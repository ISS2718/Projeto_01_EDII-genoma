#ifndef __GENOMA__
#define __GENOMA__

#include "intervalos.h"
#include "ctrl_F.h"

void ContagemLeituras (char* arquivo_genoma, char* arquivo_pos_genes, char* arquivo_fragmentos, 
    char* arquivo_pos_fragmentos, long n_genes, char* arquivo_saida);
#endif