#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "genoma.h"

int main(void) {

  clock_t ciclos_ini_fix = 0, ciclos_ini = 0, quant_ciclos = 0; // inicia variáveis para contabilização dos ciclos
  FILE* tempo = fopen("./tempos.txt", "w"); // abre/cria arquivo de saida 

  ciclos_ini_fix = clock(); // guarda contagem de clocks do inicio do teste

  // testa caso (genoma grande.txt, pos genes grande.csv, fragmentos pequeno.txt)
  fprintf (tempo, "---VARIA-FRAGAMENTOS---\n");
  ciclos_ini = clock();
  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_pequeno.txt", 
    "./pos_fragmentos.txt", 10000,"./atividade_genica.txt");
  quant_ciclos = clock() - ciclos_ini;
  fprintf (tempo, "PEQUENO\n");
  fprintf (tempo, "Ciclos necessarios: %ld\n", quant_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) quant_ciclos)) / CLOCKS_PER_SEC);

  // testa caso (genoma grande.txt, pos genes grande.csv, fragmentos medio.txt)
  ciclos_ini = clock();
  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_medio.txt", 
    "./pos_fragmentos.txt", 10000,"./atividade_genica.txt");
  quant_ciclos = clock() - ciclos_ini;
  fprintf (tempo, "MEDIO\n");
  fprintf (tempo, "Ciclos necessarios: %ld\n", quant_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) quant_ciclos)) / CLOCKS_PER_SEC);

  // testa caso (genoma grande.txt, pos genes grande.csv, fragmentos grande.txt)
  ciclos_ini = clock();
  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 10000,"./atividade_genica.txt");
  quant_ciclos = clock() - ciclos_ini;
  fprintf (tempo, "GRANDE\n");
  fprintf (tempo, "Ciclos necessarios: %ld\n", quant_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) quant_ciclos)) / CLOCKS_PER_SEC);

  fprintf (tempo, "-----------------------\n");

  // testa caso (genoma grande.txt, pos genes pequeno.csv, fragmentos grande.txt)
  fprintf (tempo, "\n---VARIA-POS-GENES---\n");
  ciclos_ini = clock();
  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_pequeno.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 100,"./atividade_genica.txt");
  quant_ciclos = clock() - ciclos_ini;
  fprintf (tempo, "PEQUENO\n");
  fprintf (tempo, "Ciclos necessarios: %ld\n", quant_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) quant_ciclos)) / CLOCKS_PER_SEC);

  // testa caso (genoma grande.txt, pos genes medio.csv, fragmentos grande.txt)
  ciclos_ini = clock();  
  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_medio.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 1000,"./atividade_genica.txt");
  quant_ciclos = clock() - ciclos_ini;
  fprintf (tempo, "MEDIO\n");
  fprintf (tempo, "Ciclos necessarios: %ld\n", quant_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) quant_ciclos)) / CLOCKS_PER_SEC);

  // testa caso (genoma grande.txt, pos genes grande.csv, fragmentos grande.txt)
  ciclos_ini = clock();
  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 10000,"./atividade_genica.txt");
  quant_ciclos = clock() - ciclos_ini;
  fprintf (tempo, "GRANDE\n");
  fprintf (tempo, "Ciclos necessarios: %ld\n", quant_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) quant_ciclos)) / CLOCKS_PER_SEC);

  fprintf (tempo, "---------------------\n");

  // testa caso (genoma pequeno.txt, pos genes grande.csv,fragmentos grande.txt)
  fprintf (tempo, "\n---VARIA-GENOMA---\n");
  ciclos_ini = clock();
  ContagemLeituras ("./projeto_1_dados/genoma_pequeno.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 10000,"./atividade_genica.txt");
  quant_ciclos = clock() - ciclos_ini;
  fprintf (tempo, "PEQUENO\n");
  fprintf (tempo, "Ciclos necessarios: %ld\n", quant_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) quant_ciclos)) / CLOCKS_PER_SEC); 

  //testa caso (genoma medio.txt, pos genes grande.csv, fragmentos grande.txt)
  ciclos_ini = clock();
  ContagemLeituras ("./projeto_1_dados/genoma_medio.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 10000,"./atividade_genica.txt");
  quant_ciclos = clock() - ciclos_ini;
  fprintf (tempo, "MEDIO\n");
  fprintf (tempo, "Ciclos necessarios: %ld\n", quant_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) quant_ciclos)) / CLOCKS_PER_SEC);  

  //testa caso (genoma grande.txt, pos genes grande.csv, fragmentos grande.txt)
  ciclos_ini = clock();
  ContagemLeituras ("./projeto_1_dados/genoma_grande.txt", "./projeto_1_dados/pos_genes_grande.csv", "./projeto_1_dados/fragmentos_grande.txt", 
    "./pos_fragmentos.txt", 10000,"./atividade_genica.txt"); 
  quant_ciclos = clock() - ciclos_ini;
  fprintf (tempo, "GRANDE\n");
  fprintf (tempo, "Ciclos necessarios: %ld\n", quant_ciclos);
  fprintf (tempo, "Tempo (segundos): %.50lf\n", (((double) quant_ciclos)) / CLOCKS_PER_SEC);

  fprintf (tempo, "------------------\n");

  // imprime tempo total em minutos e quantitade total de ciclos para execução do teste 
  fprintf(tempo, "tempo TOTAL (minutos):  %.10lf\n", (((((double)clock() - ciclos_ini_fix)) / CLOCKS_PER_SEC)/(double) 60));
  fprintf (tempo, "Ciclos necessarios TOTAL: %ld", (clock() - ciclos_ini_fix));

  fclose(tempo);
  return 0;
}