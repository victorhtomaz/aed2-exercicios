#include <stdio.h>
#include <stdlib.h>
#include "arvore-binaria/arvore_binaria_busca.h"

void imprimir_pre_ordem(tnoe *raiz);
int main(void);

void imprimir_pre_ordem(tnoe *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        imprimir_pre_ordem(raiz->esq);
        imprimir_pre_ordem(raiz->dir);
    }
}

int main(void){
    tnoe *raiz;

    criar_raiz(&raiz);
    inserir(&raiz, 12);
    inserir(&raiz, 8);
    inserir(&raiz, 15);
    inserir(&raiz, 6);
    inserir(&raiz, 10);
    inserir(&raiz, 13);
    inserir(&raiz, 18);
    inserir(&raiz, 14);

    imprimir_pre_ordem(raiz);

    remover(raiz, &raiz, 12);
    printf("\n");
    imprimir_pre_ordem(raiz);
}
