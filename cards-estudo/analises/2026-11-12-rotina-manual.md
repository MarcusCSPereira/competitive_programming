# Execução manual de 12/11/2026

Pedido de execução única. O lote acrescentou 17 cards, atualizou 1 e foi
sincronizado com o AnkiWeb. O baralho tem 113 cards com 10 novos por dia
e revisões antes dos novos.

## Fontes comparadas

O Drive foi consultado antes e depois da leitura local. O lote começou
dentro da validade da verificação `109cf8d8-ff3a-41ea-a881-986d807ac0ab`.
As cópias foram fixadas por hash para a análise.

| Caderno | Páginas no PDF | Páginas alteradas ou novas |
| --- | ---: | --- |
| Problemas | 110 | 101 alterada e 102–110 novas |
| Big Tech Problems | 20 | 15 alterada e 16–20 novas |
| Anotações | 40 | Mesmo hash |

A comparação PPM a 72 dpi começa na página 45 de Problemas e na página 1
de Big Tech Problems. As 16 páginas novas ou alteradas foram lidas em
cores a 120 dpi. Não houve deslocamento das páginas anteriores no trecho
comparado. A listagem também encontrou IA - Studies fora das fontes
selecionadas para esta rotina. Ver [comparação](../estado/comparacao-2026-11-12.json).

## Conteúdo

| Origem | Questão | Cards |
| --- | --- | --- |
| Problemas 101 | Triangles on a Rectangle | Proveniência de 000094 atualizada no repo após confirmar código, roxo e verde |
| Problemas 102 | Divan and a New Project | 000096 atualizado no mesmo ID com o vínculo ao manuscrito |
| Problemas 103–104 | MEXor Mixup | 000097–000098 sobre prefixo XOR e ajuste sem violar o MEX |
| Problemas 105–106 | Double-ended Strings | 000099–000100 sobre redução a substring e DP de coincidência contígua |
| Problemas 106–107 | Add and Divide | 000101 sobre ordem das operações e limite de busca |
| Problemas 107–109 | Different Divisors | 000102–000103 sobre contagem por expoentes e candidatos ótimos |
| Problemas 109–110 | Numbers Box | 000104 sobre paridade de sinais e alcance por caminhos |
| Big Tech 15–20 | Valid Palindrome, Valid Parentheses, Min Stack, 3Sum, Valid Palindrome II, Majority Element, Design HashSet e Sort an Array | 000105–000112 |
| Repositório | Binary Search 704 | 000113 sobre intervalo fechado em array ordenado, sem página vinculada |

Em Big Tech 15, a seção de Longest Consecutive Sequence mantém o assunto
já coberto por 000095 e a segunda metade começa Valid Palindrome. O card
antigo continua associado à seção original. Divan foi remapeado de fonte
local para a página 102, preservando questão, nota e agendamento.

A revisão distinguiu a DP de substring da DP de subsequência. Em
Different Divisors, a prova considera também candidatos com mais de quatro
divisores. A complexidade do teste de primalidade foi registrada em termos
da raiz e do número de candidatos. Em Majority Element, o critério é
estritamente mais de metade. Em Design HashSet, as listas nos buckets
implementam encadeamento separado. Os cards de soluções anotadas em Python
trazem uma adaptação em C++17.

## Validação e publicação

Os 18 trechos do lote compilaram em C++17 estrito e passaram com ASan e
UBSan. Os testes incluem referências independentes por enumeração, BFS,
ordenação e estruturas de referência. Também cobrem valores extremos da
Min Stack, colisões no HashSet, estabilidade da intercalação e duplicatas
de 3Sum.

A sincronização de coleção e mídia terminou. Os 96 IDs e estados de
revisão anteriores conferem com a leitura feita antes do envio. Os 18 cards
do lote foram lidos e renderizados via AnkiConnect. O cursor avançou para
111 em Problemas e 21 em Big Tech Problems. Os próximos IDs são 114 para
card e 79 para questão.

[Cards do lote](../exportacoes/2026-11-12-manual.md) ·
[Validação dos trechos](../estado/validacao-2026-11-12-manual.json) ·
[Verificação no Anki](../estado/verificacao-2026-11-12-manual.json)
