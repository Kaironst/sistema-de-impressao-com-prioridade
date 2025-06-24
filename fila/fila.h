#include "../impressao/impressao.h"
#ifndef FILA_IMPRESSAO_H
#define FILA_IMPRESSAO_H

typedef struct NO_FILA {
struct IMPRESSAO* impressao;
struct NO_FILA *proximo, *anterior;
} NoFila;

typedef struct FILA_IMPRESSAO {
    NoFila* primeiro;
    NoFila* ultimo;
} FilaImpressao;

FilaImpressao* iniFila();
NoFila* iniNoFila();     //retorna NULL ao NoFila;
int enqueFila(FilaImpressao* fila, struct IMPRESSAO* impressao);    //coloca usuário na fila tomando conta para respeitar a prioridade
struct IMPRESSAO* dequeFila(FilaImpressao* fila);        //retorna a impressão da frente da fila e remove ela
struct IMPRESSAO* peekFila(FilaImpressao* fila);     //retorna a impressão da frente da fila
struct IMPRESSAO* buscaFila(FilaImpressao* fila, struct IMPRESSAO* impressao);
void printFila(FilaImpressao* fila);
void freeFila(FilaImpressao* fila);



#endif