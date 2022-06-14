#define TAM 100
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
}
