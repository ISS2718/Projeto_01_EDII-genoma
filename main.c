#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "genoma.h"

int main(void) {

  clock_t ciclos_ini, soma_ciclos;
  FILE* tempo = fopen("./tempos.txt", "w");


  fprintf (tempo, "---VARIA-FRAGAMENTOS---\n");
  ciclos_ini = clock();
  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_pequeno.txt", 
    "./pos_fragmentos.txt", 10000,"./atividade_genica.txt");
  soma_ciclos =+ clock() - ciclos_ini;
  fprintf (tempo, "PEQUENO\n");
  fprintf (tempo, "Soma ciclos: %d\n", soma_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) soma_ciclos)) / CLOCKS_PER_SEC);

  ciclos_ini = clock();
  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_medio.txt", 
    "./pos_fragmentos.txt", 10000,"./atividade_genica.txt");
  soma_ciclos =+ clock() - ciclos_ini;
  fprintf (tempo, "MEDIO\n");
  fprintf (tempo, "Soma ciclos: %d\n", soma_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) soma_ciclos)) / CLOCKS_PER_SEC);

  ciclos_ini = clock();
  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 10000,"./atividade_genica.txt");
  soma_ciclos =+ clock() - ciclos_ini;
  fprintf (tempo, "GRANDE\n");
  fprintf (tempo, "Soma ciclos: %d\n", soma_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) soma_ciclos)) / CLOCKS_PER_SEC);

  fprintf (tempo, "-----------------------\n");


  fprintf (tempo, "\n---VARIA-POS-GENES---\n");
  ciclos_ini = clock();
  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_pequeno.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 100,"./atividade_genica.txt");
  soma_ciclos =+ clock() - ciclos_ini;
  fprintf (tempo, "PEQUENO\n");
  fprintf (tempo, "Soma ciclos: %d\n", soma_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) soma_ciclos)) / CLOCKS_PER_SEC);

  ciclos_ini = clock();  
  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_medio.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 1000,"./atividade_genica.txt");
  soma_ciclos =+ clock() - ciclos_ini;
  fprintf (tempo, "MEDIO\n");
  fprintf (tempo, "Soma ciclos: %d\n", soma_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) soma_ciclos)) / CLOCKS_PER_SEC);

  ciclos_ini = clock();
  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 10000,"./atividade_genica.txt");
  soma_ciclos =+ clock() - ciclos_ini;
  fprintf (tempo, "GRANDE\n");
  fprintf (tempo, "Soma ciclos: %d\n", soma_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) soma_ciclos)) / CLOCKS_PER_SEC);

  fprintf (tempo, "---------------------\n");


  fprintf (tempo, "\n---VARIA-GENOMA---\n");
  ciclos_ini = clock();
  ContagemLeituras ("./projeto_1_dados/genoma_pequeno.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 10000,"./atividade_genica.txt");
  soma_ciclos =+ clock() - ciclos_ini;
  fprintf (tempo, "PEQUENO\n");
  fprintf (tempo, "Soma ciclos: %d\n", soma_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) soma_ciclos)) / CLOCKS_PER_SEC); 

  ciclos_ini = clock();
  ContagemLeituras ("./projeto_1_dados/genoma_medio.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 10000,"./aatividade_genica.txt");
  soma_ciclos =+ clock() - ciclos_ini;
  fprintf (tempo, "MEDIO\n");
  fprintf (tempo, "Soma ciclos: %d\n", soma_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) soma_ciclos)) / CLOCKS_PER_SEC);  

  ciclos_ini = clock();
  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 10000,"./atividade_genica.txt"); 
  soma_ciclos =+ clock() - ciclos_ini;
  fprintf (tempo, "GRANDE\n");
  fprintf (tempo, "Soma ciclos: %d\n", soma_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) soma_ciclos)) / CLOCKS_PER_SEC);

  fprintf (tempo, "------------------\n");

  return 0;
}