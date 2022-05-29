#include "contagemInterseccoes.h"
#include <stdio.h>
#include <stdlib.h>

void contagemInterseccoes (lista A, long nA, lista B, long nB) {
    long primeiro_iB = 0;

    //cria/abre arquivo de saida
    FILE* saida = fopen ("./contagem.txt", "w");
    if (saida == NULL) {
        exit(-1); //erro de abertura/criacao de arquivo
    }

    //cria e inicia contagem com zeros
    long* contagem = malloc(sizeof(long) * nA);
    if (contagem != NULL) {
        for (long i = 0; i < nA; i++) {
            contagem[i] = 0;
        }
    } else {
        exit(-1); //erro de alocacao de memoria
    }

    //verifica interseccoes entre A e B
    for (long iA = 0; iA < nA; iA++) {
        for (long iB = primeiro_iB; iB < nB; iB++) {
            if (A.intervalo[iA][1] < B.intervalo[iB][0] || A.intervalo[iA][0] > B.intervalo[iB][1]) {
                if (contagem[iA] == 0) {
                    primeiro_iB = iB;
                }
            } else {
                contagem[iA]++; 
            }
        }
    }

    for (long i = 0; i < nA; i++) {
        fprintf(saida, "%li", contagem[i]);
    }
}