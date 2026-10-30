# Lotes para o Anki

Os lotes **2026-10-28-historico** (69), **2026-10-28-expansao** (17 novos) e
**2026-10-28-rating1300** (5 novos e 2 atualizados) foram importados por
AnkiConnect e sincronizados com AnkiWeb: **91 cards únicos**.
[distribuicao.md](distribuicao.md) mostra quantos estão associados a cada questão,
incluindo conceitos compartilhados. A versão `.md` de cada lote permite ler seus cards; `.json`
contém os campos HTML enviados, e `.tsv` é a alternativa para importação manual.

Formato TSV UTF-8 com campos `ID`, `Frente`, `Verso`, `Fonte`
e `Tags`, destinado ao tipo de nota próprio `CP Goodnotes`. O campo `ID` é o
primeiro campo para atualização sem duplicação e não deve aparecer na frente.
Os templates desse tipo de nota foram configurados e testados.

`-create-receipt.json` guarda o recibo da criação atômica; `-manifest.json`
registra IDs nativos, hashes e status de sincronização. A reexecução foi
conferida: zero novas notas, zero alterações, 69 existentes. Os originais
editáveis estão em `../cards/`.

O último lote contém as versões atuais de 000051/000052; os exports anteriores
guardam a versão enviada na época. O último manifesto de cada card é indicado
por `anki.last_batch_id` no JSON autoral. Notas revisadas mantêm seus IDs nativos.

Cada lote deverá acompanhar um manifesto com IDs, revisão do cursor, hashes dos
arquivos autorais e status de importação. Gerar um lote não confirma importação.
Pacotes `.apkg` são derivados e ignorados pelo Git; os textos/manifestos devem ser
versionáveis. Código HTML deve escapar operadores para não ocultar C++ no card.
