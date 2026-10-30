# Sincronização Drive → Mac antes dos cards

O usuário cuida de Goodnotes/iPad → Google Drive. O agente cuida de confirmar
Drive → Mac em cada execução de análise ou geração. Ter o PDF no Finder ou
ter configurado disponibilidade offline não dispensa essa confirmação.

## Configuração verificada em 28/10/2026

- Conta: `marcus.cesar.sp@gmail.com`, conexão `Pessoal - Prog Competitiva`.
- Caminhos e IDs dos três PDFs: [estado/fontes.json](estado/fontes.json).
- Google Drive para computador iniciado. Nas preferências, a opção **Iniciar o
  Google Drive quando você fizer login no computador** já estava marcada.
- Pasta `GoodNotes/César/Programação Competitiva` marcada como **disponível
  offline** pelo Finder. A confirmação exibiu `Available offline` e a ação
  inversa `Disponibilizar apenas on-line`.
- A pasta de backup é somente fonte. Não gravar nela cards, cursores ou caches.

## Procedimento obrigatório do agente

1. Ler `estado/fontes.json` e `estado/cursor.json`. Confirmar que o Drive está
   executando; iniciar o aplicativo, se necessário. Conferir a conta configurada
   e resolver qualquer pausa/erro de sincronização pela interface oficial.
2. Consultar pelo conector os PDFs ativos dentro de `drive_folder_id`, usando
   `connector.link_id`. Exemplo de filtro: `trashed = false and
   '14BAvQwVD7kuo90RbTmYZgLkFtLGJpyhc' in parents`. Guardar a resposta em
   `.cache/sync/remote-before.json` com o envelope abaixo. `fetched_at` deve ser
   o horário real de término da consulta, nunca renovado sem nova consulta.

   ```json
   {
     "account": "marcus.cesar.sp@gmail.com",
     "folder_id": "14BAvQwVD7kuo90RbTmYZgLkFtLGJpyhc",
     "fetched_at": "HORÁRIO_ISO_8601_COM_FUSO_DA_CONSULTA_REAL",
     "files": ["RESULTADOS_COMPLETOS_DO_CONECTOR_COM_ID_NOME_PARENTS_SIZE_MTIME_MIME"]
   }
   ```

   O exemplo descreve o envelope; substituir `files` pelos objetos reais de
   metadados. Não passar apenas títulos ou inventar metadados. Se a busca
   retornar paginação, obter todas as páginas antes de montar o envelope.
3. Na raiz do repositório C++, executar:

   ```sh
   python3 cards-estudo/scripts/sync_guard.py prepare --remote cards-estudo/.cache/sync/remote-before.json
   ```

   O comando invalida a autorização anterior, lê integralmente cada PDF com
   timeout, exige tamanho/data iguais aos metadados remotos, assinatura PDF,
   marcador final, contagem de páginas e arquivo estável durante a leitura.
   Guarda uma cópia por SHA-256 em `.cache/sync/snapshots/`, ainda bloqueada.
4. Após `prepare` terminar, fazer **nova consulta remota** e salvar o mesmo
   envelope em `.cache/sync/remote-after.json`, com seu próprio horário real.
   Executar:

   ```sh
   python3 cards-estudo/scripts/sync_guard.py confirm --remote cards-estudo/.cache/sync/remote-after.json
   ```

   A confirmação exige metadados remotos inalterados entre as consultas,
   cópia local ainda estável, snapshot íntegro e preparação pendente da mesma
   execução. Evidências expiram em cinco minutos; não reutilizar uma confirmação
   já consumida. Os comandos usam trava de escrita e substituição atômica.
5. Exigir saída zero, `status: verified`, `generation_allowed: true`, dentro de
   `valid_until`, em [estado/sincronizacao.json](estado/sincronizacao.json).
   Abrir **os snapshots desse relatório** para o lote iniciado nessa execução.
   Registrar seus hashes e páginas no histórico. Um resultado antigo não
   autoriza uma execução nova, mesmo que os arquivos pareçam iguais.
6. Comparar a nova versão com o catálogo antes de retomar. Mudanças de páginas
   ou inserções exigem remapeamento. A contagem de páginas é observação, não
   progresso. Problemas continua autorizado somente a partir da página **45**.

Dependências: Python 3 padrão e `pdfinfo` (Poppler), já disponíveis neste Mac.
O script não contém login, tokens ou um cliente próprio da API do Google. A
consulta autenticada é feita pelo conector do agente em cada execução.

## Atrasos, falhas e alcance da garantia

Se o arquivo estiver ausente, desatualizado, incompleto ou mudando, não iniciar
análise/geração. Verificar o Drive, solicitar atualização da pasta pelo Finder
quando útil e repetir o ciclo com consultas novas. Fazer até três tentativas
com esperas curtas; persistindo a divergência, registrar o bloqueio para retomar
depois. Não exportar do Goodnotes como atalho, nem trocar IDs automaticamente.

Falha do conector, conta desconectada, ausência de rede ou timeout também
bloqueiam: PDF offline pode estar antigo. Preservar cursor e cards existentes.
Não apagar cópias, redefinir contas ou editar o arquivo remoto para forçar sync.

A garantia operacional é: **o agente só inicia um lote após confirmar os
metadados atuais e uma leitura local estável**. O conector atual não devolve
checksum remoto, mesmo solicitado; por isso tamanho e data não são prova de
igualdade criptográfica com o servidor. SHA-256 protege a identidade do snapshot
local. Se checksum remoto passar a ser fornecido, o script também o compara.

O relatório é uma verificação pontual, não um monitor permanente. O Drive só
atualiza o Mac quando este está ligado, com sessão/serviço ativos e conectividade.
Ao retomar, repetir a confirmação antes dos cards. Nenhum agendamento foi criado
nesta etapa; futuras automações devem executar este mesmo protocolo.

## Validação

```sh
python3 -m unittest discover -s cards-estudo/scripts -p 'test_*.py' -v
```

Dez testes cobrem cópia válida, tamanho incompleto, data atrasada mesmo com
tamanho igual, checksum divergente, evidência expirada, conta errada,
duplicidade, alteração remota e revogação/reutilização de autorizações.
