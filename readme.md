# Introdução

Este é um trabalho realizado por Pedro Novak Wosch e Bruno Kussen, referente à disciplina de Estrutura de Dados da UFPR, dirigido pelo professor Helcio Soares Padilha Junior.

Aqui foi realizado a implementação de um sistema de impressão com prioridades dentro de laboratório de informática que compartilha uma impressora entre diversos usuários.
O sistema é capaz de realizar as seguintes tarefas:

- Cadastro de usuários,
- Solicitar impressões,
- Executar impressões,
- Mostrar fila de espera,
- Mostrar histórico de impressões. 

# Instrução de sistema
Ao iniciar o arquivo main.c, o usuário verá o seguinte menu:

``` c
=== MENU SISTEMA DE IMPRESSAO ===
"1. Cadastrar usuario"
"2. Cadastrar solicitacao de impressao"
"3. Executar impressao"
"4. Mostrar fila de espera"
"5. Mostrar historico de impressoes"
"6. Estatisticas"
"7. Sair"
"Escolha uma opcao: "
```

Após digitar o número referente a uma dessas opções no terminal, o usuário receberá novos prompts para completar a tarefa requisitada.
Um exemplo, utilizando a função 2. Cadastrar solicitacao impressao:

``` c
"CPF do usuário: "12345678901
"Número de páginas: "3
"Solicitação adicionada à fila."
```
No caso da função 6. Estatísticas, são mostradas:

- Total de impressões por tipo de usuário
- Tempo médio estimado por prioridade
- Número de páginas por tipo de usuário

Para o tempo médio estimado, caso não tenha sido realizado nenhuma impressão daquela prioridade, será mostrado como N/A.
