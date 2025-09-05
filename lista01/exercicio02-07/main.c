#include <stdio.h>
#include <stdlib.h>
#include "arvore-binaria/arvore_binaria_busca.h"
#include "operacoes/operacoes_arvore.h"

int main(void);

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

    percorrer_pre(raiz);

    remover(raiz, &raiz, 12);
    printf("\n");
    percorrer_pre(raiz);
    printf("\n");

    printf("Quantidade de folhas: %d \n", contar_folhas(raiz));

    int chave_teste = 13;
    printf("Quantidade de chaves maiores que %d : %d \n", chave_teste, contar_maiores_chave(raiz, chave_teste));

    printf("Percusos da arvore: Pré-ordem, Em-ordem, Pós-Ordem \n");
    percorrer_pre(raiz);
    printf("\n");
    percorrer_in(raiz);
    printf("\n");
    percorrer_pos(raiz);
    printf("\n");

    chave_teste = 14;
    printf("A altura da chave %d : %d \n", chave_teste, altura_no(raiz, chave_teste));

    printf("A quantidade de nós com apenas um filho é: %d \n", contar_nos_um_filho(raiz));
}
