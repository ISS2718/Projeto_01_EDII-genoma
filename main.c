#define TAM 100
#include "genoma.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  FILE* tempo = fopen("./tempos.txt", "w"); 

  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_pequeno.txt", 
    "./pos_fragmentos.txt", 100,"./tividade_genica.txt");
  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_medio.txt", 
    "./pos_fragmentos.txt", 100,"./tividade_genica.txt");
  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 100,"./tividade_genica.txt");

  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_pequeno.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 100,"./tividade_genica.txt");
  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_medio.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 100,"./tividade_genica.txt");
  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 100,"./tividade_genica.txt");

  ContagemLeituras ("./projeto_1_dados/genoma_pequeno.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 100,"./tividade_genica.txt");
  ContagemLeituras ("./projeto_1_dados/genoma_medio.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 100,"./tividade_genica.txt");
  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 100,"./tividade_genica.txt"); 

  return 0;
}