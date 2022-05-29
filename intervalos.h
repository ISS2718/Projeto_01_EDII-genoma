#ifndef __INTERVALOS__
#define __INTERVALOS__

typedef struct {
    long *inicio;
    long *fim;
} elem;

typedef struct {
    long **intervalo;
} lista;

void criar(lista *l, long n);
void destruir(lista *l, int n);
long ** ordenaDigitos(long **A, long n, long posicao);
long ** ordenaNumeros(long **A, long n);

#endif