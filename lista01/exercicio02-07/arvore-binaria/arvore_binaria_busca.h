#ifndef ARVORE_BINARIA_BUSCA_H
#define ARVORE_BINARIA_BUSCA_H

typedef int tno;

typedef struct _tnoe{
    tno chave;
    struct _tnoe *esq, *dir;
} tnoe;  

void criar_raiz(tnoe **raiz);
tnoe* cria_no(tno chave);
int arvore_vazia(tnoe *arv);
int inserir(tnoe **arv, tno valor);
int remover(tnoe *raiz, tnoe **no, tno chave);
#endif