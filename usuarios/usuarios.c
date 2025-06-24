#include "usuarios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Autor: Pedro Novak Wosch
NoUsuario* iniListaUsuario() {
    NoUsuario* header=(NoUsuario*)malloc(sizeof(NoUsuario));
    header->nome="";
    header->cpf=0;
    header->tipoUsuario=ESTUDANTE;
    header->proximo=NULL;
    header->anterior=NULL;
    return header;
}

// Autor: Pedro Novak Wosch
int addUsuario(NoUsuario* header, char* nome, int cpf, tipoUsuario tipoUsuario) {
    NoUsuario* novo=(NoUsuario*)malloc(sizeof(NoUsuario));
    novo->nome=nome;
    novo->cpf=cpf;
    novo->tipoUsuario=tipoUsuario;
    novo->proximo=header->proximo;
    header->proximo=novo;
    if (novo->proximo!=NULL)
        novo->proximo->anterior=novo;
    return 1;
}

// Autor: Pedro Novak Wosch
int rmUsuario(NoUsuario* no) {
    if (no==NULL || no->anterior==NULL) return 0;     // nó não encontrado
    free(no->nome);
    no->proximo->anterior=no->anterior;
    no->anterior->proximo=no->proximo;
    free(no);
    no=NULL;
    return 1;
}

// Autor: Pedro Novak Wosch
NoUsuario* getUsuario(NoUsuario* header, char* nome) {
    NoUsuario* atual=header->proximo;
    while( atual!=NULL && strcmp(atual->nome,nome)!=0 ) {
        atual=atual->proximo;
    }
    return atual;
}

// Autor: Pedro Novak Wosch
NoUsuario* getUsuarioCpf(NoUsuario* header, int cpf) {
    NoUsuario* atual=header->proximo;
    while(atual!=NULL && atual->cpf!=cpf) {
        atual=atual->proximo;
    }
    return atual;
}

// Autor: Pedro Novak Wosch
int freeListaUsuario(NoUsuario* header) {
    while(rmUsuario(header->proximo));
    free(header);
    header=NULL;
    return 1;
}