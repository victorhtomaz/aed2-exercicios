#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void cria_pilha(pilha *p){
    p->indice_topo = -1;
}

int pilha_vazia(pilha *p){
    return p->indice_topo == -1;
}

int empilhar(pilha *p, tpilha item){
    if (p->indice_topo < MAX_PILHA - 1) {
        p->indice_topo++;
        p->itens[p->indice_topo] = item;
        return 1;
    }
    return 0;
}

tpilha desempilhar(pilha *p){
    if (pilha_vazia(p))
        return '\0';

    return p->itens[p->indice_topo--];
}

tpilha pega_topo(pilha *p){
    if (pilha_vazia(p))
        return '\0';
        
    return p->itens[p->indice_topo];
}