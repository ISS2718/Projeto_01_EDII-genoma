#include <stdio.h>
#include <stdlib.h>

#include "genoma.h"

int main(void) {
  //entrada dos caminhos do aruivo de texto e da quantidade de genes
  char* arquivo_genoma = malloc (255 * sizeof(char));
  char* arquivo_pos_genes = malloc (255 * sizeof(char));
  char* arquivo_fragmentos = malloc (255 * sizeof(char));
  char* arquivo_pos_fragmentos = malloc (255 * sizeof(char));
  char* arquivo_saida = malloc (255 * sizeof(char));
  long n_genes;
  scanf ("%s %s %s %s %s %ld", arquivo_genoma,  arquivo_pos_genes, arquivo_fragmentos, arquivo_pos_fragmentos, arquivo_saida, &n_genes);
  
  //inicia o programa enviando os caminhos dos arquivos recebidos para suas devidas funções
  ContagemLeituras (arquivo_genoma, arquivo_pos_genes, arquivo_fragmentos, 
    arquivo_pos_fragmentos, n_genes, arquivo_saida);
  
  //libera a memória alocada para as strings
  free (arquivo_genoma);
  free (arquivo_pos_genes);
  free (arquivo_fragmentos);
  free (arquivo_pos_fragmentos);
  free (arquivo_saida);

  return 0;
}