# Protocolo persistente dos cards

1. Leia `README.md`, `estado/cursor.json` e a última análise em `analises/` antes
   de trabalhar. Os caminhos deste arquivo são relativos a `cards-estudo/`.
2. Priorize `Problemas` a partir da página 45 e `Big Tech Problems`. `Anotações`
   é fonte complementar. Não modifique os cadernos para marcar progresso.
3. Leia também `estado/fontes.json`. Prefira os PDFs na pasta local do Drive
   validada nesse arquivo. Confirme conta, pasta, identidade do arquivo, número
   de páginas, versão e sincronização antes de processar. A integração
   `Pessoal - Prog Competitiva` pode consultar metadados e servir de alternativa.
   Não selecione entre duplicatas apenas pelo nome ou pela data. Não exporte
   pelo Goodnotes nem controle o Chrome se o acesso direto validado funcionar.
   Execute obrigatoriamente o ciclo `prepare` → nova consulta remota → `confirm`
   de `sincronizacao.md` em cada execução; não reutilize aprovação de outra
   execução. Só inicie o lote com `estado/sincronizacao.json` verificado e dentro
   de `valid_until`; use os snapshots desse relatório. Falha de sync bloqueia
   processamento e avanço do cursor. O agente assume Drive → Mac; o usuário
   assume iPad/Goodnotes → Drive.
4. Separe observação visual, extração, validação, geração e importação. Ler ou
   catalogar uma página NÃO significa que seus cards foram gerados/validados.
5. Salve pendências e cursor a cada questão completa ou interrupção. Preserve o
   estado anterior, valide o JSON e escreva por substituição atômica. Use um só
   escritor. Se houver edição concorrente ou estado corrompido, preserve os
   arquivos e resolva a divergência antes de continuar.
6. Só avance `generation.next_page` após salvar e validar todos os artefatos da
   questão e registrar seus IDs. Registre lacunas explicitamente; não pule uma
   questão ilegível/incompleta silenciosamente. Um bloqueio no começo não impede
   analisar outra questão, mas o cursor contíguo deve preservar a lacuna.
7. Preserve IDs das questões/cards entre novas versões do PDF; número de página
   é localização, não identidade. Compare páginas anteriores alteradas também.
   Inserção/exclusão/reordenação exige remapeamento antes de retomar por número.
8. Roxo tem prioridade de extração em QUALQUER posição da página. Cor é pista,
   não prova exclusiva da função do trecho. Preserve lógica, desenhos e contexto.
9. Diferencie o que o usuário anotou da correção técnica. Não publique um erro
   manuscrito/OCR como resposta correta. Guarde dúvidas para validação.
   A preferência explícita é por teoria ligada a um padrão completo de uso.
   TODO verso deve incluir uso concreto em C++17, mesmo em cards conceituais.
   Evite perguntas tão fragmentadas que se restrinjam a um retorno/lacuna;
   reconstruir um procedimento coerente inteiro é uma unidade válida de card.
10. Cards autorais editáveis ficam em `cards/`; exports Anki em `exportacoes/`.
    Histórico de respostas e agenda pertencem ao Anki. Não reimporte zerando-os.
    Leia `anki.md`: prefira a API local AnkiConnect, já instalada, ao controle de
    tela para enviar/atualizar notas e sincronizar. Use `scripts/anki_client.py`,
    confirme perfil/baralho/sessão e preserve IDs. `notes.validate` não é revisão
    técnica do conteúdo. Não avance geração por configurar o modelo ou a API.
11. PDFs originais, renderizações e OCR bruto ficam em `.cache/` (ignorado).
    Nunca grave tokens, cookies ou links temporários autenticados no Git.
12. O usuário aprovou o formato e autorizou a geração histórica em lote em
    28/10/2026: mais de um card por questão quando houver aprendizados distintos,
    priorizando os melhores assuntos. Gere e envie os cards validados ao Anki.
    Preserve lacunas e questões abertas. Não crie agendamentos apenas por
    encontrar datas ou tarefas pendentes neste diretório.
13. A revisão de cobertura seguinte acrescentou 17 cards, IDs 000070–000086.
    Naquela execução o total chegou a 86. O próximo ID está no cursor; consulte `estado/revisao-cobertura.json`
    e a análise mais recente. Os lotes têm seleção explícita em `lotes/` e
    validação separada. Não publique todos os arquivos sob o nome do primeiro
    lote; preserve recibos, manifestos e IDs anteriores. Complementos didáticos
    devem ser identificados como tais, sem atribuí-los ao manuscrito original.
14. A revisão das questões recentes acrescentou IDs 000087–000091 e atualizou
    000051/000052 preservando notas e revisões: total 91, próximo ID 000092.
    Make it Alternating (cp-problem-000061, 1879C) usa código local e enunciado
    oficial, sem página localizada no PDF. Não inventar página/cor nem marcar
    manuscrito como conferido nessa origem. Ao aparecer no caderno, vincular ao
    mesmo ID e aos quatro cards existentes. Consultar `estado/revisao-recentes.json`
    e `analises/2026-10-28-rating1300.md`; os cursores PDF seguem 99 e 16.
15. Em 29/10 o usuário autorizou a rotina diária às 12:30 (America/Bahia).
    A automação `gerar-cards-do-goodnotes` retorna a este chat. Leia também
    `rotina-diaria.md`. Reconciliar lotes pendentes de importação mesmo quando
    os PDFs não mudarem. Os totais e próximos IDs dos itens anteriores são
    históricos; use sempre o cursor atual. Preserve 10 novos por dia no Anki.
    Execute geração, testes e publicação dos conteúdos validados dentro do
    escopo autorizado; não exigir nova aprovação a cada lote. Não confundir
    validação manual do fluxo com confirmação de uma execução futura agendada.
