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

void contagemIntersecoes(char* arquivo_A, char* arquivo_B, long nA, long nB){
    //recebe A.txt e B.txt nao ordenados
    // recebe numero de linhas de A e de B (na, nb)
    long inicio;
    long fim;

    long *contagens = calloc(nA, sizeof(long));
    
    FILE* fA = fopen(arquivo_A, "r");
    lista *A = malloc(sizeof(lista));
    criar(A, nA);

    FILE* fB = fopen(arquivo_B, "r");
    lista *B = malloc(sizeof(lista));
    criar(B, nB);


    for(int i = 0; i<nA; i++){
        fscanf(fA,"%ld,%ld", &(A->intervalo[i][0]), &(A->intervalo[i][1]));
        //ler uma linha de A.txt determinando inicio e fim do intervalo
        //A[i][0] = inicio;
        //A[i][1] = fim;
    }
    for(int i = 0; i<nB; i++){
        fscanf(fB,"%ld,%ld", &(B->intervalo[i][0]), &(B->intervalo[i][1]));
        //ler uma linha de A.txt determinando inicio e fim do intervalo
        //A[i][0] = inicio;
        //A[i][1] = fim;
    }
    fclose(fA);

    A->intervalo = ordenaNumeros(A->intervalo, nA);
    B->intervalo = ordenaNumeros(B->intervalo, nB);

    /*for(int i=0; i<nA; i++){
        printf("%ld %ld\n", A->intervalo[i][0], A->intervalo[i][1]);
    }
    for(int i=0; i<nB; i++){
        printf("%ld %ld\n", B->intervalo[i][0], B->intervalo[i][1]);
    }*/

    long primeiro_iB = 0;
    for (long iA = 0; iA < nA; iA++){
        for(long iB = primeiro_iB; iB < nB; iB++){
            if(A->intervalo[iA][1] < B->intervalo[iB][0] || A->intervalo[iA][0] > B->intervalo[iB][1]){
                if(contagens[iA] == 0){
                    primeiro_iB = iB;
                    contagens[iA]++;
                }
                else{
                    contagens[iA]++;
                }
            }
        }
    }

    FILE *file;
    file = fopen("contagens.txt", "w");

    for(int i = 0; i < nA; i++){
        fprintf(file, "%ld", contagens[i]); 
        //escreve contagens[i] em contagens.txt;
    }
    fclose(file);
}