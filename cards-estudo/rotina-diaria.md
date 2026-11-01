# Rotina diária Goodnotes → Anki

**Desativada em 01/11/2026 por solicitação do usuário.** A automação
`gerar-cards-do-goodnotes` está PAUSED no app, com leitura de volta confirmada.
A antiga agenda diária às 12:30 America/Bahia fica preservada como configuração
pausada. Codex e Anki tiveram a abertura automática no login removida.
Não reativar nem reinstalar os serviços sem novo pedido. Os passos abaixo
servem de referência para futuras execuções manuais solicitadas.

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
local/oficial, testes C++ e envio ao Anki. Uma execução disparada pelo agendador foi recebida em 31/10 às 19:47 e teve
o fluxo completo confirmado: 3 novos cards, 2 aprimorados, total96. O recebimento
posterior ao horário da agenda não comprova pontualidade às 12:30.

Consulte `estado/automacao-diaria.json`, `estado/cursor.json` e a análise mais
recente para resultados, quantidades atuais e pendências.

Referência: [tarefas agendadas na documentação oficial OpenAI](https://learn.chatgpt.com/docs/automations?surface=app).

## Histórico da abertura automática do Codex (removida em 01/11/2026)

Configurada em 2026-10-29T22:13:53-03:00 por solicitação do usuário. O agente do macOS
`local.codex.open-at-login` iniciava o app de bundle `com.openai.codex` ao entrar
na sessão gráfica, com as opções oficiais de abertura em segundo plano e oculto.
O app instalado neste Mac aparece como ChatGPT, em `/Applications/ChatGPT.app`.
Não há relançamento forçado quando o usuário fecha o aplicativo.

A configuração foi validada com plutil, proprietário/permissões e argumentos.
Ela entra em vigor no próximo início de sessão; esse primeiro login ainda não
foi observado. Oculto em segundo plano é o comportamento configurado, sem exigir
que a janela fique minimizada no Dock. Registro: `estado/codex-inicio-sessao.json`.

### Histórico do Anki oculto (removido em 01/11/2026)

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

## Desativação confirmada em 01/11/2026

A automação foi pausada pela ferramenta do app e relida como PAUSED. Os serviços
`local.codex.open-at-login` e `local.anki.open-at-login` foram desabilitados e
descarregados do launchd. Os arquivos foram retirados de Library/LaunchAgents
e guardados em `.codex/backups/startup-disabled-2026-11-01`, fora da pasta de
inicialização. A entrada adicional ChatGPT.app (bundle com.openai.codex) também
foi removida de Abrir no Início da Sessão nos Ajustes do Sistema.

Cards, histórico de revisões, fontes e cursores de geração foram preservados.
Os registros `estado/*-inicio-sessao.json` e `estado/automacao-diaria.json`
contêm o estado atual; instruções de configuração anteriores são histórico.
