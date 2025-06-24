
#ifndef FILA_IMPRESSAO_H
#define FILA_IMPRESSAO_H

typedef struct NO_FILA {
Impressao* impressao;
struct NO_FILA *proximo, *anterior;
} NoFila;

NoFila* iniNoFila();     //retorna NULL ao NoFila;
int enqueFila(NoFila* primeiro, NoFila* ultimo, Impressao* impressao);    //coloca usuário na fila tomando conta para respeitar a prioridade
Impressao* dequeFila(NoFila* primeiro, NoFila* Ultimo);        //retorna a impressão da frente da fila e remove ela
Impressao* peekFila(NoFila* primeiro, NoFila* Ultimo);     //retorna a impressão da frente da fila
Impressao* buscaFila(NoFila* primeiro, NoFila* Ultimo, Impressao* impressao);
void printFila(NoFila* primeiro, NoFila* ultimo);




#endif