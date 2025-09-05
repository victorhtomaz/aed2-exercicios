#include <stdio.h>
#include <stdlib.h>
#include "../arvore-binaria/arvore_binaria_busca.h"

int contar_folhas(tnoe *no){
    if (no == NULL)
        return 0;

    if (no->esq == NULL && no->dir == NULL)
        return 1;

    return contar_folhas(no->esq) + contar_folhas(no->dir);
}

int contar_maiores_chave(tnoe *no, tno chave){
    if (no == NULL)
        return 0;

    if (no->chave <= chave)
        return contar_maiores_chave(no->dir, chave);
    else
        return 1 + contar_maiores_chave(no->esq, chave) + contar_maiores_chave(no->dir, chave);
}

void percorrer_pre(tnoe *no){
    if (no == NULL)
        return;

    print_chave(no->chave);
    printf("; ");
    percorrer_pre(no->esq);
    percorrer_pre(no->dir);
}

void percorrer_in(tnoe *no){
    if (no == NULL)
        return;

    percorrer_in(no->esq);
    print_chave(no->chave);
    printf("; ");
    percorrer_in(no->dir);
}

void percorrer_pos(tnoe *no){
    if (no == NULL)
        return;
    
    percorrer_pos(no->esq);
    percorrer_pos(no->dir);
    print_chave(no->chave);
    printf("; ");
}

int altura_no(tnoe *no,tno chave){
    int altura;
    if (no == NULL)
        return -1;

    if (no->chave == chave)
        return 0;
    
    if (no->chave < chave){
        altura = altura_no(no->dir, chave);
        if (altura == -1)
            return altura;
        else
            return altura + 1;
    }
    else{
        altura = altura_no(no->esq, chave);
        if (altura == -1)
            return altura;
        else
            return altura + 1;
    }
}

int contar_nos_um_filho(tnoe *no){
    if (no == NULL)
        return 0;

    if ((no->esq == NULL && no->dir != NULL) || no->dir == NULL && no->esq != NULL){
        return 1 + contar_nos_um_filho(no->esq) + contar_nos_um_filho(no->dir);
    }
    else
        return contar_nos_um_filho(no->esq) + contar_nos_um_filho(no->dir);
}