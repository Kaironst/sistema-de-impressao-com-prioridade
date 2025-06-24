
// Autor: Bruno Kissen

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../usuarios/usuarios.h"
#include "../impressao/impressao.h"
#include "../fila/fila.h"
#include "../historico/historico.h"

int main() {
    NoUsuario* listaUsuarios = iniListaUsuario();
    NoFila* primeiroFila = iniNoFila();
    NoFila* ultimoFila = iniNoFila();
    NoHistorico* historico = iniNoHistorico();

    int opcao;
    do {
        printf("\n--- MENU SISTEMA DE IMPRESSAO ---\n");
        printf("1. Cadastrar usuário\n");
        printf("2. Cadastrar solicitação de impressão\n");
        printf("3. Executar impressão\n");
        printf("4. Mostrar fila de espera\n");
        printf("5. Mostrar histórico de impressões\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {   //cadastrar usuario
                char nome[100];
                int cpf, tipo;

                printf("Nome: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("CPF: ");
                scanf("%d", &cpf);

                printf("Tipo (1=Estudante, 2=Professor, 3=Administração/Direção): ");
                scanf("%d", &tipo);
                getchar();

                if (addUsuario(listaUsuarios, nome, cpf, (tipoUsuario)tipo))
                    printf("Usuário adicionado com sucesso.\n");
                else
                    printf("Erro ao adicionar usuário.\n");
                break;
            }

            case 2: {   //cadastrar solicitacao de impressao
                int cpf, paginas;
                printf("CPF do usuário: ");
                scanf("%d", &cpf);
                getchar();

                NoUsuario* usuario = getUsuarioCpf(listaUsuarios, cpf);
                if (!usuario) {
                    printf("Usuário não encontrado.\n");
                    break;
                }

                printf("Número de páginas: ");
                scanf("%d", &paginas);

                Impressao* nova = criarImpressao(usuario, paginas);
                colocarEmFila(nova, primeiroFila, ultimoFila);
                printf("Solicitação adicionada à fila.\n");
                break;
            }

            case 3: { //executar impressao
                realizarImpressao(historico, primeiroFila, ultimoFila);
                break;
            }
                
            case 4: { //mostrar fila de espera
                printFila(primeiroFila, ultimoFila);
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
                printf("Opção inválida. Tente novamente.\n");
                break;
            }
        }

    } while (opcao != 6);

    freeListaUsuario(listaUsuarios);
    freeFila(primeiroFila);
    freeFila(ultimoFila);
    freeHistorico(historico);
    
    return 0;
}
