# Acesso aos cadernos pelo Drive — verificação de 28/10/2026

## Resultado

**Funcionou a leitura direta dos três PDFs pela pasta sincronizada do Drive para
computador, sem exportação pelo Goodnotes ou download manual pelo navegador.**
A conta `marcus.cesar.sp@gmail.com` também passou a aparecer na integração com
o nome `Pessoal - Prog Competitiva`.

Pasta local conferida:

```text
/Users/marcus_cs_pereira/Library/CloudStorage/GoogleDrive-marcus.cesar.sp@gmail.com/Meu Drive/GoodNotes/César/Programação Competitiva
```

| Arquivo | Páginas | Tamanho em bytes | Teste |
| --- | --- | --- | --- |
| Problemas.pdf | 99 | 68.343.204 | Leitura completa para hash; texto da 45; renderização colorida da 45 |
| Big Tech Problems.pdf | 15 | 10.072.014 | Leitura completa para hash; texto e renderização colorida da 14 |
| Anotações.pdf | 40 | 24.476.332 | Leitura completa para hash e estrutura do PDF; conteúdo pedagógico não analisado |

Os tamanhos locais coincidiram com os metadados retornados pela integração para
os IDs na pasta remota conhecida. Tamanho e data locais ficaram estáveis durante
a leitura. Os hashes SHA-256 e IDs foram salvos em `../estado/fontes.json`.
Essa comparação não é uma prova criptográfica dos bytes no servidor: o conector
não forneceu um checksum remoto para essa comparação.

## Legibilidade confirmada

A página 45 de Problemas contém a própria legenda `Novo Padrão` e o início de
`Microondas`. A renderização preserva as cores e os desenhos. A página 14 de
Big Tech Problems continua legível e contém Add Two Numbers, sua lógica, o código,
os assuntos roxos e a complexidade em verde.

Os PDFs do backup possuem texto reconhecido extraível: foram obtidos 1.370
caracteres na amostra da página 45 de Problemas e 1.186 na página 14 de Big Tech
Problems. Há ruído, falta de espaços e símbolos incorretos; o texto auxilia a
busca, mas não substitui a conferência da imagem. Isso difere da exportação manual
de Problemas no Mac usada na inspeção anterior, cuja amostra não expunha texto.

O parser tolerante emitiu avisos de referências internas do PDF durante a leitura,
mas os três documentos abriram e as duas páginas de teste renderizaram. A fonte
sincronizada não foi regravada ou reparada. Cada execução deve validar abertura e
renderização antes de considerar seu conteúdo utilizável.

## Integração direta também testada

- Busca na conta correta listou os três PDFs, seus IDs, tamanhos e datas.
- A operação de leitura de Big Tech Problems retornou texto reconhecido.
- Não foi necessário testar download remoto bruto do PDF nesta execução porque
  a leitura do arquivo completo pela pasta local já funcionou.
- Uma resposta de texto do conector, sozinha, não preserva o papel pedagógico das
  cores. Para interpretar as cores, continuar renderizando o PDF original.

## Rota operacional recomendada

1. Goodnotes do iPad atualiza seu backup no Drive.
2. Drive para computador sincroniza a pasta dessa conta no Mac.
3. O agente lê os caminhos de `estado/fontes.json`; consulta obrigatoriamente os
   metadados remotos antes e depois da leitura local, conforme `../sincronizacao.md`.
4. Validar assinatura `%PDF-`, número de páginas, versão e estabilidade do arquivo
   antes/depois da leitura. Se o arquivo estiver mudando ou a cópia local divergir
   do backup remoto, aguardar/repetir sem avançar o cursor.
5. Ler as páginas de interesse e gerar imagens/texto intermediários somente no
   cache ignorado do repo; guardar cards e estado nos diretórios versionáveis.

Não usar a pasta de backup como destino dos cards ou de arquivos intermediários.
Acesso aos cadernos deve ser somente leitura.

No primeiro teste os arquivos tinham o sinalizador macOS `dataless`: eram itens
somente online. Ler o conteúdo acionou a obtenção dos dados pelo Drive. Não há
download manual nem uma nova cópia/exportação de cada caderno pelo agente, mas
a transferência para o Mac continua existindo e é gerenciada pelo Drive.

Na continuação de 28/10, o agente tornou **a pasta de Programação Competitiva
disponível offline** pelo menu do Finder e confirmou o estado `Available offline`
e a opção inversa `Disponibilizar apenas on-line`. Nas preferências do Drive,
confirmou que iniciar ao fazer login já estava habilitado. Verificar a atualização
continua necessário mesmo com arquivos offline: o protocolo obrigatório e o
bloqueio antes de processar estão em [sincronizacao.md](../sincronizacao.md).

Referências oficiais: [Drive no macOS](https://support.google.com/drive/answer/12178485?hl=en),
[transmissão e espelhamento](https://support.google.com/drive/answer/13401938?hl=en-193)
e [arquivos offline](https://support.google.com/drive/answer/2375012?hl=en-193).

## Cursor e limites desta execução

Esta execução verificou transporte e legibilidade. **Não gerou cards nem avançou
a análise do histórico para além do corte.** O cursor de geração continua em
Problemas **45** e Big Tech Problems **1**. As amostras da preparação anterior
e a identidade de seus snapshots foram preservadas; a verificação atual foi
registrada separadamente.

Execução automática com o Mac em condições reais, reconhecimento de questões,
validação de cards e importação no Anki ainda precisam de teste antes de agendar.
