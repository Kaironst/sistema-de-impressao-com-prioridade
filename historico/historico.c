#include "historico.h"
#include "../impressao/impressao.h"
#include <stdio.h>
#include <stdlib.h>

// Autor: Pedro Novak Wosch
NoHistorico* iniNoHistorico() {
    NoHistorico* header = (NoHistorico*)malloc(sizeof(NoHistorico));
    header->proximo = NULL;
    return header;
}

// Autor: Pedro Novak Wosch
int pushHistorico(NoHistorico* header, Impressao* impressao) {
    NoHistorico* novo = (NoHistorico*)malloc(sizeof(NoHistorico));
    novo->impressao=impressao;
    novo->proximo=header->proximo;
    header->proximo=novo;
}

// Autor: Pedro Novak Wosch
Impressao* popHistorico(NoHistorico* header) {
    if (header->proximo==NULL) return NULL;

    NoHistorico* aux = header->proximo;
    header->proximo = aux->proximo;
    Impressao* impressao = aux->impressao;
    free(aux);
    return impressao;
}

// Autor: Pedro Novak Wosch
Impressao* peek(NoHistorico* header) {
    return header->proximo->impressao;
}

// Autor: Pedro Novak Wosch
void printHistorico(NoHistorico* header) {
    NoHistorico* aux = header->proximo;
    printf("proximo -->");
    while (aux!=NULL) {
        printf("%s NumeroFolhas:%d \n",aux->impressao->usuario->nome,aux->impressao->numPaginas);
        aux=aux->proximo;
    }
}

// Autor: Bruno Kussen
void freeHistorico(NoHistorico* header) {
    NoHistorico* atual = header->proximo;
    while (atual != NULL) {
        NoHistorico* temp = atual;
        atual = atual->proximo;
        free(temp->impressao);
        free(temp);
    }
    free(header);
}