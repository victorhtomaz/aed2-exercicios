#include <stdio.h>
#include <stdlib.h>
#include "notacao-polonesa/notacao-polonesa.h"
#include "arvore-expressao/arvore.h"

int main(void) {
    char expressao_infixa[100] = "(A+B)*2";
    char expressao_posfixa[100];
    tnoe *arvore = NULL;

    ncentral_para_npolonesa_posfixa(expressao_infixa, expressao_posfixa);

    cria_arvore_expressao(&arvore, expressao_posfixa);

    percorrer_npolonesa(arvore);
    printf("\n");
    percorrer_ncetral(arvore);
    printf("\n");
    percorrer_npolonesa_reversa(arvore);
    printf("\n");

    return 0;
}