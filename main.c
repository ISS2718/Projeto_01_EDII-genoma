#define TAM 100
#include "intervalos.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    FILE* pos_genes = fopen("projeto_1_dados/pos_genes_pequeno.csv", "r");
    char linha[1024];
    int n = TAM;
    lista *l = malloc(sizeof(lista)); ;
    criar(l,n);
    char *num2 = calloc(100,sizeof(char));
    for(int i=0; i<n; i++){
        fgets(linha, 1024, pos_genes);
        long inicio = strtol(linha, &num2,10);
        num2[0] = ' ';
        long fim = strtol(num2, &num2,10);
        l->intervalo[i][0] = inicio;
        l->intervalo[i][1] = fim;        
        //printf("%d %d\n", l->intervalo[i][0], l->intervalo[i][1]);
    }
    l->intervalo = ordenaNumeros(l->intervalo, n);
    for(int i=0; i<n; i++){
        printf("%d %d\n", l->intervalo[i][0], l->intervalo[i][1]);
    }
}
