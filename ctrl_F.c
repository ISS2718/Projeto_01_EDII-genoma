#include "ctrl_F.h"

void criar_texto (texto* text) { // aloca memoria para uma string 
    text->txt = malloc(TAM_TXT * sizeof(char)); 
}

void criar_copiar_texto (texto* text, char* arquivo) {// aloca memoria para uma string e copia uma linha de um arquivo
 FILE* A = fopen (arquivo, "r");
 text->txt = malloc(TAM_TXT * sizeof(char));
 fgets (text->txt, TAM_TXT, A);
 fclose (A);
}

void destruir_texto (texto* text) {// desaloca memória alocada num ponteiro tipo texto
    free(text->txt);
    free(text);
    text == NULL;
}

long ctrlF (char* arquivo_texto, char* arquivo_trechos, char* saida ) {
    // declaração de variáveis necessárias
    long n_frag = 0; // variável de retorno de numero de trechos encontrados  
    texto *text = malloc (1*sizeof(texto));
    criar_copiar_texto (text, arquivo_texto); // guarda o arquivo texto em uma string 
    texto *trecho = malloc (1*sizeof(texto));
    criar_texto(trecho);// cria uma string para trechos
    for(long i = 0; i < TAM_TXT; i++) {// inicia a string de trechos com \0
        trecho->txt[i] = '\0';
    }

    FILE *f_saida = fopen (saida, "w"); // abre/cria o arquivo de saida
    FILE *f_trechos = fopen(arquivo_trechos, "r");// abre o arquivo de trechos

    char *status = fgets(trecho->txt, TAM_TXT, f_trechos);// copia o primeiro trecho
    while (status) {// enquanto o arquivo de trechos não chega ao fim
        long i = 0;
        while (text->txt[i] != '\0') {// enquanto um texto não chega ao fim
            long j = 0;
            while ((trecho->txt[j] == text->txt[i+j])) {// enquanto o caracter do trecho for igual ao do texto
                j++;  
                if ((trecho->txt[j+1] == '\0')) { //verificando se o proximo caracter é o fim do trecho
                    fprintf (f_saida, "%ld,%ld\n", i+1, (i+j));
                    n_frag++;
                    break; //quebra o laço para não precisar comparar se o trecho chegou ao fim
                } 
            }
            i++;
        }
        status = fgets(trecho->txt, TAM_TXT, f_trechos); // copia novo trecho
    }
    // fecha arquivos usados
    fclose(f_trechos);
    fclose(f_saida);
    // destroi os tipo textos usados
    destruir_texto(text);
    destruir_texto(trecho);
    
    return n_frag; // retorna quantidade de trechos encontrados
}