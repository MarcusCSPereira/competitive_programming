# Cards autorais

Há **93 cards validados**, `cp-note-000001` a `cp-note-000093`, publicados e
sincronizados no baralho Programação competitiva. O primeiro lote tem 69, e a
revisão de cobertura acrescentou 17. A revisão das questões recentes acrescentou
5 e melhorou 2 existentes, sem trocar seus IDs. Consulte a
[distribuição por problema](../exportacoes/distribuicao.md).

O processamento incremental de 29/10 acrescentou dois cards de Roof Construction.
O lote é `../exportacoes/2026-10-29-diaria.md`, com casos em
`../tests/diaria-2026-10-29-cases.json` e relatório
`../estado/validacao-diaria-2026-10-29.json`.

Cada JSON é a fonte editável: pergunta, teoria, código C++17, complexidade,
critérios de acerto, assuntos, páginas e versão das fontes. IDs são imutáveis.
O campo `anki` registra os IDs nativos; revisões e agenda ficam no Anki/AnkiWeb.

A versão legível de todo o lote está em
[exportacoes/2026-10-28-historico.md](../exportacoes/2026-10-28-historico.md).
Os testes de comportamento ficam em `../tests/historico-cases.json` e o resultado
com hashes em `../estado/validacao-historico.json`. Os 17 complementos têm casos
em `../tests/expansao-cases.json` e relatório `../estado/validacao-expansao.json`.
O lote recente está em `../exportacoes/2026-10-28-rating1300.md`, com testes em
`../tests/rating1300-cases.json` e relatório `../estado/validacao-rating1300.json`.
Para uma nota revisada, o JSON deste diretório e seu último lote são a versão atual.

Não colocar aqui o banco do Anki nem o histórico de respostas. Os arquivos
autorais e seu manifesto devem ser versionados junto com o cursor. Depois de
alterar código, valide novamente antes de publicar. Atualize a mesma nota e
seus cards, preservando o histórico de revisão.
