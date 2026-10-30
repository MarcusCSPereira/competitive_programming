# Rotina diária Goodnotes → Anki

Automação **Gerar cards do Goodnotes**, ID `gerar-cards-do-goodnotes`, ativa
todos os dias às **12:30 — America/Bahia**. Foi criada como retorno a este chat
no Codex, usando o checkout local do repositório. O fuso do Mac foi conferido
como America/Bahia. A definição executável é gerenciada pelo agendador do app.

## O que acontece em cada execução

1. Ler AGENTS, README, fontes, cursor e análise recente. Reconciliar primeiro
   qualquer lote já gerado mas ainda não importado/sincronizado, sem recriá-lo.
2. Conferir Drive → Mac pelo gate obrigatório: listar os PDFs ativos na pasta
   remota conhecida, verificar IDs e duplicatas, obter metadados recentes,
   prepare, nova consulta remota e confirm. Só iniciar análise dentro da validade
   e usar os snapshots imutáveis dessa execução.
3. Comparar páginas autorizadas, inclusive antigas alteradas. Problemas começa
   na 45, inclusive; Big Tech Problems é a outra fonte principal. Anotações é
   complementar. Revisar também soluções locais novas quando relevantes.
4. Delimitar questões e identificar aprendizados distintos, especialmente os
   roxos. Questão incompleta fica registrada; uma solução local completa pode
   complementar um manuscrito parcial, com origem e lacunas declaradas.
5. Gerar ou aprimorar cards com teoria, justificativa e C++17 obrigatório.
   Validar código e casos de comportamento antes de publicar. Não há quota de
   cards gerados por dia ou por questão; evitar duplicação e fragmentação inútil.
6. Salvar JSON autoral, casos, análise e lote com seleção explícita. Atualizar
   catálogo, IDs e checkpoints por questão, com trava e substituição atômica.
7. Conferir perfil User 1, baralho Programação competitiva e modelo CP Goodnotes.
   Sincronizar antes da escrita. Criar/atualizar via AnkiConnect por ID estável,
   reler o resultado e sincronizar até confirmar conclusão. Preservar histórico.

O limite de **10 cards novos por dia** controla o estudo, e não quantos cards
existem nem quantos podem ser gerados. A rotina preserva esse limite e a ordem
de revisões primeiro. Não remove cards nem reinicia os agendamentos.

## Condições de execução

O Mac deve estar ligado, com o Codex aberto e conexão à internet. O checkout e
a conta do Drive precisam continuar acessíveis. Se o Anki estiver fechado, a
rotina pode iniciá-lo pela interface disponível e continuar pela API local.
Essa abertura e a retomada da API foram testadas durante a preparação.

A execução programada pode aguardar o chat ficar disponível. Mac desligado ou
suspenso impede garantir o início naquele horário. Não foram alterados ajustes
de energia, rede, credenciais ou inicialização do Codex.

Se o gate de fonte falhar, não analisar cópia antiga nem avançar o cursor. Se
a importação falhar, manter os cards já validados e o lote pendente para retomar.
Um timeout de operação Anki não significa cancelamento: consultar seu ID antes
de repetir. Não fazer commit/push nem criar outras automações por esta rotina.

Sem novidades, a execução registra a checagem sem avisos repetidos. Informar no
chat quando houver cards novos/aprimorados sincronizados, falha relevante ou
algo que dependa do usuário. Contagens e estado de importação devem ser precisos.

## Estado da validação

O fluxo incremental foi exercitado manualmente em 29/10/2026, incluindo mudança
de PDF, comparação das páginas antigas, resolução de uma pendência com fonte
local/oficial, testes C++ e envio ao Anki. A primeira execução disparada pelo
agendador ainda será confirmada pelo seu resultado; criar a agenda não comprova
uma execução futura.

Consulte `estado/automacao-diaria.json`, `estado/cursor.json` e a análise de
29/10 para os resultados e quantidades atuais.

Referência: [tarefas agendadas na documentação oficial OpenAI](https://learn.chatgpt.com/docs/automations?surface=app).

## Abertura automática do Codex

Configurada em 2026-10-29T22:13:53-03:00 por solicitação do usuário. O agente do macOS
`local.codex.open-at-login` inicia o app de bundle `com.openai.codex` ao entrar
na sessão gráfica, com as opções oficiais de abertura em segundo plano e oculto.
O app instalado neste Mac aparece como ChatGPT, em `/Applications/ChatGPT.app`.
Não há relançamento forçado quando o usuário fecha o aplicativo.

A configuração foi validada com plutil, proprietário/permissões e argumentos.
Ela entra em vigor no próximo início de sessão; esse primeiro login ainda não
foi observado. Oculto em segundo plano é o comportamento configurado, sem exigir
que a janela fique minimizada no Dock. Registro: `estado/codex-inicio-sessao.json`.

### Anki também abre oculto

Configurado em 2026-10-29T22:20:55-03:00 para iniciar automaticamente ao entrar na sessão
gráfica do Mac, em segundo plano e oculto. O LaunchAgent é
`local.anki.open-at-login`, com bundle `net.ankiweb.anki`. O primeiro login
ainda não foi observado; a configuração e os argumentos foram validados.
Registro: `estado/anki-inicio-sessao.json`.

Com o Anki aberto em segundo plano, criação, atualização e sincronização dos
cards continuam pela API AnkiConnect. Se o usuário o fechar, a rotina pode
precisar iniciá-lo novamente; mantenha a janela minimizada/oculta pelos meios
disponíveis e use a API para os cards. O horário permanece 12:30 e o estudo
continua limitado a 10 novos por dia, além das revisões.
