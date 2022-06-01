typedef struct {
    long *inicio;
    long *fim;
} elem;

typedef struct {
    long **intervalo;
} lista;

void criar(lista *l, long n);
void destruir(lista *l, int n);
long ** ordenaDigitos(long **A, long n, long posicao);
long ** ordenaNumeros(long **A, long n);
void contagemIntersecoes(char* arquivo_A, char* arquivo_B, long nA, long nB);
