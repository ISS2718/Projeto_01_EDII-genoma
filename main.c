#define TAM 10000
#include "intervalos.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  FILE* A_file = fopen("projeto_1_dados/A.csv", "r");
  FILE* B_file = fopen("projeto_1_dados/B.csv", "r");
  lista *A = malloc(sizeof(lista));
  lista *B = malloc(sizeof(lista));
  
  criar(A,TAM);
  criar(B, TAM);

  insere_intervalos(A, TAM, A_file);
  insere_intervalos(B, TAM, B_file);
  
  A->intervalo = ordenaNumeros(A->intervalo, TAM);
  B->intervalo = ordenaNumeros(B->intervalo, TAM);
  for(int i=0; i<TAM; i++){
    printf("%ld %ld\n", A->intervalo[i][0], A->intervalo[i][1]);
  }

  for(int i=0; i<TAM; i++){
    printf("%ld %ld\n", B->intervalo[i][0], B->intervalo[i][1]);
  }
  destruir(A,TAM);
  destruir(B,TAM);
  fclose(A_file);
  fclose(B_file);
}
