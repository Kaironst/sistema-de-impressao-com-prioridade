#include "../impressao/impressao.h"
#ifndef HISTORICO_H
#define HISTORICO_H

typedef struct NOHISTORICO  {
    Impressao* impressao;
    struct NOHISTORICO *proximo;
} NoHistorico; //pilha linkada (primeiro nó é cabeçalho)

NoHistorico* iniNoHistorico();
int pushHistorico(NoHistorico* header, Impressao* impressao);
Impressao* popHistorico(NoHistorico* header);
Impressao* peek(NoHistorico* header);
void printHistorico(NoHistorico* header);
void freeHistorico(NoHistorico* header);

#endif