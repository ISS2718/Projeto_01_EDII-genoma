#include "ctrl_F.h"

void criar_texto (texto* text, char* arquivo) {
 FILE* A = fopen (arquivo, "r");
 text->txt = malloc(TAM_TXT * sizeof(char));
 fscanf (A, "%s", &text->txt);
 fclose (A);
}

void destruir_texto (texto* text) {
    free(text->txt);
    free(text);
    text == NULL;
}

void ctrlF (char* arquivo_texto, char* arquivo_trechos, char* saida ) {
    texto *text = malloc (1*sizeof(texto));
    texto *trecho = malloc (1*sizeof(texto));
    criar_texto (text, arquivo_texto);
    trecho->txt = malloc (TAM_TXT * sizeof(char));
    
    FILE *f_saida = fopen (saida, "w");
    FILE *f_trechos = fopen(arquivo_trechos, "r");

    char *status = fgets(trecho->txt, TAM_TXT, f_trechos);
    while (status) {
        long i = 0;
        while (text->txt[i] != '\0') {
            long j = 0;
            while ((trecho->txt[j] != '\0') && (text->txt[i+j] == trecho->txt[j])) {
                j++;
            }
            if ((trecho->txt[j] == '\0')) {
                fprintf (f_saida, "%ld,%ld\n", i, (i+j-1));
            }
            i++;
        }
        status = fgets(trecho->txt, TAM_TXT, f_trechos);
    }
    fclose(f_saida);
    fclose(f_trechos);
    destruir_texto(text);
    destruir_texto(trecho);
}