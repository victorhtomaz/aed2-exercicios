#ifndef OPERACOES_ARVORE_H
#define OPERACOES_ARVORE_H
#include "../arvore-binaria/arvore_binaria_busca.h"

int contar_folhas(tnoe *no);
int contar_maiores_chave(tnoe *no, tno chave);
void percorrer_pre(tnoe *no);
void percorrer_in(tnoe *no);
void percorrer_pos(tnoe *no);
int altura_no(tnoe *no, tno chave);
int contar_nos_um_filho(tnoe *no);

#endif