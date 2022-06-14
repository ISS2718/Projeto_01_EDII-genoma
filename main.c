#define TAM 1000
#include "intervalos.h"
#include "ctrl_F.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(void) {
  long n_frag = ctrlF ("projeto_1_dados/genoma_pequeno.txt", "projeto_1_dados/fragmentos_pequeno.txt", "projeto_1_dados/pos_fragmentos.txt");
  printf("n_frag: %ld\n", n_frag);
  system("pause");
  contagemIntersecoes("projeto_1_dados/pos_genes_grande.csv", "projeto_1_dados/pos_fragmentos.txt", TAM, n_frag);
    /*FILE* pos_genes = fopen("projeto_1_dados/pos_genes_pequeno.csv", "r");
    char linha[1024];
    int n = TAM;
    lista *l = malloc(sizeof(lista));
    criar(l,n);
    char *num2 = calloc(100,sizeof(char));
    char *num2_original = num2;
    for(int i=0; i<n; i++){
        fgets(linha, 1024, pos_genes);
        long inicio = strtol(linha, &num2,10);
        num2[0] = ' ';
        long fim = strtol(num2, &num2,10);
        l->intervalo[i][0] = inicio;
        l->intervalo[i][1] = fim;        
        //printf("%d %d\n", l->intervalo[i][0], l->intervalo[i][1]);
    }
  free(num2_original);
    l->intervalo = ordenaNumeros(l->intervalo, n);
    for(int i=0; i<n; i++){
        //printf("%ld %ld\n", l->intervalo[i][0], l->intervalo[i][1]);
    }
  destruir(l,n);
  fclose(pos_genes);*/
}
