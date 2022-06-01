#ifndef __INTERVALOS__
#define __INTERVALOS__

#include <stdio.h>

typedef struct {
    long *inicio;
    long *fim;
} elem;

typedef struct {
    long **intervalo;
} lista;

void criar(lista *l, long n);
void destruir(lista *l, int n);
void insere_intervalos (lista *l, long tamanho_lista,  FILE* entrada);
long ** ordenaDigitos(long **A, long n, long posicao);
long ** ordenaNumeros(long **A, long n);

#endif