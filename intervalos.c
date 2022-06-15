#include "intervalos.h"
#include <stdio.h>
#include <stdlib.h>

void criar(lista *l, long n) {
    // Instancia uma lista de intervalos com n elementos
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

void inserir_arquivo(lista *l, int n, FILE * arquivo){
    // Lê todas as linhas de um arquivo e preenche uma lista de intervalos
    for(int i = 0; i<n; i++){
        fscanf(arquivo,"%ld,%ld", &(l->intervalo[i][0]), &(l->intervalo[i][1]));
    }
}

long ** ordenaDigitos(long **A, long n, long posicao){
    long B[10] = {0,0,0,0,0,0,0,0,0,0};
    
    // Conta quantos algarismos de cada tipo existem na posição analisada e armazena no vetor B
    // na posição correspondente ao tipo
    for(long i=0; i<n; i++){
        int digito = A[i][0]/posicao;
        digito = digito%10;
        B[digito]++;
    }

    //Soma quantidade de elementos do tipo com a quantidade de todos os tipos anteriores
    // B[i] passa a armazenar a posição + 1 do ultimo elemento do tipo i no vetor ordenado
    for(int i=1; i<=9; i++){
        B[i] = B[i] + B[i-1];
    }

    // Usa as posições indicadas por B para colocar elementos na posição correta no vetor C
    lista *C = malloc(sizeof(lista));
    criar(C, n);
    for(long i=n-1; i>=0; i--){
        int digito = A[i][0]/posicao;
        digito = digito%10;
        B[digito]--;
        C->intervalo[B[digito]][0] = A[i][0];
        C->intervalo[B[digito]][1] = A[i][1];
    }

    //Sobrescreve vetor ordenado C no vetor A
    for(long i=0; i<n; i++){
        A[i][0] = C->intervalo[i][0];
        A[i][1] = C->intervalo[i][1];
    }
    destruir(C,n);
    return A;
}

long ** ordenaNumeros(long **A, long n){
    long maior = -99999;
    
    //Encontra maior para saber quantas posição precisam ser analisadas
    for(long i=0; i<n; i++){
        if(A[i][0]> maior){
            maior = A[i][0];
        }
    }

    long posicao = 1; // posição menos significativa

    //Ordena os números em relação à todas as posições começando da menos significativa
    while((maior/posicao) > 0){
        ordenaDigitos(A,n, posicao);
        posicao*=10;
    }
    return A;
}

void contagemIntersecoes(char* arquivo_A, char* arquivo_B, long nA, long nB, char* arquivo_saida){
    //recebe A.txt e B.txt nao ordenados
    // recebe numero de linhas de A e de B (na, nb)
    long inicio;
    long fim;

    long *contagens = calloc(nA, sizeof(long));
    
    FILE* fA = fopen(arquivo_A, "r");
    lista *A = malloc(sizeof(lista));
    criar(A, nA);
    inserir_arquivo(A, nA, fA);
    FILE* fB = fopen(arquivo_B, "r");
    lista *B = malloc(sizeof(lista));
    criar(B, nB);
    inserir_arquivo(B, nB, fB);
    fclose(fA);
    fclose(fB);

    A->intervalo = ordenaNumeros(A->intervalo, nA);
    B->intervalo = ordenaNumeros(B->intervalo, nB);

    long primeiro_iB = 0;
    for (long iA = 0; iA < nA; iA++){
        for(long iB = primeiro_iB; iB < nB; iB++){
            if(A->intervalo[iA][1] < B->intervalo[iB][0] || A->intervalo[iA][0] > B->intervalo[iB][1]){
                if(contagens[iA] == 0){
                    primeiro_iB = iB;
                }
            } else {
                    contagens[iA]++;
            }
        }
    }

    FILE *file;
    file = fopen(arquivo_saida, "w");

    for(int i = 0; i < nA; i++){
        fprintf(file, "%ld\n", contagens[i]); 
        //escreve contagens[i] em contagens.txt;
    }
    fclose(file);
    free(A);
    free(B);
    free(contagens);
}