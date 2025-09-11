#ifndef ARVORE_H
#define ARVORE_H

#define MAX_PILHA_NO 100

typedef char* tno;

typedef struct _tnoe{
    tno chave;
    struct _tnoe *esq, *dir;
} tnoe;

typedef struct _pilha_no{
    tnoe* itens[MAX_PILHA_NO];
    int indice_topo;
} pilha_no;

void cria_pilha_no(pilha_no *p);
int pilha_vazia_no(pilha_no *p);
tnoe* cria_no(tno chave);
int empilhar_no(pilha_no *p, tnoe* item);
tnoe* desempilhar_no(pilha_no *p);
void cria_arvore_expressao(tnoe **raiz, char* expressao_polonesa_posfixa);

void print_chave(tno chave);

void percorrer_npolonesa(tnoe *no);
void percorrer_ncetral(tnoe *no);
void percorrer_npolonesa_reversa(tnoe *no);
#endif