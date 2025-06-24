#include "../impressao/impressao.h"
#ifndef HISTORICO_H
#define HISTORICO_H

typedef struct NOHISTORICO  {
    Impressao* impressao;
    struct NOHISTORICO *proximo;
} NoHistorico;

NoHistorico* iniNoHistorico();
int pushHistorico(NoHistorico* primeiro, Impressao* impressao);
Impressao* popHistorico(NoHistorico* primeiro);
Impressao* peek(NoHistorico* primeiro);
void printHistorico(NoHistorico* primeiro);
void freeHistorico(NoHistorico* primeiro);

#endif