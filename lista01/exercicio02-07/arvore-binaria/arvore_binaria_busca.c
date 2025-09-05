#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria_busca.h"


void criar_raiz(tnoe **raiz){
    *raiz = NULL;
}

tnoe* cria_no(tno chave){
    tnoe *no;

    no = (tnoe*) malloc(sizeof(tnoe));
    if (no == NULL)
        exit(0);
    
    no->chave = chave;
    no->esq = NULL;
    no->dir = NULL;

    return no;
}

int arvore_vazia(tnoe *arv){
    return (arv == NULL);
}

int inserir(tnoe **no_atual, tno valor){
    // Aux = No que quero inserir, Aux2 No que estou verificando
    tnoe *aux;

    if (arvore_vazia(*no_atual)){
        *no_atual = cria_no(valor);
    }
    else{
        aux = *no_atual;

        if (valor == aux->chave)
            return -1;

        if (valor > aux->chave){
            if (aux->dir == NULL){
                aux->dir = cria_no(valor);
            }
            else{
                aux = aux->dir;
                inserir(&aux, valor);
            }
        }
        else{
            if (aux->esq == NULL){
                aux->esq = cria_no(valor);
            }
            else{
                aux = aux->esq;
                inserir(&aux, valor);
            }
        }
    }

    return 1;
}

int remover(tnoe *raiz, tnoe **no_atual, tno chave){
    tnoe *aux, *aux2, *sucessor, *ant_sucessor;

    aux = *no_atual;

    if (aux == NULL)
        return 0;
    else if (chave < aux->chave)
        remover(raiz, &(aux->esq), chave);
    else if (chave > aux->chave)
        remover(raiz, &(aux->dir), chave);
    else{
        // Apagar sem filhos
        if (aux->esq == NULL && aux->dir == NULL)
            *no_atual = NULL;
        // Apagar com um filho
        else if (aux->esq == NULL)
            *no_atual = aux->dir;
        else if (aux->dir == NULL)
            *no_atual = aux->esq;
        // Apagar com dois filhos
        else{
            ant_sucessor = aux;
            sucessor = aux->dir;

            while(sucessor->esq != NULL){
                ant_sucessor = sucessor;
                sucessor = sucessor->esq;
            }

            aux->chave = sucessor->chave;

            if (ant_sucessor == aux)
                ant_sucessor->dir = sucessor->dir;
            else
                ant_sucessor->esq = sucessor->dir;
        }
    }

    return 1;
}

void print_chave(tno chave){
    printf("%d", chave);
}