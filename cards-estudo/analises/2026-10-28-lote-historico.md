# Primeiro lote histórico — 28/10/2026

Conferência final: 2026-10-28T20:36:49-03:00.

Foram gerados, validados, importados e sincronizados **69 cards**, selecionados de **59 questões e seções**. Cada verso contém teoria e aplicação concreta em C++17. Foram mantidos os IDs dos dois pilotos aprovados; as perguntas priorizam padrões transferíveis e podem compartilhar fontes.

## Cobertura e leitura

| Caderno | Faixa visualmente lida | Unidades com assuntos selecionados | Cards | Retomada |
| --- | --- | --- | --- | --- |
| Problemas | 45–99, inclusive | 50 | 53 | Página 99: Roof Construction incompleto |
| Big Tech Problems | 1–15 | 9 | 16 | Página 16, após a versão atual |

Problemas 1–44 não foi analisado para geração. Em Big Tech Problems, 1 é capa e 15 está vazia. Anotações continua complementar, sem geração em massa. As continuações foram agrupadas por questão; Forked 48–50 foi reconciliado sem mudar seu ID.

## Aquisição e rastreabilidade

O lote foi iniciado após prepare → nova consulta autenticada de metadados → confirm. A execução de sincronização é `e7a260ec-99cb-4f89-9052-d1ac727383a7`. A leitura utilizou snapshots imutáveis dos PDFs da pasta do Drive no Mac. O prazo de validade do gate controla o início da leitura, não exige baixar outra versão no meio do lote. Toda próxima execução precisa de nova conferência.

- Problemas SHA-256: `2446f6a988a66805ea578961e258c31bdf8616ccd584ffa922664f71ef896250`.
- Big Tech Problems SHA-256: `5ad1d1cddf6ebb85f357ea00eb33031820f37ff80b432b1f33955b43024302b9`.
- Metadados remotos recentes coincidiram com tamanho/data e a leitura local ficou estável. O conector não expôs checksum remoto; não afirmar comparação criptográfica com o servidor.

Foram combinados texto extraído e imagens em cores de todas as páginas autorizadas. Títulos, lógica, observações roxas e complexidade foram interpretados no contexto de cada questão. As impressões das páginas e a identidade dos arquivos estão no cursor. PDFs e imagens ficam apenas no cache ignorado.

## Validação e correções

Todos os 69 trechos foram compilados com clang++ em C++17 estrito (`-pedantic-errors -Wall -Wextra -Werror`) e executados com AddressSanitizer e UndefinedBehaviorSanitizer. Os casos exercitam comportamento e bordas, incluindo lista vazia, carry, remoção LRU, intervalos e fórmulas. Os hashes de código e dos testes estão em `../estado/validacao-historico.json`. Isso não equivale a submissão de cada solução na plataforma.

- Sum of Medians: a imagem manuscrita repete o código de Strange Partition. A versão do card foi reconstruída com o enunciado oficial e o código do repo; posição da mediana e exemplos foram conferidos.
- Longest Divisors Interval: corrigido o limite anotado; para n ≤ 10^18 o máximo é 42, pois o MMC de 1…43 ultrapassa esse limite. O card explica por que qualquer intervalo de comprimento L implica divisibilidade por 1…L.
- Luntik: contagem de subconjuntos por shift inteiro sob limites válidos, sem `pow` em ponto flutuante.
- Comparações de caracteres: intervalos com `&&`, alternativas com `||`, e `unsigned char` para funções de cctype. Leitura de strings continua O(n).
- Hash map: acesso O(1) médio, sem prometer pior caso constante.
- Security Delivery Logs: a regra de descarte não ficou comprovada por um enunciado público. O card explicita a hipótese didática de poder deixar unidades sem alocar; não apresenta essa hipótese como regra confirmada da entrevista. Corrigida a complexidade para O(M·N·log N). O raciocínio foi confrontado com enumeração exaustiva em 78 instâncias pequenas sob essa hipótese.

## Publicação e reexecução

O perfil User 1, o baralho Programação competitiva e o modelo CP Goodnotes foram conferidos antes da publicação. Houve sincronização antes da escrita. A criação de 69 notas foi atômica; todas foram relidas campo a campo, com um card por nota. A sincronização final retornou `collectionComplete: true` e `mediaComplete: true`.

A execução seguinte de planejamento retornou **criar 0, atualizar 0, manter 69**. Não foram apagadas/recriadas notas. IDs nativos e hashes estão no manifesto; a atualização real de um texto existente ainda não foi necessária nesta execução. Foram renderizados por API os cards de casa dos pombos, construção de lista e o exemplo condicional de entregas.

O conteúdo está disponível para revisão no AnkiWeb. A coleção estava com SM-2; não foi ativado FSRS nem alterado o limite diário. Sugestão de início: revisões vencidas primeiro e 3–5 novos por dia, tentando reconstruir ideia e código antes de revelar.

## Pendências e persistência

- Roof Construction, página 99: só há título; aguardar lógica/anotações antes de gerar.
- Mudanças em páginas antigas devem ser comparadas antes de retomar uma versão futura.
- Nenhuma tarefa recorrente foi criada. O fluxo de leitura e publicação foi executado sob acompanhamento; execução desacompanhada ainda precisa de validação.
- Arquivos estão salvos no checkout do repositório; não foi feito commit/push nem criado backup remoto do Git nesta execução. Cards e histórico já foram sincronizados com AnkiWeb.

## Questões e cards derivados

| Unidade | Caderno e páginas | Cards |
| --- | --- | --- |
| Microwaves | problemas · 45, 46 | cp-note-000003, cp-note-000004 |
| Porquinho da Índia | problemas · 46, 47, 48 | cp-note-000005, cp-note-000006 |
| Forked! | problemas · 48, 49, 50 | cp-note-000007 |
| Chemistry | problemas · 50, 51 | cp-note-000008 |
| Vasilije in Cacak | problemas · 52 | cp-note-000009 |
| Jellyfish and Undertale | problemas · 53 | cp-note-000010 |
| Make It Zero | problemas · 54 | cp-note-000011 |
| Longest Divisors Interval | problemas · 55 | cp-note-000012 |
| Balanced Round | problemas · 55, 56 | cp-note-000013 |
| Comparison String | problemas · 56, 57 | cp-note-000014 |
| Permutation Swap | problemas · 57, 58 | cp-note-000015 |
| Odd Queries | problemas · 58, 59 | cp-note-000016 |
| Not Dividing | problemas · 59, 60 | cp-note-000017 |
| Mainak and Array | problemas · 60, 61 | cp-note-000018 |
| NIT Destroys the Universe | problemas · 61, 62 | cp-note-000019 |
| AvtoBus | problemas · 62, 63 | cp-note-000020 |
| Make It Increasing | problemas · 63, 64 | cp-note-000021 |
| Deletive Editing | problemas · 64, 65 | cp-note-000022 |
| Array Cloning Technique | problemas · 65, 66 | cp-note-000023 |
| Make AP | problemas · 66, 67, 68 | cp-note-000024 |
| Odd Grasshopper | problemas · 68, 69 | cp-note-000025 |
| AB Balance | problemas · 69, 70 | cp-note-000026 |
| Make It Divisible by 25 | problemas · 70, 71 | cp-note-000027 |
| Luntik and Subsequences | problemas · 71, 72 | cp-note-000028 |
| Mocha and Math | problemas · 72 | cp-note-000029 |
| Exciting Bets | problemas · 73, 74 | cp-note-000030 |
| Bad Boy | problemas · 74, 75 | cp-note-000031 |
| Odd Divisor | problemas · 75 | cp-note-000032 |
| Strange Partition | problemas · 75, 76 | cp-note-000020, cp-note-000033 |
| Sum of Medians | problemas · 76, 77 | cp-note-000034 |
| Three Indices | problemas · 77, 78 | cp-note-000035 |
| 01 Game | problemas · 78 | cp-note-000036 |
| Multiply by 2, Divide by 6 | problemas · 78, 79 | cp-note-000037 |
| Swap and Delete | problemas · 79, 80 | cp-note-000038 |
| Raspberries | problemas · 80, 81 | cp-note-000039 |
| Helmets in Night Light | problemas · 82, 83 | cp-note-000040 |
| Olya and Game with Arrays | problemas · 83, 84 | cp-note-000041 |
| Monsters | problemas · 84 | cp-note-000042 |
| Ski Resort | problemas · 85, 86 | cp-note-000043 |
| Array Merging | problemas · 86, 87 | cp-note-000044 |
| Distinct Split | problemas · 87, 88 | cp-note-000045 |
| Minimum LCM | problemas · 88, 89, 90, 91 | cp-note-000046, cp-note-000047 |
| Traffic Light | problemas · 91, 92 | cp-note-000048 |
| Basketball Together | problemas · 92, 93 | cp-note-000049 |
| Beautiful Array | problemas · 93, 94 | cp-note-000050 |
| Luke Is a Foodie | problemas · 94, 95 | cp-note-000051 |
| Shoe Shuffling | problemas · 95, 96 | cp-note-000052 |
| Word Capitalization | problemas · 96, 97 | cp-note-000053 |
| Black and White Stripe | problemas · 97, 98 | cp-note-000016, cp-note-000054 |
| Red Versus Blue | problemas · 98, 99 | cp-note-000001 |
| LRU Cache | big-tech-problems · 2, 3, 4, 5 | cp-note-000055, cp-note-000056, cp-note-000057, cp-note-000058 |
| Group Anagrams | big-tech-problems · 5 | cp-note-000058, cp-note-000059 |
| Top K Frequent Elements | big-tech-problems · 5, 6 | cp-note-000058, cp-note-000060 |
| Security Delivery Logs | big-tech-problems · 6, 7, 8, 9 | cp-note-000061 |
| Product of Array Except Self | big-tech-problems · 9, 10 | cp-note-000062, cp-note-000063 |
| Encode and Decode Strings | big-tech-problems · 10, 11 | cp-note-000064 |
| Valid Sudoku | big-tech-problems · 11, 12 | cp-note-000065, cp-note-000066 |
| Inicialização de contêineres compostos | big-tech-problems · 12, 13 | cp-note-000067, cp-note-000068 |
| Add Two Numbers | big-tech-problems · 14 | cp-note-000002, cp-note-000057, cp-note-000069 |
