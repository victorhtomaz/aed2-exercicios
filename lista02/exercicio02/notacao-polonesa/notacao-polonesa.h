#ifndef NOTACAO_POLONESA_H
#define NOTACAO_POLONESA_H

int e_operador(char c);
int prioridade(char c);
void ncentral_para_npolonesa_posfixa(char *expressao_infixa, char *expressao_posfixa);

#endif