# Revisão de cobertura — 28/10/2026

Conferência final: 2026-10-28T21:00:10-03:00.

Após o pedido para aprofundar os assuntos que realmente precisavam, foram acrescentados **17 cards** em **16 questões/seções**. O total é **86**: 65 de Problemas e 21 de Big Tech Problems. Os 69 anteriores preservaram campos, tags, IDs nativos, cards e dados de agendamento na conferência por API.

## Seleção e origem

A revisão confrontou os cards existentes com a extração colorida integral do lote anterior e releu os alvos do aprofundamento no mesmo snapshot. Sem quota por problema: a quantidade foi definida por objetivos de aprendizagem distintos. Os demais tópicos selecionados permaneceram cobertos pelos cards anteriores. Isso não significa esgotar todos os assuntos possíveis de cada questão.

Foi repetido o gate obrigatório Drive → Mac: prepare, nova consulta autenticada, confirm. Run ID `b9f78700-9140-42d3-9354-cee80c562b26`. Os três PDFs mantiveram seus hashes; não houve nova versão a remapear. A execução foi iniciada dentro da validade do gate. O corte de Problemas permanece 45, inclusive; páginas 1–44 não foram processadas.

Os padrões que ampliam a aplicação do exemplo original estão marcados como `didactic_extension` nos JSON e explicados como complementos no verso. Exemplos: duração acima de capacidade por sweep line, vetor de diferenças, decoder para dados malformados e a variante de busca binária. Não se atribui uma hipótese nova ao enunciado ou ao manuscrito.

## Novos objetivos

| Card | Fonte contextual | Aprendizado acrescentado |
| --- | --- | --- |
| cp-note-000070 | Microwaves | Lista de adjacência, bidirecionalidade e ausência da aresta alternativa. |
| cp-note-000071 | Microwaves | Descoberta versus finalização e retorno antecipado no Dijkstra. |
| cp-note-000072 | Microwaves, Vasilije in Cacak | Limites numéricos, promoção de tipos, INF e relaxamento sem overflow. |
| cp-note-000073 | Porquinho da Índia | Respostas memoizadas, propagação de intervalos e rejeição de ciclos. |
| cp-note-000074 | Porquinho da Índia | IDs grandes traduzidos para índices compactos; ausência sem inserção acidental. |
| cp-note-000075 | Porquinho da Índia | Duração acima de uma capacidade e distância real entre coordenadas. |
| cp-note-000076 | Porquinho da Índia, Odd Queries | Vetor de diferenças para atualizações offline, distinguindo-o de prefix sums. |
| cp-note-000077 | Top K Frequent Elements | Top K com min-heap limitado e comparação com buckets. |
| cp-note-000078 | Encode and Decode Strings | Decoder validado, limites, overflow e preservação da saída em caso de erro. |
| cp-note-000079 | Minimum LCM, Exciting Bets | Algoritmo de Euclides e MMC com verificação de overflow. |
| cp-note-000080 | Monsters | Comparador estrito e desempate consistente no sort. |
| cp-note-000081 | Olya and Game with Arrays | Dois menores em uma passada, incluindo valores repetidos. |
| cp-note-000082 | Traffic Light, Exciting Bets | Resto negativo e índices/distâncias circulares sem somas desnecessárias. |
| cp-note-000083 | Luntik and Subsequences | Largura do shift e overflow da multiplicação após calcular uma potência. |
| cp-note-000084 | LRU Cache | Propriedade dos nós, RAII, destruição e ligações em listas. |
| cp-note-000085 | Inicialização de contêineres compostos, Group Anagrams | Cópias versus referências em parâmetros e contêineres aninhados. |
| cp-note-000086 | Security Delivery Logs | Prova de monotonicidade antes de usar busca binária sobre resposta. |

Microwaves passou de **2 para 5** e Porquinho da Índia de **2 para 6**. As perguntas básicas anteriores já tratavam Dijkstra com estados, fila obsoleta, detecção de ciclos e pico de presença por sweep line. Os complementos acrescentam montagem, limites, correção do algoritmo, resolução efetiva das dependências e usos distintos da varredura; não repetem apenas o mesmo cálculo com outra redação.

## Verificações

- Os 17 trechos foram compilados em C++17 estrito e executados com AddressSanitizer e UndefinedBehaviorSanitizer. Casos e hashes estão em `../tests/expansao-cases.json` e `../estado/validacao-expansao.json`.
- Caminhos mínimos: comparação com Bellman-Ford no grafo de estados materializado em 250 grafos pequenos gerados de forma determinística, incluindo pesos zero e recursos opcionais.
- Dependências: comparação com um oráculo sem memoização em 250 grafos funcionais pequenos e teste de cadeia de 100.000 nós para evitar depender da pilha recursiva.
- Sweep line: comparação com contagem por instante em domínios pequenos, empates, intervalos vazios e horários esparsos grandes.
- Demais testes incluem decoder truncado e bytes nulos, MDC/MMC por enumeração, dois menores versus ordenação, comparador estrito, limites de shift e inteiros, ligações de lista após remoções e busca binária versus enumeração.
- Publicação por AnkiConnect: 17 notas novas, relidas campo a campo, um card por nota; sincronização final confirmou coleção e mídias completas. Renderização por API conferida em exemplos de dependências, sweep line e memória de listas.
- Comparação dos 69 anteriores com a captura anterior à publicação: IDs, campos, tags e agendamento iguais. Não houve recriação nem reset de revisão. O resultado está em `../estado/verificacao-expansao.json`.
- Reexecução de planejamento: expansão cria 0, atualiza 0 e mantém 17; o lote inicial cria 0, atualiza 0 e mantém 69. Os dois recibos e manifestos são separados.

## Retomada

Problemas segue na página **99**, com Roof Construction pendente por ter somente o título. Big Tech Problems segue em **16**, após a versão atual. Os cards da expansão foram associados às mesmas identidades das questões anteriores; o próximo ID é **cp-note-000087**. Antes de novo processamento, repetir o gate de sincronização e comparar páginas antigas alteradas.

Foi corrigida a nota antiga do catálogo de Forked que ainda mencionava pendência nas páginas 45–48: o início já estava reconciliado pelo primeiro lote. A identidade da questão e seus cards não mudaram.

Arquivos foram salvos no checkout do repositório e os cards sincronizados no AnkiWeb. Nenhum commit/push ou agendamento foi criado nesta execução.

## Referências técnicas consultadas

- [Relação de ordenação dos algoritmos C++](https://eel.is/c++draft/alg.sorting#general).
- [Largura e validade dos operadores de shift](https://eel.is/c++draft/expr.shift).
- [Operações de listas e validade dos iteradores](https://eel.is/c++draft/list.ops).
- [Contêineres associativos sem ordem e complexidade](https://eel.is/c++draft/unord.req).

A implementação entregue foi compilada como C++17. As páginas acima são o texto de trabalho atual do padrão; a revisão usou as regras estáveis aplicáveis aos recursos escolhidos, sem introduzir recursos de versões posteriores.

[Cards novos](../exportacoes/2026-10-28-expansao.md) · [Distribuição completa](../exportacoes/distribuicao.md)
