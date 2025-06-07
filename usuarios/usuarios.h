#ifndef LISTA_USUARIOS
#define LISTA_USUARIOS

typedef enum {
ESTUDANTE=1,
PROFESSOR=2,
ADMINISTRACAO=3,
DIRECAO=3
} tipoUsuario;

//TODO alterar a estrutura e função usuario para cumprir os requisitos marcados pelo professor
typedef struct NO_USUARIO {
    char* nome;
    int cpf;
    tipoUsuario tipoUsuario;
    struct NO_USUARIO* proximo;
    struct NO_USUARIO* anterior;
}NoUsuario;     //implementação da lista duplamente encadeada com cabeçalho

NoUsuario* iniListaUsuario();   //cria lista
int addUsuario(NoUsuario* header, char* nome, int cpf, tipoUsuario tipoUsuario);
int rmUsuario(NoUsuario* no); //remove usuario da lista
NoUsuario* getUsuario(NoUsuario* header, char* nome);       //procura usuario por nome
NoUsuario* getUsuarioCpf(NoUsuario* header, int cpf);       //procura usuario por cpf
int freeListaUsuario(NoUsuario* header);        //libera a lista

#endif