#include "historico.h"
#include "../impressao/impressao.h"
#include <stdio.h>
#include <stdlib.h>

// Autor: Pedro Novak Wosch
NoHistorico* iniNoHistorico() {
    return NULL;
}

// Autor: Pedro Novak Wosch
int pushHistorico(NoHistorico* primeiro, Impressao* impressao) {
    NoHistorico* novo = (NoHistorico*)malloc(sizeof(NoHistorico));
    novo->impressao=impressao;
    
    if (primeiro==NULL) {
        primeiro=novo;
        return 0;
    }
    novo->proximo=primeiro;
    primeiro=novo;
}

// Autor: Pedro Novak Wosch
Impressao* popHistorico(NoHistorico* primeiro) {
    if (primeiro==NULL) return NULL;

    NoHistorico* aux = primeiro;
    primeiro = primeiro->proximo;
    Impressao* impressao = aux->impressao;
    free(aux);
    return impressao;
}

// Autor: Pedro Novak Wosch
Impressao* peek(NoHistorico* primeiro) {
    return primeiro->impressao;
}

// Autor: Pedro Novak Wosch
void printHistorico(NoHistorico* primeiro) {
    NoHistorico* aux = primeiro;
    printf("proximo -->");
    while (aux!=NULL) {
        printf("%s NumeroFolhas:%d \n",aux->impressao->usuario->nome);
        aux=aux->proximo;
    }
}
