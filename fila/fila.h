#include "../usuarios/usuarios.h"
#ifndef FILA_IMPRESSAO
#define FILA_IMPRESSAO

typedef struct NO_FILA {
NoUsuario* usuario;
int numPaginas;
struct NO_FILA *proximo, *anterior;
} NoFila;

NoFila* iniNoFila();     //retorna NULL ao NoFila;
int enque(NoFila* primeiro, NoFila* ultimo, NoUsuario* usuario, int numPaginas);    //coloca usuário na fila tomando conta para respeitar a prioridade
NoFila* deque(NoFila* primeiro, NoFila* Ultimo);        //retorna a impressão da frente da fila e remove ela
NoFila* peek(NoFila* primeiro, NoFila* Ultimo);     //retorna a impressão da frente da fila




#endif