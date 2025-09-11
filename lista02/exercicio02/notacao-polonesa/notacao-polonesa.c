#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../pilha/pilha.h"

int e_operador(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int prioridade(char c){
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
}

void ncentral_para_npolonesa_posfixa(char *expressao_infixa, char *expressao_posfixa){
    char aux;
    int i, j, tamanho;
    pilha pilha;
    
    cria_pilha(&pilha);

    j = 0;
    tamanho = strlen(expressao_infixa);
    
    for (i = 0; i < tamanho; i++){
        aux = expressao_infixa[i];

        if (isalpha(aux)){
            expressao_posfixa[j++] = aux;
            expressao_posfixa[j++] = ' ';
        }
        else if (isdigit(aux)){
            while (i < tamanho && isdigit(expressao_infixa[i])) {
                expressao_posfixa[j++] = expressao_infixa[i++];
            }

            i--;
            expressao_posfixa[j++] = ' ';
        }
        else if (aux == '(')
            empilhar(&pilha, aux);
        else if (aux == ')'){
            while (!pilha_vazia(&pilha) && pega_topo(&pilha) != '('){
                expressao_posfixa[j++] = desempilhar(&pilha);
                expressao_posfixa[j++] = ' ';
            }

            if (!pilha_vazia(&pilha))
                desempilhar(&pilha);
        }
        else if (e_operador(aux)){
            while (!pilha_vazia(&pilha) && pega_topo(&pilha) != '(' && prioridade(aux) <= prioridade(pega_topo(&pilha))) {
                expressao_posfixa[j++] = desempilhar(&pilha);
                expressao_posfixa[j++] = ' ';
            }
            
            empilhar(&pilha, aux);
        }
    }

    while (!pilha_vazia(&pilha)){
        expressao_posfixa[j++] = desempilhar(&pilha);
        expressao_posfixa[j++] = ' ';
    }
    
    expressao_posfixa[j - 1] = '\0';
}
