
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
        printf("6. Estatisticas\n");
        printf("7. Sair\n");
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
                
            case 6: {
                int totalEstudante = 0, totalProfessor = 0, totalAdmin = 0;
                int paginasEstudante = 0, paginasProfessor = 0, paginasAdmin = 0;
                int countEstudante = 0, countProfessor = 0, countAdmin = 0;

                NoHistorico* atual = historico->proximo;
                while (atual != NULL) {
                    Impressao* imp = atual->impressao;
                    if (imp && imp->usuario) {
                        switch (imp->usuario->tipoUsuario) {
                            case ESTUDANTE:
                                totalEstudante++;
                                paginasEstudante += imp->numPaginas;
                                countEstudante++;
                                break;
                            case PROFESSOR:
                                totalProfessor++;
                                paginasProfessor += imp->numPaginas;
                                countProfessor++;
                                break;
                            case ADMINISTRACAO:
                                totalAdmin++;
                                paginasAdmin += imp->numPaginas;
                                countAdmin++;
                                break;
                        }
                    }
                    atual = atual->proximo;
                }

                printf("\n--- Estatisticas ---\n");
                printf("Total de impressoes:\n");
                printf("Estudantes: %d\n", totalEstudante);
                printf("Professores: %d\n", totalProfessor);
                printf("Administracao/Direcao: %d\n", totalAdmin);

                printf("\nNumero total de paginas:\n");
                printf("Estudantes: %d\n", paginasEstudante);
                printf("Professores: %d\n", paginasProfessor);
                printf("Administracao/Direcao: %d\n", paginasAdmin);

                printf("\nTempo medio estimado por prioridade (supondo 5s por pagina):\n");
                if (countEstudante > 0)
                    printf("Estudantes: %.2f s\n", (paginasEstudante * 5.0) / countEstudante);
                else
                    printf("Estudantes: N/A\n");
                if (countProfessor > 0)
                    printf("Professores: %.2f s\n", (paginasProfessor * 5.0) / countProfessor);
                else
                    printf("Professores: N/A\n");
                if (countAdmin > 0)
                    printf("Administracao/Direcao: %.2f s\n", (paginasAdmin * 5.0) / countAdmin);
                else
                    printf("Administracao/Direcao: N/A\n");

                break;
            }

            case 7:
                printf("Encerrando o sistema...\n");
                break;

            default:
                printf("Opcao inválida. Tente novamente.\n");
                break;
        }

    } while (opcao != 7);

    freeListaUsuario(listaUsuarios);
    freeFila(filaImpressao);
    freeHistorico(historico);

    return 0;
}
