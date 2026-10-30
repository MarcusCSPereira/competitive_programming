# Cards de estudo — Goodnotes → Anki

Preparação iniciada em **28/10/2026**, fuso `America/Bahia`. Este diretório fica
no repositório `competitive_programming` (checkout local `C++/`).

## Objetivo e fase atual

Transformar aprendizados das questões já estudadas em revisões curtas no celular,
preservando a escrita no iPad como rotina principal. Primeiro recuperar o passado;
depois incorporar questões novas e alterações em anotações antigas.

**Fase atual: 91 cards sincronizados**, após o primeiro lote de 69, uma revisão
de cobertura com 17 novos e a revisão das questões recentes com **5 novos e
2 atualizações**. Todos têm teoria e uso
concreto em C++17, com validação de código. Os dois pilotos aprovados preservam
seus IDs. Veja o [lote inicial](exportacoes/2026-10-28-historico.md), os
[17 complementos](exportacoes/2026-10-28-expansao.md), a
[distribuição por problema](exportacoes/distribuicao.md) e a
[revisão das questões recentes](analises/2026-10-28-rating1300.md).
Não há tarefa agendada.

**Rotina configurada:** 10 cards novos por dia, com revisões antes dos novos.
Todos os 91 continuam no baralho; o número diário mostrado na tela não é o
total da coleção. Configuração e verificação em `estado/anki-limite-diario.json`.

Make it Alternating (1879C, rating 1300 verificado) recebeu quatro cards a partir
da solução do repositório e do enunciado oficial. Sua página não foi localizada
no snapshot autorizado do caderno: a origem é `repositorio-cpp`, sem página
inventada. Há 66 cards de Problemas, 21 de Big Tech Problems e 4 dessa fonte local.
O [lote mais recente](exportacoes/2026-10-28-rating1300.md) inclui também um novo
card de Red Versus Blue e as versões aprimoradas de Luke Is a Foodie e Shoe Shuffling.

## Fontes e escopo autorizado

Conta do backup: `marcus.cesar.sp@gmail.com`.

- [Pasta GoodNotes no Drive](https://drive.google.com/drive/u/3/folders/16hczegzfD6ouWNRHGttDUYMiZQT6PEse)
- [Pasta de Programação Competitiva conferida](https://drive.google.com/drive/u/3/folders/14BAvQwVD7kuo90RbTmYZgLkFtLGJpyhc)

| Fonte | Uso | Início da geração | Limite inicial |
| --- | --- | --- | --- |
| Problemas | Principal; exercícios de programação competitiva | Página **45**, inclusive | 99 páginas relatadas e confirmadas no visualizador; gerar do trecho 45–99, respeitando questões incompletas |
| Big Tech Problems | Principal; entrevistas e LeetCode | Página 1 como início do histórico, sem corte adicional solicitado | 15 páginas conferidas no snapshot do Drive; capa na 1, conteúdo nas 2–14, 15 vazia |
| Anotações | Complementar; conceitos básicos das aulas | Sem geração em massa nesta fase | Consultar para esclarecer lacunas e fundamentos relacionados às questões |

Use os títulos exatos observados, incluindo **Big Tech Problems**. A conta correta
agora está disponível tanto no **Drive para computador** quanto na integração
`Pessoal - Prog Competitiva`. A leitura local dos três PDFs foi validada, assim
como a busca remota de metadados e a leitura remota do texto de Big Tech Problems.

**Rota preferencial neste Mac:** ler diretamente a pasta sincronizada pelo Drive,
sem exportar pelo Goodnotes nem baixar manualmente pelo Chrome. Caminhos, IDs,
hashes e resultado do teste estão em [estado/fontes.json](estado/fontes.json).
O procedimento e os limites estão em
[analises/2026-10-28-acesso-drive.md](analises/2026-10-28-acesso-drive.md).
O Drive gerencia a transferência/cache dos arquivos. A pasta foi marcada como
disponível offline e a inicialização do Drive ao entrar no Mac foi confirmada.
**O agente assume a confirmação Drive → Mac antes de cada execução**, conforme
[sincronizacao.md](sincronizacao.md). O usuário cuida de Goodnotes/iPad → Drive.
Os comandos de verificação bloqueiam o lote se não confirmarem metadados remotos
recentes e leitura local estável. PDF offline, sozinho, não comprova atualização.

O Drive pode conter itens de backup antigos ou duplicados. O usuário informou
que deixou somente os corretos. Antes de cada nova execução, reconfirme a origem;
não apague nem misture outras cópias automaticamente.

## Como ler as anotações

A convenção abaixo foi **informada pelo usuário**. A análise de amostras deve
registrar separadamente o que foi realmente confirmado visualmente.

| Sinal | Significado esperado | O que extrair |
| --- | --- | --- |
| Título vermelho | Início/identidade de uma questão | Título, plataforma/ID/link quando presentes; não confundir setas ou rótulos vermelhos de um desenho com título |
| Texto inicial | Explicação breve, entradas e saídas | Objetivo, variáveis, restrições, operações permitidas, exemplos e casos de borda |
| Expected time complexity | Eficiência esperada | Guardar como meta/requisito separado da análise da solução escrita |
| Título azul de lógica | Raciocínio usado pelo usuário | Estratégia, invariantes, decisões, alternativas descartadas, desenhos e trechos de implementação |
| Imagem da questão | Enunciado ou código de apoio | Ler como imagem e associar à questão; não presumir que sua posição é sempre fixa |
| Roxo | Assuntos, aprendizados e observações importantes | Extrair em qualquer região, inclusive dentro da lógica; prioridade para candidatos a cards |
| Verde claro ao fim | Complexidade da solução em Big-O | Tempo e espaço, significado de cada variável e justificativa; separar anotação original de validação técnica |

Não usar só cor ou só OCR. Combinar texto reconhecido, renderização colorida,
posição, continuação entre páginas e significado do conteúdo. Um título pode
estar ausente numa página de continuação, e uma página pode conter várias questões.

Preservar a explicação do usuário antes de complementá-la. Quando houver erro,
armazenar `anotacao_original`, `correcao`, `evidencia` e `status_validacao`; os cards
devem usar a versão tecnicamente validada. Não inferir que uma solução foi aceita
pela plataforma apenas porque há código ou uma explicação escrita.

## Resultado inicial de legibilidade

Veja [a análise inicial das fontes](analises/2026-10-28-fontes.md) e a
[leitura completa do lote histórico](analises/2026-10-28-lote-historico.md).
As análises anteriores registram a situação de sua execução; o cursor e a análise
mais recente registram o estado atual.

## Unidade de trabalho

A unidade é uma **questão com seus aprendizados**, e não uma página nem um PDF.
Para cada questão, guardar:

- ID estável próprio e ID oficial quando verificado; caderno de origem.
- Título, páginas e regiões relevantes (`bbox` normalizada quando disponível).
- Enunciado resumido autocontido, exemplos, restrições e eficiência esperada.
- Lógica original, invariantes, decisões, implementação e casos de borda.
- Todos os trechos roxos e aprendizados, ainda que dispersos.
- Complexidade anotada de tempo/espaço e sua checagem independente.
- Correspondência com código local quando encontrada; ausência não é erro.
- Dúvidas de leitura, lacunas de contexto e grau de confiança por campo.
- Versão da fonte, hashes e IDs dos cards derivados.

O exemplo de linked lists dado na conversa orienta o tipo de habilidade desejada,
mas não comprova que uma determinada questão esteja em uma página específica.

## Cursor e retomada confiável

Fonte canônica do andamento: [estado/cursor.json](estado/cursor.json).
O progresso não deve depender da memória do chat, do PDF aberto nem de `mtime`.

Cada caderno tem controles separados:

1. **Aquisição:** identidade da origem, versão/`modifiedTime` quando disponível,
   contagem de páginas, hash SHA-256 do PDF quando houver cópia local completa.
2. **Inspeção:** quais páginas foram realmente lidas e por qual método. Páginas
   apenas vistas em miniatura ou carregadas pelo visualizador não contam.
3. **Análise:** questões completas, continuações, campos pendentes e validação.
4. **Geração:** próximo ponto da faixa histórica ainda sem cards validados;
   questões já concluídas, IDs e eventuais lacunas anteriores.
5. **Exportação/importação:** lote exportado e confirmação de importação separada.
   Gerar um arquivo não prova que ele foi importado nem que houve aprendizado.

### Gravação por checkpoint

- Ler o estado atual e exigir a mesma `revision` antes da escrita.
- Usar lock de escritor único; numa automação, impedir execuções sobrepostas.
- Salvar primeiro os artefatos completos da questão, validar conteúdo/IDs e
  calcular seus hashes. Só então registrar o checkpoint.
- Gravar o novo JSON num temporário no mesmo diretório, fazer `flush`/`fsync`,
  validar e substituir atomicamente; preservar uma cópia anterior recuperável.
- Acrescentar evento de execução com origem, revisão anterior/nova e motivo.
- Em interrupção, salvar a questão aberta e os campos pendentes, sem promovê-la
  a concluída. Na retomada, reconciliar artefatos existentes antes de repetir.

IDs estáveis tornam uma repetição de execução idempotente. Um único número
`last_page = 99` não resolve retomada, alterações antigas ou inserções no caderno.

### PDF alterado

Guardar hash do documento e, futuramente, impressão de cada página (texto
normalizado + imagem renderizada de modo consistente). Se só páginas finais
forem acrescentadas, manter a identidade das questões já catalogadas e continuar.
Se uma página antiga mudar, reanalisar suas questões, inclusive uma questão que
atravesse a página anterior/seguinte. Reordenar/inserir/excluir páginas exige
remapear por título, contexto e impressão de conteúdo; suspender avanço se houver
ambiguidade. Diferença de bytes do PDF, sozinha, não demonstra mudança semântica.

### Corte da página 45

O usuário corrigiu o início de 49 para **45, inclusive**. As páginas 1–44 ficam
fora do escopo. A faixa 45–99 foi lida em cores no snapshot validado do Drive.
A 45 começa com a legenda e Microwaves; a continuação de Forked na 49 foi
reconciliada com o início nas 48–50, preservando o ID previamente catalogado.

O cursor de Problemas fica na **99** porque Roof Construction só tem título
nessa página e permanece pendente. Os demais assuntos selecionados têm cards
validados e importados. Em Big Tech Problems, o próximo ponto é **16**, após as
15 páginas atuais. Sempre verificar alterações anteriores antes de continuar.

## Como transformar aprendizados em cards

- Priorizar perguntas teóricas e padrões completos de implementação, conforme
  feedback do usuário em 28/10. A unidade pode ser um procedimento coerente
  inteiro (por exemplo, percorrer uma lista e construir outra); evitar fragmentar
  tanto que o card só pergunte um retorno ou uma lacuna isolada.
- Em geral 2–5 cards úteis por questão, sem quota obrigatória. Deduplicar
  conceitos equivalentes entre cadernos/questões.
- Priorizar aprendizados roxos, erros reais, invariantes, padrões de construção,
  condições de validade e diferenças entre uma ideia plausível e a correta.
- Misturar reconstrução de um trecho curto, justificativa, caso de borda,
  diagnóstico de bug e transferência para uma variante pequena.
- Frente autocontida: perguntar pelo conceito, por que funciona e como usá-lo,
  sem exigir lembrar a questão original. Nomear o conceito na pergunta quando
  a habilidade for explicar sua aplicação; não limitar todos os cards a descobrir
  uma técnica escondida ou preencher uma expressão.
- Todo verso deve conter explicação teórica, raciocínio/justificativa e **uso
  concreto do item em código C++17**, requisito explícito do usuário. Código não
  é opcional, inclusive em cards teóricos. Usar um trecho coerente suficiente
  para reconstruir o padrão; evitar copiar a solução inteira sem necessidade.
- Preservar legibilidade no celular, com código comentado, critério de acerto,
  fonte e complexidade quando ajudam. Concisão não deve omitir a teoria nem
  etapas essenciais do procedimento.
- Separar complexidade esperada da obtida. Identificar as variáveis; não pedir
  apenas uma expressão decorada quando a justificativa for o aprendizado.
- Reproduzir desenhos por recorte quando ajudarem; não encher o celular com uma
  página inteira ilegível. Conteúdo textual deve continuar pesquisável.
- Validar símbolos, condições de parada, fórmulas e código antes de exportar.
  Quando necessário, usar enunciado/editorial oficial e casos pequenos verificáveis.
- Dúvidas de caligrafia ou de correção viram pendências, não respostas inventadas.

## Organização no repositório

```text
cards-estudo/
  README.md                    # Escopo, método e operação
  AGENTS.md                    # Instruções de retomada para agentes
  analises/                    # Evidência da leitura e decisões por execução
  estado/cursor.json           # Checkpoint canônico, versionável
  estado/fontes.json           # Caminhos do Drive e verificação de aquisição
  estado/execucoes.jsonl        # Histórico de checkpoints
  modelos/                     # Contratos dos registros e cards
  cards/                       # Cards autorais editáveis e versionáveis
  exportacoes/                 # Markdown, HTML/JSON, TSV e manifesto Anki
  scripts/                     # Aquisição, validação C++ e publicação por API
  tests/                       # Casos de comportamento dos padrões C++
  .cache/fontes/               # PDFs locais, ignorados pelo Git
  .cache/render/               # Imagens/OCR intermediários, ignorados
```

As pastas `cards/` e `exportacoes/` contêm os três lotes definitivos.
O repositório guarda o conteúdo autoral e os checkpoints; respostas,
intervalos e estatísticas de revisão ficam no Anki/AnkiWeb. O histórico local
anterior `../../.revisao/estado.json` (relativo a esta pasta) não deve ser apagado
ou misturado automaticamente.

Arquivos dentro do checkout ainda não são backup remoto. Um commit/push futuro
precisa incluir README, cursores, análises, cards e manifestos; esta preparação
não publica nem faz push. Cópias `.bak` no mesmo disco ajudam recuperação local,
mas não garantem proteção contra perda da máquina.

## Identidade e exportação para o Anki

O cliente escolhido para o iPhone é **AnkiWeb no Safari**, gratuito e com acesso
à internet. O Anki gratuito do Mac recebe os lotes e sincroniza com o AnkiWeb.
Configuração e marcos de acesso estão em [anki.md](anki.md).

**Rota preferencial de envio:** API local **AnkiConnect**, já instalada e
validada com o modelo `CP Goodnotes`. Criação, atualização e sincronização podem
ser feitas por `scripts/anki_client.py`, com o Anki aberto em segundo plano.
O protocolo de identidade abaixo também vale para essa rota; TSV é alternativa.

Cada novo lote tem uma seleção explícita em `lotes/`, com IDs e relatório de
validação. `publish_cards.py --batch 2026-10-28-expansao` planeja somente os
17 complementos; acrescentar `--apply` publica e sincroniza. A execução sem
`--batch` continua limitada aos 69 cards do primeiro relatório. Um lote novo
não sobrescreve os recibos nem os exports dos anteriores.

Os exports de lotes anteriores representam o conteúdo enviado naquela execução.
Ao revisar uma nota, o JSON em `cards/` e seu `anki.last_batch_id` indicam a versão
atual. A revisão `2026-10-28-rating1300` atualizou duas notas existentes sem
recriá-las; os manifestos anteriores continuam como histórico da publicação.

Usar IDs próprios imutáveis, por exemplo `cp-note-000001`, independentes de página,
título de frente ou posição no lote. A exportação TSV deve usar esse ID como
primeiro campo de um tipo de nota próprio, oculto no template de revisão:

```text
ID | Frente | Verso | Fonte | Tags
```

A barra acima explica os campos; o arquivo real terá tabulações, UTF-8 e HTML
com escape de `<`, `>` e `&` do código. Ativar correspondência por primeiro campo
e atualização das notas existentes. Não inventar GUIDs internos do Anki.
Não usar só a pergunta como identidade, pois revisá-la criaria duplicatas.

Reimportações devem preservar a mesma nota e seus cards. Mudar o número/tipo de
templates ou recriar IDs exige cuidado específico com o histórico. Não substituir
`collection.anki2`. Manter manifesto de cada lote e confirmação separada de import.

## Rotina proposta e automação futura

1. Resolver e anotar normalmente no Goodnotes; o backup atualiza o PDF no Drive.
2. Uma execução lê `estado/fontes.json`, verifica a sincronização e obtém uma
   fonte estável da pasta local do Drive; compara versões, lê cursor e identifica
   as questões novas, alteradas e pendentes. A integração direta pode consultar
   metadados e servir de alternativa quando o acesso local não estiver disponível.
3. Extrair por questão, validar, gerar/atualizar cards no repo e salvar checkpoint.
4. Exportar um lote idempotente, importar no Anki do Mac e sincronizar com AnkiWeb.
5. Revisar no celular em pequenos intervalos; começar com cerca de 10 minutos/dia
   e 3–5 cards novos/dia, ajustando à carga real. Revisões difíceis continuam
   voltando; o agendador do Anki decide os intervalos a partir das avaliações.
   A coleção foi observada com SM-2; FSRS não foi ativado nesta execução.
6. Reservar prática no computador para reimplementar padrões e questões difíceis.

Antes de agendar: validar aquisição na conta correta, leitura de cores e código,
cursor com recuperação, IDs/importação sem duplicatas, revisão de um lote piloto
e ausência de geração para cadernos incompletos. Essas etapas são requisitos do
fluxo, não automações já instaladas. Notificações e horários ainda não foram
solicitados nem configurados.

## Critério para começar o primeiro lote

- Fontes obtidas e identificadas, com versão e paginação conferidas.
- Amostras de ambos os cadernos principais legíveis e documentadas.
- Primeira questão completa e suas observações roxas delimitadas.
- Páginas 45–48 lidas e continuidade com a página 49 reconciliada, sem omissão silenciosa.
- Contrato dos cards e tipo de nota/ID estável definidos.
- Cursor válido preservando o começo em 45 até concluir a primeira unidade.
- Lote piloto pequeno, tecnicamente conferido, antes de expandir o histórico.

## Referências operacionais

- [Backup do Goodnotes](https://support.goodnotes.com/hc/en-us/articles/7352786555279-How-to-Set-Up-Auto-Backup-in-Goodnotes)
- [Exportação PDF e reconhecimento de escrita](https://support.goodnotes.com/hc/en-us/articles/8537070839183-Choose-Between-Editable-and-Flattened-PDF-Export)
- [Importação e atualização no Anki](https://docs.ankiweb.net/manual/importing/text-files)
- [FSRS e opções de baralho](https://docs.ankiweb.net/manual/deck-options)
