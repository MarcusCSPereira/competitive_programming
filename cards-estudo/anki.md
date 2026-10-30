# Anki e revisão gratuita no iPhone

O fluxo escolhido é Anki gratuito no Mac → AnkiWeb → Safari do iPhone.
AnkiMobile pago não é necessário para este fluxo. A revisão no AnkiWeb requer
internet. O conteúdo e as respostas ficam no ecossistema Anki; o repositório
guarda os cards autorais, os lotes e os checkpoints da geração.

Em 28/10/2026 o usuário informou login no AnkiWeb e o agente confirmou pela
interface a sessão autenticada em `https://ankiweb.net/decks`. Naquele momento
havia somente o baralho `Default`, com zero cards novos e zero revisões.

O agente instalou o Anki 26.09.3 para Apple Silicon em `/Applications/Anki.app`
pelo DMG ligado no site oficial, cuja assinatura identifica Anki Software LLC.
A primeira abertura foi concluída. Após o usuário entrar no aplicativo, o agente
criou o baralho **Programação competitiva** e confirmou sua sincronização em ambas
as direções entre Mac e AnkiWeb. A coleção remota foi conferida antes do envio
inicial; naquele momento havia apenas `Default`, sem novos cards ou revisões.
O nome correto do baralho foi confirmado no site e recebido de volta no Mac.
Esse foi o estado inicial. Após a aprovação do formato e a autorização do lote,
o baralho recebeu **69 notas e 69 cards**, com sincronização confirmada por API.
O manifesto em `exportacoes/2026-10-28-historico-manifest.json` guarda os IDs
nativos e a confirmação da coleção e das mídias. O comprovante da configuração
inicial fica em `.cache/anki/2026-10-28-baralho-sincronizado.png`.

## Integração por código: AnkiConnect

Instalado em 28/10/2026 pelo catálogo do Anki, código **2055492159**. O Anki foi
reiniciado e a API v1 respondeu em `http://127.0.0.1:8765/api/v1`. A escuta foi
confirmada somente em `127.0.0.1:8765`. Perfil ativo conferido: **User 1**; versão
do Anki: **26.09.3**. Não é necessário controlar a tela para enviar lotes.

O modelo **CP Goodnotes** foi criado por código a partir de
`modelos/anki-note-type.json`: campos `ID`, `Frente`, `Verso`, `Fonte`; um único
template de revisão. `ID` é o primeiro campo e fica oculto na revisão. Tags são
metadados da nota no Anki, não um quinto campo de conteúdo.

Validação real: `notes.validate` retornou `valid: true`, sem gravar uma nota;
`notes.search` confirmou zero notas desse modelo. A sincronização por API
retornou `collectionComplete: true` e `mediaComplete: true`. O teste comprova
conexão, modelo, validação de formato e sincronização. Posteriormente o primeiro
lote real foi criado, relido campo a campo e sincronizado. Uma segunda execução
de planejamento retornou criar **0**, atualizar **0**, manter **69**. Criação e
reexecução sem duplicatas foram verificadas; uma alteração real de conteúdo na
mesma nota ainda não foi necessária. Dados locais do teste inicial ficam em
`.cache/anki/ankiconnect-setup.json`, ignorado pelo Git.

Cliente Python padrão salvo em `scripts/anki_client.py`. Na raiz do repo C++:

```sh
python3 cards-estudo/scripts/anki_client.py status
python3 cards-estudo/scripts/anki_client.py call decks.list
python3 cards-estudo/scripts/anki_client.py call notes.validate --params-file parametros.json
python3 cards-estudo/scripts/anki_client.py sync
```

`call` aceita um método da API v1 e um arquivo JSON contendo seus parâmetros;
não monta comandos a partir de conteúdo dos cadernos. A chave opcional, se vier
a ser configurada no complemento, é lida de `ANKICONNECT_API_KEY` e nunca deve
ser gravada no Git. O cliente não guarda a senha do AnkiWeb e não troca o perfil.
O Anki precisa permanecer aberto, podendo ficar em segundo plano.

### Protocolo para enviar lotes futuros

1. Confirmar `profiles.getActive`, `collection.get` e `decks.list`; exigir perfil,
   baralho e modelo esperados. Reusar a sessão de `collection.get` nos métodos
   que a aceitam, para detectar mudança de perfil durante o lote.
2. Sincronizar antes de escrever para receber revisões feitas no AnkiWeb.
3. Ler somente cards autorais validados. Confirmar ID imutável, fonte e campos
   preenchidos. Não confundir validação técnica do conteúdo com `notes.validate`,
   que confere apenas formato e regras do Anki.
4. Buscar a nota pelo campo `ID` dentro do tipo `CP Goodnotes`. Zero resultados:
   `notes.validate` e `notes.create` (ou `notes.createMany` com `atomic: true`).
   Um resultado: conferir identidade e atualizar campos com `notes.update`.
   Mais de um: bloquear e reconciliar duplicatas, sem escolher arbitrariamente.
5. Atualizar conteúdo na mesma nota, preservando seus IDs e cards. Não apagar e
   recriar notas para corrigir texto, nem alterar templates para atualizar lote.
   Conferir notas/cards retornados pela API e registrar mapeamento ID autoral →
   note ID/card IDs no manifesto; registrar importação separadamente da geração.
6. Sincronizar e aguardar a operação terminar. O cliente acompanha `operations.get`;
   timeout não significa cancelamento. Guardar o identificador e consultar antes
   de repetir. `waitingForUser`/conflito requer inspeção; nunca sobrescrever uma
   coleção automaticamente para concluir um lote.

Exportação TSV continua alternativa recuperável. A rota preferencial é a API;
nenhum agendamento foi criado.

O publicador do lote atual executa as verificações acima, exporta JSON/TSV e
confere o hash de cada trecho contra a validação C++17:

```sh
# Gera os arquivos derivados e mostra o plano, sem escrever no Anki
python3 cards-estudo/scripts/publish_cards.py
# Publica somente conteúdo validado e sincroniza antes/depois
python3 cards-estudo/scripts/publish_cards.py --apply
```

O padrão continua sendo `2026-10-28-historico`, limitado aos 69 IDs do relatório
original. Novos lotes usam uma especificação em `lotes/` com `id`, `card_ids` e
`validation_report`. A expansão já publicada usa:

```sh
python3 cards-estudo/scripts/validate_cards.py --cases tests/expansao-cases.json --report estado/validacao-expansao.json --cache-key expansao
python3 cards-estudo/scripts/publish_cards.py --batch 2026-10-28-expansao
python3 cards-estudo/scripts/publish_cards.py --batch 2026-10-28-expansao --apply
```

Após essa expansão, há **86 notas e 86 cards**: 65 associados ao caderno Problemas
e 21 a Big Tech Problems. A conferência preservou campos, IDs e agendamento dos
69 anteriores. Cada lote mantém export, recibo e manifesto separados. Não misturar
novos arquivos sem preparar sua seleção e validação.

A revisão seguinte, `2026-10-28-rating1300`, criou 5 notas e atualizou 2 na mesma
identidade. Agora são **91 notas/cards**: 66 de Problemas, 21 de Big Tech Problems
e 4 de Make it Alternating com fonte no repositório e no enunciado oficial.
Foi verificado que os 86 IDs anteriores e seus agendamentos ficaram iguais;
84 conteúdos anteriores ficaram intactos, e somente 000051/000052 receberam as
melhorias previstas. A reexecução desse lote retorna manter 7, criar/atualizar 0.

## Configuração e operação

1. Usar a mesma conta AnkiWeb no Anki do Mac e no Safari do iPhone. Login web
   não autentica automaticamente o aplicativo do Mac. Não guardar senhas no
   repositório nem pedir que sejam enviadas pelo chat.
2. Antes do primeiro lote, configurar o tipo de nota `CP Goodnotes`, com `ID`
   como primeiro campo oculto na revisão, e o baralho `Programação competitiva`.
   O baralho e o tipo de nota já foram configurados e validados por API.
3. Enviar os lotes pela API conforme o protocolo acima e os IDs do README.
   Confirmar a importação e sincronizar com AnkiWeb; verificar o resultado.
4. No iPhone, abrir `https://ankiweb.net/decks` no Safari e revisar o baralho.
   O Mac não precisa ficar ligado durante revisões de cards já sincronizados.
5. Antes de novas importações no Mac, sincronizar para receber o histórico das
   respostas feitas no site. Depois da importação, sincronizar novamente.

Para começar, priorize as revisões vencidas e experimente 3–5 novos por dia.
Tente explicar a ideia e reconstruir o código antes de revelar a resposta.
Use Novamente quando faltar a ideia ou um passo essencial; Bom quando conseguir
reconstruir o padrão. Essa é uma sugestão de rotina: limites do baralho e algoritmo
de agendamento não foram alterados. A coleção estava com SM-2, não FSRS.

O login confirmado não significa tipo de nota configurado, lote importado ou
sincronização do aplicativo concluída. Registrar esses marcos separadamente em
`estado/cursor.json`, preservando os cursores de geração.

Fontes oficiais: [Anki para Mac](https://apps.ankiweb.net/),
[sincronização e estudo online](https://docs.ankiweb.net/manual/syncing),
[catálogo AnkiConnect](https://ankiweb.net/shared/info/2055492159),
[documentação do projeto AnkiConnect](https://git.sr.ht/~foosoft/anki-connect).

## Liberação do baralho completo

Em 2026-10-28T21:22:45-03:00, após o usuário informar que só tinha acesso a 20, o limite de novos
foi alterado de **20 para 91 por dia**, em um preset próprio do baralho
Programação competitiva. A contagem nativa passou de novos 20/total 91 para
**novos 91/total 91**. Os 91 agendamentos existentes foram comparados e
preservados, e a sincronização confirmou coleção e mídias completas.
Comprovante: `estado/anki-limite-diario.json`.

## Limite diário atual

A pedido do usuário, em 2026-10-28T21:23:53-03:00, o limite foi ajustado para **5 novos por dia**,
com revisões antes dos novos (`afterReviews`). Todos os **91 cards** permanecem
na coleção e no AnkiWeb; os 91 IDs e agendamentos foram comparados e preservados.
O limite de revisões permanece em 200 por dia. A sincronização de coleção e
mídias foi concluída. O número azul pode mostrar 5 ou menos disponíveis hoje;
continuam existindo 91 cards no total. O ajuste anterior para 91 novos/dia foi
substituído por esta configuração.

## Ajuste solicitado: 10 novos por dia

Em 2026-10-28T21:24:46-03:00, o usuário solicitou **10 novos por dia**, substituindo o limite
anterior de 5. Revisões continuam antes dos novos. Todos os 91 cards e seus
agendamentos foram preservados; a sincronização foi confirmada.

## Abertura automática em segundo plano

A pedido do usuário, o Anki foi configurado para abrir oculto no início da sessão
do Mac, a partir do próximo login. Isso permite à rotina das 12:30 usar a API
sem trazer a janela à frente. A configuração está validada; o primeiro login
ainda está pendente de observação. Todos os cards e o limite de 10/dia foram
preservados. Veja `estado/anki-inicio-sessao.json`.
