#include "fila.h"
#include "../impressao/impressao.h"
#include <stdlib.h>
#include <stdio.h>

// Autor: Pedro Novak Wosch
FilaImpressao* iniFila() {
    FilaImpressao* novo = (FilaImpressao*)malloc(sizeof(FilaImpressao));
    novo->primeiro=iniNoFila();
    novo->ultimo=iniNoFila();
    return novo;
}

// Autor: Pedro Novak Wosch
NoFila* iniNoFila() { //retorna NULL ao NoFila;
return NULL;
}

// Autor: Pedro Novak Wosch
int enqueFila(FilaImpressao* fila, Impressao* impressao) { //coloca usuário na fila tomando conta para respeitar a prioridade
    NoFila* novo = (NoFila*)malloc(sizeof(NoFila));
    novo->impressao=impressao;

    //caso esteja vazia
    if  (fila->primeiro==NULL) {
        fila->primeiro=novo;
        fila->ultimo=novo;
        novo->anterior=NULL;
        novo->proximo=NULL;
    }

    //insere na traseira da fila caso o usuário seja da menor prioridade presente
    else if (novo->impressao->usuario->tipoUsuario <= fila->ultimo->impressao->usuario->tipoUsuario) {
        fila->ultimo->proximo = novo;
        novo->anterior = fila->ultimo;
        novo->proximo = NULL;
        fila->ultimo = novo;
    }

    //insere na frente da fila caso o usuaário seja da maior prioridade presente
    else if (novo->impressao->usuario->tipoUsuario > fila->primeiro->impressao->usuario->tipoUsuario) {
        fila->primeiro->anterior = novo;
        novo->proximo = fila->primeiro;
        novo->anterior = NULL;
        fila->primeiro = novo;
    }
    
    //em outros casos
    else {
        NoFila* aux = fila->ultimo->anterior;
        while (aux->impressao->usuario->tipoUsuario < novo->impressao->usuario->tipoUsuario)
            aux=aux->anterior;
        aux->proximo->anterior=novo;
        novo->proximo=aux->proximo;
        novo->anterior=aux;
        aux->proximo=novo;
    }
    

}

// Autor: Pedro Novak Wosch
Impressao* dequeFila(FilaImpressao* fila) { // retorna a impressão da frente da fila e remove ela
    if (fila->primeiro==NULL) return NULL;
    if (fila->primeiro==fila->ultimo) fila->ultimo=NULL;
    NoFila* aux = fila->primeiro;
    fila->primeiro = fila->primeiro->proximo;
    Impressao* impressao = aux->impressao;
    free(aux);
    aux = NULL; 
    return impressao;
}

// Autor: Pedro Novak Wosch
Impressao* peekFila(FilaImpressao* fila) { //retorna a impressão da frente da fila
    if (fila->primeiro==NULL) return NULL;
    return fila->primeiro->impressao;
}

// Autor: Pedro Novak Wosch
Impressao* buscaFila(FilaImpressao* fila, Impressao* impressao) {
    if (fila->primeiro==NULL) return NULL;
    NoFila* aux = fila->primeiro;
    while(aux!=NULL && aux->impressao!=impressao) {
        aux=aux->proximo;
    }
    return aux->impressao;
}

// Autor: Pedro Novak Wosch
void printFila(FilaImpressao* fila) {
    printf("proximo --> ");
    NoFila* aux = fila->primeiro;
    while(aux!=NULL) {
        printf("%s NumeroFolhas:%d \n",aux->impressao->usuario->nome);
        aux=aux->proximo;
    }
}

// Autor: Bruno Kussen
void freeFila(FilaImpressao* fila) {
    NoFila* atual = fila->primeiro->proximo;
    while (atual != NULL) {
        NoFila* temp = atual;
        atual = atual->proximo;
        free(temp->impressao);
        free(temp);
    }
    free(fila->primeiro);
}
