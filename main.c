#define TAM 100
#include "genoma.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

  char* arquivo_genoma = malloc (255 * sizeof(char));
  char* arquivo_pos_genes = malloc (255 * sizeof(char));
  char* arquivo_fragmentos = malloc (255 * sizeof(char));
  char* arquivo_pos_fragmentos = malloc (255 * sizeof(char));
  char* arquivo_saida = malloc (255 * sizeof(char));
  long n_genes;

  scanf ("%s %s %s %s %s %ld", arquivo_genoma,  arquivo_pos_genes, arquivo_fragmentos, arquivo_pos_fragmentos, arquivo_saida, &n_genes);
  ContagemLeituras (arquivo_genoma, arquivo_pos_genes, arquivo_fragmentos, 
    arquivo_pos_fragmentos, n_genes, arquivo_saida);
  
  free (arquivo_genoma);
  free (arquivo_pos_genes);
  free (arquivo_fragmentos);
  free (arquivo_pos_fragmentos);
  free (arquivo_saida);

  return 0;
}