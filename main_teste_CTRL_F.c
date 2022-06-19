#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "genoma.h"

int main(void) {

  clock_t ciclos_ini_fix = 0, ciclos_ini = 0, quant_ciclos = 0; // inicia variáveis para contabilização dos ciclos
  FILE* tempo = fopen("./teste_empirico_CRTL_F.txt", "w"); // abre/cria arquivo de saida 

  ciclos_ini_fix = clock(); // guarda contagem de clocks do inicio do teste
  fprintf (tempo, "---GENES___FRAGEMENTOS---\n");
  fprintf (tempo, "---PEQUENO_PEQUENO---\n");
  ciclos_ini = clock();
  ctrlF("./projeto_1_dados/genoma_pequeno.txt", "./projeto_1_dados/fragmentos_pequeno.txt", "./pos_fragmentos_PP.txt");
  quant_ciclos = clock() - ciclos_ini;
  fprintf (tempo, "Ciclos necessarios: %ld\n", quant_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) quant_ciclos)) / CLOCKS_PER_SEC);
  fprintf (tempo, "---------------------\n");

  fprintf (tempo, "---PEQUENO_MEDIO---\n");
  ciclos_ini = clock();
  ctrlF("./projeto_1_dados/genoma_pequeno.txt", "./projeto_1_dados/fragmentos_medio.txt", "./pos_fragmentos_PM.txt");
  quant_ciclos = clock() - ciclos_ini;
  fprintf (tempo, "Ciclos necessarios: %ld\n", quant_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) quant_ciclos)) / CLOCKS_PER_SEC);
  fprintf (tempo, "---------------------\n");

  fprintf (tempo, "---PEQUENO_GRANDE---\n");
  ciclos_ini = clock();
  ctrlF("./projeto_1_dados/genoma_pequeno.txt", "./projeto_1_dados/fragmentos_grande.txt", "./pos_fragmentos_PG.txt");
  quant_ciclos = clock() - ciclos_ini;
  fprintf (tempo, "Ciclos necessarios: %ld\n", quant_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) quant_ciclos)) / CLOCKS_PER_SEC);
  fprintf (tempo, "---------------------\n");

  fprintf (tempo, "---MEDIO_PEQUENO---\n");
  ciclos_ini = clock();
  ctrlF("./projeto_1_dados/genoma_medio.txt", "./projeto_1_dados/fragmentos_pequeno.txt", "./pos_fragmentos_MP.txt");
  quant_ciclos = clock() - ciclos_ini;
  fprintf (tempo, "Ciclos necessarios: %ld\n", quant_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) quant_ciclos)) / CLOCKS_PER_SEC);
  fprintf (tempo, "---------------------\n");

  fprintf (tempo, "---MEDIO_MEDIO---\n");
  ciclos_ini = clock();
  ctrlF("./projeto_1_dados/genoma_medio.txt", "./projeto_1_dados/fragmentos_medio.txt", "./pos_fragmentos_MM.txt");
  quant_ciclos = clock() - ciclos_ini;
  fprintf (tempo, "Ciclos necessarios: %ld\n", quant_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) quant_ciclos)) / CLOCKS_PER_SEC);
  fprintf (tempo, "---------------------\n");

  fprintf (tempo, "---MEDIO_GRANDE---\n");
  ciclos_ini = clock();
  ctrlF("./projeto_1_dados/genoma_medio.txt", "./projeto_1_dados/fragmentos_grande.txt", "./pos_fragmentos_MG.txt");
  quant_ciclos = clock() - ciclos_ini;
  fprintf (tempo, "Ciclos necessarios: %ld\n", quant_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) quant_ciclos)) / CLOCKS_PER_SEC);
  fprintf (tempo, "---------------------\n");

  fprintf (tempo, "---GRANDE_PEQUENO---\n");
  ciclos_ini = clock();
  ctrlF("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/fragmentos_pequeno.txt", "./pos_fragmentos_GP.txt");
  quant_ciclos = clock() - ciclos_ini;
  fprintf (tempo, "Ciclos necessarios: %ld\n", quant_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) quant_ciclos)) / CLOCKS_PER_SEC);
  fprintf (tempo, "---------------------\n");

  fprintf (tempo, "---GRANDE_MEDIO---\n");
  ciclos_ini = clock();
  ctrlF("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/fragmentos_medio.txt", "./pos_fragmentos_GM.txt");
  quant_ciclos = clock() - ciclos_ini;
  fprintf (tempo, "Ciclos necessarios: %ld\n", quant_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) quant_ciclos)) / CLOCKS_PER_SEC);
  fprintf (tempo, "---------------------\n");

  fprintf (tempo, "---GRANDE_GRANDE---\n");
  ciclos_ini = clock();
  ctrlF("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/fragmentos_grande.txt", "./pos_fragmentos_GG.txt");
  quant_ciclos = clock() - ciclos_ini;
  fprintf (tempo, "Ciclos necessarios: %ld\n", quant_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) quant_ciclos)) / CLOCKS_PER_SEC);
  fprintf (tempo, "---------------------\n");

  // imprime tempo total em minutos e quantitade total de ciclos para execução do teste 
  fprintf(tempo, "\ntempo TOTAL (minutos):  %.10lf\n", (((((double)clock() - ciclos_ini_fix)) / CLOCKS_PER_SEC)/(double) 60));
  fprintf (tempo, "Ciclos necessarios TOTAL: %ld", (clock() - ciclos_ini_fix));

  fclose(tempo);
  return 0;
}