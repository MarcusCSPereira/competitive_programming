#!/usr/bin/env python3
"""Exporta e publica cards validados por ID estável; sem controlar a tela.

Sem --apply, apenas mostra o plano. Não exclui notas, cards ou histórico.
"""
import argparse
import csv
import fcntl
import hashlib
import html
import json
import os
from pathlib import Path
import re
import tempfile

from anki_client import AnkiClient, AnkiError

ROOT = Path(__file__).resolve().parents[1]
BATCH = '2026-10-28-historico'


def atomic(path, value):
    fd, name = tempfile.mkstemp(dir=path.parent, suffix='.tmp')
    with os.fdopen(fd, 'w') as stream:
        json.dump(value, stream, ensure_ascii=False, indent=2)
        stream.write('\n')
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(name, path)


def prose(value):
    blocks = []
    for paragraph in value.split('\n\n'):
        if not paragraph.strip():
            continue
        if all(line.startswith('- ') for line in paragraph.splitlines()):
            blocks.append('<ul>' + ''.join('<li>' + inline(x[2:]) + '</li>' for x in paragraph.splitlines()) + '</ul>')
        else:
            blocks.append('<p>' + inline(paragraph).replace('\n', '<br>') + '</p>')
    return ''.join(blocks)


def inline(value):
    value = html.escape(value)
    value = re.sub(r'`([^`]+)`', r'<code>\1</code>', value)
    return re.sub(r'\*\*([^*]+)\*\*', r'<strong>\1</strong>', value)


def source_label(source):
    label = source['title'] + ' · ' + source['notebook_id']
    if source.get('pages_1based'):
        return label + ' · páginas ' + ', '.join(map(str, source['pages_1based']))
    if source.get('local_code_path'):
        return label + ' · arquivo ' + source['local_code_path']
    return label + ' · sem página vinculada'


def fields(card):
    back = card['back']
    answer = prose(back['answer'])
    answer += '<pre><code class="language-cpp">' + html.escape(back['cpp17']) + '</code></pre>'
    answer += '<p><strong>Complexidade:</strong> ' + inline(back['complexity']) + '</p>'
    answer += '<details><summary>Critério de acerto</summary><ul>'
    answer += ''.join('<li>' + inline(x) + '</li>' for x in back['success_criteria']) + '</ul></details>'
    sources = []
    for source in card['sources']:
        text = source_label(source)
        url = source.get('official_statement_url')
        sources.append('<li>' + (f'<a href="{html.escape(url, quote=True)}">{inline(text)}</a>' if url else inline(text)) + '</li>')
    return {'ID': card['id'], 'Frente': prose(card['front']), 'Verso': answer, 'Fonte': '<ul>' + ''.join(sources) + '</ul>'}


def readable(cards):
    lines = ['# Cards de revisão — lote histórico', '',
             f'{len(cards)} cards autorais. Teoria, aplicação em C++17 e critérios de acerto.', '',
             'Este arquivo deriva dos JSON em `../cards/`. O manifesto registra o envio ao Anki.', '',
             '## Índice', '']
    for card in cards:
        lines.append(f'- [{card["id"]} — {card["content_key"]}](#{card["id"]})')
    for card in cards:
        back = card['back']
        lines += ['', f'## {card["id"]}', '', '**Pergunta**', '', card['front'], '',
                  '**Resposta**', '', back['answer'], '', '```cpp', back['cpp17'], '```', '',
                  '**Complexidade:** ' + back['complexity'], '', '**Critérios de acerto**', '']
        lines += ['- ' + x for x in back['success_criteria']]
        lines += ['', '**Fontes**', '']
        for source in card['sources']:
            label = source_label(source)
            url = source.get('official_statement_url')
            lines.append('- ' + (f'[{label}]({url})' if url else label))
    return '\n'.join(lines) + '\n'


def get_notes(api, session):
    ids = []
    params = {'query': 'note:"CP Goodnotes"', 'limit': 1000, 'session': session}
    while True:
        page = api.call('notes.search', params)
        ids += page['ids']
        if not page['nextCursor']:
            break
        params['cursor'] = page['nextCursor']
    result = {}
    for start in range(0, len(ids), 250):
        for item in api.call('notes.getMany', {'ids': ids[start:start+250], 'session': session})['items']:
            if 'error' in item:
                raise AnkiError(str(item['error']))
            note = item['result']
            ident = note['fields']['ID']
            if ident in result:
                raise AnkiError('ID duplicado no Anki: ' + ident)
            result[ident] = note
    return result


def run(apply, batch=BATCH):
    if not re.fullmatch(r'[a-z0-9][a-z0-9_-]*', batch):
        raise AnkiError('Identificador de lote inválido')
    spec_path = ROOT / 'lotes' / (batch + '.json')
    if spec_path.exists():
        spec = json.loads(spec_path.read_text())
        if spec['id'] != batch:
            raise AnkiError('Identidade da especificação diverge do lote')
        report = json.loads((ROOT / spec['validation_report']).read_text())
        selected = spec['card_ids']
    elif batch == BATCH:
        report = json.loads((ROOT / 'estado/validacao-historico.json').read_text())
        selected = sorted(report['tested_cards'])
    else:
        raise AnkiError('Preparar a especificação em lotes/ antes de publicar')
    assert report['status'] == 'passed'
    if not selected or len(set(selected)) != len(selected):
        raise AnkiError('Seleção de cards vazia ou duplicada')
    if any(not re.fullmatch(r'cp-note-\d{6}', key) for key in selected):
        raise AnkiError('ID de card inválido')
    cards = [json.loads((ROOT / 'cards' / (key + '.json')).read_text()) for key in selected]
    for card in cards:
        assert card['status'] == 'validated', card['id']
        assert card['validation']['code_tested'] is True
        digest = hashlib.sha256(card['back']['cpp17'].encode()).hexdigest()
        assert report['tested_cards'][card['id']]['code_sha256'] == digest
        assert card['sources'] and all(s['notebook_id'] != 'problemas' or min(s['pages_1based']) >= 45 for s in card['sources'])
    exports = ROOT / 'exportacoes'
    exports.mkdir(exist_ok=True)
    payload = [{'id': c['id'], 'fields': fields(c), 'tags': sorted(set(c['tags']))} for c in cards]
    atomic(exports / (batch + '.json'), payload)
    (exports / (batch + '.md')).write_text(readable(cards), encoding='utf-8')
    with (exports / (batch + '.tsv')).open('w') as stream:
        stream.write('#separator:Tab\n#html:true\n#notetype:CP Goodnotes\n#deck:Programação competitiva\n#tags column:5\n')
        writer = csv.writer(stream, delimiter='\t')
        for row in payload:
            writer.writerow([row['fields'][f] for f in ['ID', 'Frente', 'Verso', 'Fonte']] + [' '.join(row['tags'])])
    api = AnkiClient()
    active = api.call('profiles.getActive')
    if not active or active['name'] != 'User 1':
        raise AnkiError('Perfil ativo diferente do esperado; não publicar')
    if apply:
        api.wait(api.call('collection.sync'))
    session = api.call('collection.get')['session']
    deck = api.call('decks.get', {'deck': {'name': 'Programação competitiva'}, 'session': session})
    if deck['id'] != '1793225719777':
        raise AnkiError('Identidade do baralho mudou')
    model = api.call('noteTypes.get', {'noteType': {'name': 'CP Goodnotes'}, 'session': session})
    if [x['name'] for x in model['fields']] != ['ID', 'Frente', 'Verso', 'Fonte'] or len(model['templates']) != 1:
        raise AnkiError('Estrutura do tipo de nota mudou')
    existing = get_notes(api, session)
    creates, updates, unchanged = [], [], []
    for row in payload:
        old = existing.get(row['id'])
        if old:
            if old['fields'] == row['fields'] and set(row['tags']).issubset(old['tags']):
                unchanged.append(row['id'])
            else:
                updates.append((old, row))
        else:
            creates.append({'noteType': {'id': model['id']}, 'deck': {'id': deck['id']},
                            'fields': row['fields'], 'tags': row['tags']})
    plan = {'batch_id': batch, 'create': len(creates), 'update': len(updates), 'unchanged': len(unchanged), 'total': len(payload)}
    print(json.dumps(plan, ensure_ascii=False))
    if not apply:
        return
    validation = api.call('notes.validateMany', {'notes': creates, 'session': session})
    for item in validation['items']:
        if 'error' in item or not item['result']['valid']:
            raise AnkiError('Validação Anki falhou: ' + str(item))
    if creates:
        created = api.call('notes.createMany', {'notes': creates, 'atomic': True, 'session': session})
        atomic(exports / (batch + '-create-receipt.json'), created)
        if any('error' in item for item in created['items']):
            raise AnkiError('Falha de criação; consultar recibo antes de repetir')
    for old, row in updates:
        result = api.call('notes.update', {'id': old['id'], 'session': session,
                         'patch': {'fields': row['fields'], 'tags': sorted(set(row['tags']) | set(old['tags']))}})
        if result['id'] != old['id'] or result['cardIds'] != old['cardIds']:
            raise AnkiError('Identidade da nota/card mudou durante atualização')
    readback = get_notes(api, session)
    manifest = {'batch_id': batch, 'plan': plan, 'status': 'imported_pending_sync', 'notes': {}}
    for row in payload:
        note = readback[row['id']]
        if note['fields'] != row['fields'] or len(note['cardIds']) != 1:
            raise AnkiError('Readback diverge: ' + row['id'])
        manifest['notes'][row['id']] = {'note_id': note['id'], 'card_ids': note['cardIds'],
            'fields_sha256': hashlib.sha256(json.dumps(row['fields'], sort_keys=True, ensure_ascii=False).encode()).hexdigest()}
    manifest_path = exports / (batch + '-manifest.json')
    atomic(manifest_path, manifest)
    sync = api.wait(api.call('collection.sync', {'session': session}))
    if not sync.get('collectionComplete') or not sync.get('mediaComplete'):
        raise AnkiError('Sincronização incompleta: ' + str(sync))
    manifest.update(status='synced', sync=sync)
    atomic(manifest_path, manifest)
    for card in cards:
        card['anki'].update(manifest['notes'][card['id']], import_confirmed=True, last_batch_id=batch)
        atomic(ROOT / 'cards' / (card['id'] + '.json'), card)
    print(json.dumps({'status': 'synced', 'verified_notes': len(manifest['notes']), 'sync': sync}, ensure_ascii=False))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--apply', action='store_true')
    parser.add_argument('--batch', default=BATCH, help='Especificação em lotes/; padrão: primeiro lote histórico')
    args = parser.parse_args()
    with (ROOT / 'estado/publish.lock').open('a') as lock:
        fcntl.flock(lock, fcntl.LOCK_EX)
        run(args.apply, args.batch)
