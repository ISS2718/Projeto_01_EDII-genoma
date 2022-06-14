#define TAM 100
#include "intervalos.h"
#include "ctrl_F.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(void) {
  /*long n_frag = ctrlF ("projeto_1_dados/genoma_pequeno.txt", "projeto_1_dados/fragmentos_pequeno.txt", "projeto_1_dados/pos_fragmentos.txt");
  printf("n_frag: %ld\n", n_frag);
  system("pause");
  contagemIntersecoes("projeto_1_dados/pos_genes_grande.csv", "projeto_1_dados/pos_fragmentos.txt", TAM, n_frag);
  */

  srand(clock());
    
    for (int i = 2; pow(10, i) <= TAM; i++) {
        clock_t ciclos_ini, soma_ciclos;
        soma_ciclos = 0;
        int repeticoes = 10;
        for (int j = 0; j < repeticoes; j++) {
            FILE* pos_genes = fopen("projeto_1_dados/pos_genes_pequeno.csv", "r");
            lista *l = malloc(sizeof(lista));
            long n = TAM;
            criar(l, n);
            inserir_arquivo(l, n, pos_genes);
            fclose(pos_genes);

            /*for(long i=0; i<n; i++){
                printf("%ld %ld\n", l->intervalo[i][0], l->intervalo[i][1]);
            }*/

            // guarda contagem previa de ciclos
            ciclos_ini = clock();
            
            l->intervalo = ordenaNumeros(l->intervalo, n);
            
            soma_ciclos += clock() - ciclos_ini;
            /*printf("Ordenado:\n");
            for(long i=0; i<n; i++){
                printf("%ld %ld\n", l->intervalo[i][0], l->intervalo[i][1]);
            }*/
            // destroi a lista
            destruir(l,n);
        }
        printf("Soma ciclos: %d\n", soma_ciclos);
        printf("Tempo (segundos): %.0lf, %.50lf\n", pow(10, i), (((double) soma_ciclos) / repeticoes) / CLOCKS_PER_SEC);
    }
}
