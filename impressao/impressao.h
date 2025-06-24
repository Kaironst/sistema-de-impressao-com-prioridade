#ifndef IMPRESSAO_H
#define IMPRESSAO_H

#include "../usuarios/usuarios.h"

//structs externas
typedef struct NO_FILA NoFila;
typedef struct NOHISTORICO NoHistorico;

typedef struct IMPRESSAO {
    int numPaginas;
    NoUsuario* usuario;
} Impressao;


Impressao* criarImpressao(NoUsuario* usuario, int numPaginas);
int colocarEmFila(Impressao* impressao, NoFila* primeiro, NoFila* ultimo);
int realizarImpressao(NoHistorico* historico, NoFila* primeiro, NoFila* ultimo);
Impressao* retirarDoHistorico(NoHistorico* historico);

#endif