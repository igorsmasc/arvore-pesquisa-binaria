typedef struct arvore Arvore;

Arvore * criar();
void destruir(Arvore * arv);

int altura(Arvore * arv);
int contar_folhas(Arvore * arv);
void imprimir(Arvore * arv);

int buscar(Arvore * arv, char * v);
void inserir(Arvore * arv, char * v);
void remover(Arvore * arv, char * v);

int buscar2(Arvore * arv, char * v);
void inserir2(Arvore * arv, char * v);
void remover2(Arvore * arv, char * v);
