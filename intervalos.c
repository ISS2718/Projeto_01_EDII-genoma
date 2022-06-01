#include "intervalos.h"
#include <stdio.h>
#include <stdlib.h>

void criar(lista *l, long n) {
    l->intervalo = (long**)malloc(n*sizeof(long *));
    for(long j=0; j<n; j++){
        l->intervalo[j] = (long*)malloc(2*sizeof(long));
        l->intervalo[j][0] = 0;
        l->intervalo[j][1] = 0;
    }
}

void destruir(lista *l, int n) {
    for(long j=0; j<n; j++){
        free(l->intervalo[j]);
    }
    free(l->intervalo);
    free(l);
}

void insere_intervalos (lista *l, long tamanho_lista,  FILE* entrada) {
    char *linha = malloc(sizeof(char) * 1024);
    char *num2 = calloc(100,sizeof(char));
    char *num2_original = num2;
    for(int i=0; i<tamanho_lista; i++){
        fgets(linha, 1024, entrada);
        long inicio = strtol(linha, &num2,10);
        num2[0] = ' ';
        long fim = strtol(num2, &num2,10);
        l->intervalo[i][0] = inicio;
        l->intervalo[i][1] = fim;        
        //printf("%d %d\n", l->intervalo[i][0], l->intervalo[i][1]);
    }
  free(num2_original);
}

long ** ordenaDigitos(long **A, long n, long posicao){
    long B[10] = {0,0,0,0,0,0,0,0,0,0};
    //printf("Posicao: %d", posicao);
    for(long i=0; i<n; i++){
        int digito = A[i][0]/posicao;
        digito = digito%10;
        B[digito]++;
    }
    for(int i=1; i<=9; i++){
        //printf("Antes: B[%d]: %d --- ", i, B[i]);
        B[i] = B[i] + B[i-1];
        //printf("Depois: B[%d]: %d\n", i, B[i]);
    }
    lista *C = malloc(sizeof(lista));
    criar(C, n);
    for(long i=n-1; i>=0; i--){
        int digito = A[i][0]/posicao;
        digito = digito%10;
        //printf("digito: %d", digito);
        B[digito]--;
        //printf("B: %d", B[digito]);
        C->intervalo[B[digito]][0] = A[i][0];
        C->intervalo[B[digito]][1] = A[i][1];
    }
    for(long i=0; i<n; i++){
        A[i][0] = C->intervalo[i][0];
        A[i][1] = C->intervalo[i][1];
    }
    destruir(C,n);
    return A;
}

long ** ordenaNumeros(long **A, long n){
    long maior = -99999;
    for(long i=0; i<n; i++){
        if(A[i][0]> maior){
            maior = A[i][0];
        }
    }
    //printf("Maior: %ld\n", maior);
    long posicao = 1;
    while((maior/posicao) > 0){
        ordenaDigitos(A,n, posicao);
        posicao*=10;
    }
    return A;
}