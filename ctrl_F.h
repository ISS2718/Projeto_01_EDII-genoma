#ifndef __CTRL_F___
#define __CTRL_F__

#include <stdio.h>
#include <stdlib.h>

#define TAM_TXT 1000

typedef struct {
    char* txt;
} texto;

void criar_texto (texto* text, char* arquivo);
void destruir_texto (texto* text);
void ctrlF (char* arquivo_texto, char* arquivo_trechos, char* saida );
#endif