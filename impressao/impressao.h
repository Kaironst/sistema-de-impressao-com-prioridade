#include "../usuarios/usuarios.h"
#ifndef IMPRESSAO_H
#define IMPRESSAO_H

typedef struct IMPRESSAO {
int numPaginas;
NoUsuario* usuario;
}Impressao;

Impressao* criarImpressao(NoUsuario* usuario, int numPaginas); //cria uma nova impressao e aloca memoria
int colocarEmFila(Impressao* impressao, NoFila* primeiro, NoFila* ultimo); //coloca a impressão dentro da fila
int realizarImpressao(NoHistorico* historico, NoFila* primeiro, NoFila* ultimo); //realiza o deque e faz push no historico
Impressao* retirarDoHistorico(NoHistorico* historico); //realiza o pop retirando a impressao do historico
#endif