#include "../impressao/impressao.h"
#include "../historico/historico.h"
#include "../fila/fila.h"
#include <stdio.h>
#include <stdlib.h>


// Autor: Bruno Kussen
// Cria uma nova impressão e aloca memória
Impressao* criarImpressao(NoUsuario* usuario, int numPaginas) {
    Impressao* nova = (Impressao*)malloc(sizeof(Impressao));
    nova->usuario = usuario;
    nova->numPaginas = numPaginas;
    return nova;
}

// Autor: Bruno Kussen
// Coloca a impressão na fila
int colocarEmFila(Impressao* impressao, FilaImpressao* fila) {
    return enqueFila(fila, impressao);
}

// Autor: Bruno Kussen
// Remove da fila e adiciona no histórico
int realizarImpressao(NoHistorico* historico, FilaImpressao* fila) {
    Impressao* impressao = dequeFila(fila);
    if (!impressao) {
        printf("\nErro: Fila vazia.\n");
        return 0;
    }
    printf("\nImprimindo %d paginas para %s (CPF: %d).\n", impressao->numPaginas, impressao->usuario->nome, impressao->usuario->cpf);
    pushHistorico(historico, impressao);
    return 1;
}

// Autor: Bruno Kussen
// Retira a última impressão do histórico
Impressao* retirarDoHistorico(NoHistorico* historico) {
    return popHistorico(historico);
}
