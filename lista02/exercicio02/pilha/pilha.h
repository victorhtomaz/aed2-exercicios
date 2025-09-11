#ifndef PILHA_H
#define PILHA_H

#define MAX_PILHA 100

typedef char tpilha;

typedef struct _pilha{
    tpilha itens[MAX_PILHA];
    int indice_topo;
} pilha;

void cria_pilha(pilha *p);
int pilha_vazia(pilha *p);
int empilhar(pilha *p, tpilha item);
tpilha desempilhar(pilha *p);
tpilha pega_topo(pilha *p);

#endif