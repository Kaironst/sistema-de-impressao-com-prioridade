
// Autor: Bruno Kissen

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "usuarios/usuarios.h"
#include "impressao/impressao.h"
#include "fila/fila.h"
#include "historico/historico.h"

int main() {
    NoUsuario* listaUsuarios = iniListaUsuario();
    FilaImpressao* filaImpressao  = iniFila();
    NoHistorico* historico = iniNoHistorico();

    int opcao;
    do {
        printf("\n--- MENU SISTEMA DE IMPRESSAO ---\n");
        printf("1. Cadastrar usuario\n");
        printf("2. Cadastrar solicitacao de impressao\n");
        printf("3. Executar impressao\n");
        printf("4. Mostrar fila de espera\n");
        printf("5. Mostrar historico de impressoes\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {   //cadastrar usuario
                char nome[100];
                int cpf, tipo;

                printf("Nome: ");
                scanf("%c", (char *) stdin); //flush no input buffer
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("CPF: ");
                scanf("%d", &cpf);

                printf("Tipo (1=Estudante, 2=Professor, 3=Administracao/Direcao): ");
                scanf("%d", &tipo);
                getchar();

                if (addUsuario(listaUsuarios, nome, cpf, (tipoUsuario)tipo))
                    printf("Usuario adicionado com sucesso.\n");
                else
                    printf("Erro ao adicionar usuario.\n");
                break;
            }

            case 2: {   //cadastrar solicitacao de impressao
                int cpf, paginas;
                printf("CPF do usuario: ");
                scanf("%d", &cpf);
                getchar();

                NoUsuario* usuario = getUsuarioCpf(listaUsuarios, cpf);
                if (!usuario) {
                    printf("Usuario nao encontrado.\n");
                    break;
                }

                printf("Numero de paginas: ");
                scanf("%d", &paginas);

                Impressao* nova = criarImpressao(usuario, paginas);
                colocarEmFila(nova, filaImpressao);
                printf("Solicitacao adicionada a fila.\n");
                break;
            }

            case 3: { //executar impressao
                realizarImpressao(historico, filaImpressao);
                break;
            }
                
            case 4: { //mostrar fila de espera
                printFila(filaImpressao);
                break;
            }
                
            case 5: { //mostrar historico
                printHistorico(historico);
                break;
            }
                
            case 6: { //sair
                printf("Encerrando o sistema...\n");
                break;
            }
                
            default: { //opcao invalida
                printf("Opcao invalida. Tente novamente.\n");
                break;
            }
        }

    } while (opcao != 6);

    freeListaUsuario(listaUsuarios);
    freeFila(filaImpressao);
    freeHistorico(historico);
    
    return 0;
}
