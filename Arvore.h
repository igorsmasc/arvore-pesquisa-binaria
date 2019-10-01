typedef struct arvore Arvore;

Arvore * criar();
void destruir(Arvore * arv);

int altura(Arvore * arv);
int contar_folhas(Arvore * arv);
void imprimir(Arvore * arv);


char * gerar_string_txt(Arvore * a);
int buscar(Arvore * arv, char * v);
void inserir(Arvore * arv, char * v);
void remover(Arvore * arv, char * v);


void remover_maiores(Arvore * a, char * v);
void remover_menores(Arvore * a, char * v);
void listar_substring(Arvore * a, char * v);
int buscar2(Arvore * arv, char * v);
void inserir2(Arvore * arv, char * v);
void remover2(Arvore * arv, char * v);
