#include "historico.h"
#include "../impressao/impressao.h"
#include <stdio.h>
#include <stdlib.h>

NoHistorico* iniNoHistorico() {
    return NULL;
}

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

Impressao* popHistorico(NoHistorico* primeiro) {
    if (primeiro==NULL) return NULL;

    NoHistorico* aux = primeiro;
    primeiro = primeiro->proximo;
    Impressao* impressao = aux->impressao;
    free(aux);
    return impressao;
}

Impressao* peek(NoHistorico* primeiro) {
    return primeiro->impressao;
}

void printHistorico(NoHistorico* primeiro) {
    NoHistorico* aux = primeiro;
    printf("proximo -->");
    while (aux!=NULL) {
        printf("%s NumeroFolhas:%d \n",aux->impressao->usuario->nome);
        aux=aux->proximo;
    }
}
