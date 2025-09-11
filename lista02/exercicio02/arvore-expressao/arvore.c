#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arvore.h"
#include "../notacao-polonesa/notacao-polonesa.h"

void cria_pilha_no(pilha_no *p){
    p->indice_topo = -1;
}

int pilha_vazia_no(pilha_no *p){
    return p->indice_topo == -1;
}

tnoe* cria_no(tno chave){
    tnoe *novo_no = (tnoe*) malloc(sizeof(tnoe));
    novo_no->esq = NULL;
    novo_no->dir = NULL;

    novo_no->chave = (char*) malloc(strlen(chave) + 1);
    strcpy(novo_no->chave, chave);

    return novo_no;
}

int empilhar_no(pilha_no *p, tnoe* item){
    if (p->indice_topo < MAX_PILHA_NO - 1) {
        p->indice_topo++;
        p->itens[p->indice_topo] = item;
        return 1;
    }
    return 0;
}

tnoe* desempilhar_no(pilha_no *p){
    if (pilha_vazia_no(p))
            return NULL;

    return p->itens[p->indice_topo--];
}

void cria_arvore_expressao(tnoe **raiz, char* expressao_polonesa_posfixa){
    int i = 0;
    tnoe *novo_no;
    pilha_no pilha;
    char aux_str[20];
    char aux_str_2[2];

    if (*raiz != NULL)
        return;

    cria_pilha_no(&pilha);

    while (expressao_polonesa_posfixa[i] != '\0'){
        char aux = expressao_polonesa_posfixa[i];

        if (isblank(aux)) {
            i++;
            continue;
        }

        if (isdigit(aux)){
            int j = 0;

            while (isdigit(expressao_polonesa_posfixa[i])) {
                aux_str[j++] = expressao_polonesa_posfixa[i++];
            }
            aux_str[j] = '\0';
            i--;
            novo_no = cria_no(aux_str);

            empilhar_no(&pilha, novo_no);
        }
        else if (isalpha(aux)){
            aux_str_2[0] = aux;
            aux_str_2[1] = '\0';
            novo_no = cria_no(aux_str_2);

            empilhar_no(&pilha, novo_no);
        }
        else if (e_operador(aux)){
            aux_str_2[0] = aux;
            aux_str_2[1] = '\0';
            novo_no = cria_no(aux_str_2);

            novo_no->dir = desempilhar_no(&pilha);
            novo_no->esq = desempilhar_no(&pilha);

            empilhar_no(&pilha, novo_no);
        }
        i++;
    }
    *raiz = desempilhar_no(&pilha);
}

void print_chave(tno chave){
    printf("%s", chave);
}

void percorrer_npolonesa(tnoe *no){
    if (no == NULL)
        return;

    print_chave(no->chave);
    printf(" ");
    percorrer_npolonesa(no->esq);
    percorrer_npolonesa(no->dir);
}

void percorrer_ncetral(tnoe *no){
    if (no == NULL)
        return;

    percorrer_ncetral(no->esq);
    print_chave(no->chave);
    printf(" ");
    percorrer_ncetral(no->dir);
}

void percorrer_npolonesa_reversa(tnoe *no){
    if (no == NULL)
        return;
    
    percorrer_npolonesa_reversa(no->esq);
    percorrer_npolonesa_reversa(no->dir);
    print_chave(no->chave);
    printf(" ");
}