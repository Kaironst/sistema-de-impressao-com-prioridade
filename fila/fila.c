#include "fila.h"
#include "../impressao/impressao.h"
#include <stdlib.h>
#include <stdio.h>

// Autor: Pedro Novak Wosch
NoFila* iniNoFila() { //retorna NULL ao NoFila;
return NULL;
}

// Autor: Pedro Novak Wosch
int enqueFila(NoFila* primeiro, NoFila* ultimo, Impressao* impressao) { //coloca usuário na fila tomando conta para respeitar a prioridade
    NoFila* novo = (NoFila*)malloc(sizeof(NoFila));
    novo->impressao=impressao;

    //caso esteja vazia
    if  (primeiro==NULL) {
        primeiro=novo;
        ultimo=novo;
        novo->anterior=NULL;
        novo->proximo=NULL;
    }

    //insere na traseira da fila caso o usuário seja da menor prioridade presente
    else if (novo->impressao->usuario->tipoUsuario <= ultimo->impressao->usuario->tipoUsuario) {
        ultimo->proximo = novo;
        novo->anterior = ultimo;
        novo->proximo = NULL;
        ultimo = novo;
    }

    //insere na frente da fila caso o usuaário seja da maior prioridade presente
    else if (novo->impressao->usuario->tipoUsuario > primeiro->impressao->usuario->tipoUsuario) {
        primeiro->anterior = novo;
        novo->proximo = primeiro;
        novo->anterior = NULL;
        primeiro = novo;
    }
    
    //em outros casos
    else {
        NoFila* aux = ultimo->anterior;
        while (aux->impressao->usuario->tipoUsuario < novo->impressao->usuario->tipoUsuario)
            aux=aux->anterior;
        aux->proximo->anterior=novo;
        novo->proximo=aux->proximo;
        novo->anterior=aux;
        aux->proximo=novo;
    }
    

}

// Autor: Pedro Novak Wosch
Impressao* dequeFila(NoFila* primeiro, NoFila* Ultimo) { // retorna a impressão da frente da fila e remove ela
    NoFila* aux = primeiro;
    primeiro = primeiro->proximo;
    primeiro->anterior = NULL;
    Impressao* impressao = aux->impressao;
    free(aux);
    aux = NULL; 
    return impressao;
}

// Autor: Pedro Novak Wosch
Impressao* peekFila(NoFila* primeiro, NoFila* Ultimo) { //retorna a impressão da frente da fila
    return primeiro->impressao;
}

// Autor: Pedro Novak Wosch
Impressao* buscaFila(NoFila* primeiro, NoFila* Ultimo, Impressao* impressao) {
    NoFila* aux = primeiro;
    while(aux!=NULL && aux->impressao!=impressao) {
        aux=aux->proximo;
    }
    return aux->impressao;
}

// Autor: Pedro Novak Wosch
void printFila(NoFila* primeiro, NoFila* ultimo) {
    printf("proximo --> ");
    NoFila* aux = primeiro;
    while(aux!=NULL) {
        printf("%s NumeroFolhas:%d \n",aux->impressao->usuario->nome);
        aux=aux->proximo;
    }
}
