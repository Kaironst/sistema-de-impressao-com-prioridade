#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

NoFila* iniNoFila() { //retorna NULL ao NoFila;
return NULL;
}

int enque(NoFila* primeiro, NoFila* ultimo, NoUsuario* usuario, int numPaginas) {//coloca usuário na fila tomando conta para respeitar a prioridade
    NoFila* novo = (NoFila*)malloc(sizeof(NoFila));
    novo->usuario=usuario;
    novo->numPaginas=numPaginas;

    //caso esteja vazia
    if  (primeiro==NULL) {
        primeiro=novo;
        ultimo=novo;
        novo->anterior=NULL;
        novo->proximo=NULL;
    }

    //insere na traseira da fila caso o usuário seja da menor prioridade presente
    else if (novo->usuario->tipoUsuario <= ultimo->usuario->tipoUsuario) {
        ultimo->proximo = novo;
        novo->anterior = ultimo;
        novo->proximo = NULL;
        ultimo = novo;
    }

    //insere na frente da fila caso o usuaário seja da maior prioridade presente
    else if (novo->usuario->tipoUsuario >= primeiro->usuario->tipoUsuario) {
        primeiro->anterior = novo;
        novo->proximo = primeiro;
        novo->anterior = NULL;
        primeiro = novo;
    }
    
    //em outros casos
    else {
        NoFila* aux = ultimo->anterior;
        while (aux->usuario->tipoUsuario < novo->usuario->tipoUsuario)
            aux=aux->anterior;
        aux->proximo->anterior=novo;
        novo->proximo=aux->proximo;
        novo->anterior=aux;
        aux->proximo=novo;
    }
    

}

NoFila* deque(NoFila* primeiro, NoFila* Ultimo) {    //retorna a impressão da frente da fila e remove ela
    NoFila* aux = primeiro;
    primeiro = primeiro->proximo;
    primeiro->anterior = NULL;
    free(aux);
    aux = NULL; 
    return primeiro;
}
    
NoFila* peek(NoFila* primeiro, NoFila* Ultimo) {    //retorna a impressão da frente da fila
    return (primeiro);
}
