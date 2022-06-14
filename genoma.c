#include "genoma.h"

void ContagemLeituras (char* arquivo_genoma, char* arquivo_pos_genes, char* arquivo_fragmentos, 
    char* arquivo_pos_fragmentos, long n_genes, char* arquivo_saida) {
        
    long n_fragmentos = ctrlF (arquivo_genoma, arquivo_fragmentos, arquivo_pos_fragmentos);
    
    contagemIntersecoes (arquivo_pos_genes, arquivo_pos_fragmentos, n_genes, n_fragmentos, arquivo_saida);

}