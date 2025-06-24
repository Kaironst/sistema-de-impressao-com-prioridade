#ifndef IMPRESSAO_H
#define IMPRESSAO_H

#include "../usuarios/usuarios.h"
#include "../fila/fila.h"

//structs externas
typedef struct NO_FILA NoFila;
typedef struct NOHISTORICO NoHistorico;

typedef struct IMPRESSAO {
    int numPaginas;
    NoUsuario* usuario;
} Impressao;


Impressao* criarImpressao(NoUsuario* usuario, int numPaginas);
int colocarEmFila(Impressao* impressao, FilaImpressao* fila);
int realizarImpressao(NoHistorico* historico, FilaImpressao* fila);
Impressao* retirarDoHistorico(NoHistorico* historico);

#endif