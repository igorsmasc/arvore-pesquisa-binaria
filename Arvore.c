#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

typedef struct no No;

struct arvore {
	No * raiz;
};

struct no {
	char * info;
	No * pai;
	No * esq;
	No * dir;
};

Arvore * criar() {
   Arvore * a = malloc(sizeof(Arvore));
   a->raiz = NULL;
   return a;
}

void destruir(Arvore * a) {
	desalocar_nos_rec(a->raiz);
	free(a);
}

void desalocar_nos_rec(No * raiz) {
	if (raiz != NULL) {
		desalocar_nos_rec(raiz->esq);
		desalocar_nos_rec(raiz->dir);
		free(raiz);
	}
}

void imp_pre(No * raiz) {
	if (raiz != NULL) {
		printf("%s ", raiz->info);
		imp_pre(raiz->esq);
		imp_pre(raiz->dir);
	}
}

int buscar2(Arvore * arv, char * v) {
	No * raiz = arv->raiz;
	while(raiz != NULL) {
		if ( strstr(raiz->info, v) ) {
			return 1;
		}
		raiz = raiz->info > v ? 
			raiz->esq : raiz->dir;
	}
	return 0;
}

void imp_pos(No * raiz) {
	if (raiz != NULL) {
		imp_pos(raiz->esq);
		imp_pos(raiz->dir);
		printf("%s ", raiz->info);
	}
}

int altura(Arvore * arv) {
	return altura_rec(arv->raiz);
}

int altura_rec(No * raiz) {
	if (raiz != NULL) {
		int ad = altura_rec(raiz->dir);
		int ae = altura_rec(raiz->esq);
		return (ad > ae ? ad : ae) + 1;
	}
	return -1;
}

int contar_folhas(Arvore * arv) {
	return contar_folhas_rec(arv->raiz);
}

int contar_folhas_rec(No * raiz) {
	if (raiz != NULL) {
		if (raiz->esq == NULL && raiz->dir == NULL) {
			return 1;
		} else {
			return contar_folhas_rec(raiz->esq) +
				   contar_folhas_rec(raiz->dir);
		}
	}
	return 0;
}

int buscar(Arvore * arv, char * v) {
	return buscar_rec(arv->raiz, v);
}

int buscar_rec(No * raiz, char * v) {
	if (raiz != NULL) {
		if (raiz->info > v) {
			return buscar_rec(raiz->esq, v);
		}
		if (raiz->info < v) {
			return buscar_rec(raiz->dir, v);
		}
		return 1;
	}
	return 0;
}



void inserir2(Arvore * arv, char * v) {
	No * pai = NULL, * raiz = arv->raiz;
	while(raiz != NULL) {
		if (raiz->info == v) {
			return;
		}
		pai = raiz;
		raiz = raiz->info > v ? raiz->esq : raiz->dir;
	}
	raiz = malloc(sizeof(No));
	raiz->info = v;
	raiz->esq = NULL;
	raiz->dir = NULL;
	if (pai == NULL) {
		arv->raiz = raiz;
	} else {
		if (pai->info > v) {
			pai->esq = raiz;
		} else {
			pai->dir = raiz;
		}
	}
}

void remover2(Arvore * arv, char * v) {
	No * pai = NULL, * raiz = arv->raiz;
	//COMEÇA COM UMA BUSCA
	while(raiz != NULL) {
		if (raiz->info == v) {
			break;
		}
		pai = raiz;
		raiz = raiz->info > v ? 
			raiz->esq : raiz->dir;
	}
	if (raiz == NULL) {
		return;
	}
	// FOLHA (GRAU 0)
	if (raiz->esq == NULL && raiz->dir == NULL) {
		if (pai != NULL) {
			if (pai->info > raiz->info) {
				pai->esq = NULL;
			} else {
				pai->dir = NULL;
			}
		} else {
			arv->raiz = NULL;
		}
		free(raiz);
	} else {
		//GRAU 1
		if (raiz->esq == NULL || raiz->dir == NULL) {
			if (pai != NULL) {
				if (raiz->esq != NULL) {
					if (pai->info > raiz->info) {
						pai->esq = raiz->esq;
					} else {
						pai->dir = raiz->esq;
					}
				} else {
					if (pai->info > raiz->info) {
						pai->esq = raiz->dir;
					} else {
						pai->dir = raiz->dir;
					}
				}
			} else {
				if (raiz->esq != NULL) {
					arv->raiz = raiz->esq;
				} else {
					arv->raiz = raiz->dir;
				}
			}
			free(raiz);
		} else { //GRAU 2
			No * no_maior = raiz->esq;
			//percorre à direita até NULO
			pai = raiz;
			while(no_maior->dir != NULL) {
				pai = no_maior;
				no_maior = no_maior->dir;
			}
			raiz->info = no_maior->info;
			if (pai == raiz) {
				pai->esq = no_maior->esq;				
			} else {
				pai->dir = no_maior->esq;
			}
			free(no_maior);
		}
	}
}


// CONCLUIDOS PARA O TRABALHO 

// 2. Listar todos os nomes em ordem alfabética.

void imprimir(Arvore * a) {
	
	printf("\n");imp_in(a->raiz);
} 

void imp_in(No * raiz) {
	if (raiz != NULL) {
		imp_in(raiz->esq);
		printf("%s \n", raiz->info);
		imp_in(raiz->dir);
	}
}

// 3. Listar todos os nomes que contém uma substring fornecida.

void listar_substring(Arvore * a, char * v) {
	printf("*** Nomes contendo a subtring: '%s' ***", v);
	printf("\n");
	imp_substring(a->raiz, v);
	printf("\n");
} 

void imp_substring(No * raiz, char * v) {
	if (raiz != NULL) {
		
		imp_substring(raiz->esq, v);
		
		if(strstr(raiz->info, v)) {
			printf("%s ", raiz->info);
		}
		
		imp_substring(raiz->dir, v);
		
	}
}

// 4. Inserir um novo nome na memória.

No * inserir_rec(No * raiz, char * v) {
	
	if (raiz != NULL) {
		if (strcmp(raiz->info, v) > 0) {
			raiz->esq = inserir_rec(raiz->esq, v);
		}
		if (strcmp(raiz->info, v) < 0) {
			raiz->dir = inserir_rec(raiz->dir, v);
		}
	} else {
		raiz = malloc(sizeof(No));
		raiz->info = malloc(sizeof(char)*30);
		strcpy(raiz->info, v);
		raiz->esq = NULL;
		raiz->dir = NULL;
		
	}
	return raiz;
}

void inserir(Arvore * arv, char * v) {
	arv->raiz = inserir_rec(arv->raiz, v);
}

// 5. Remover um nome da memória.

No * remover_maior(No * raiz, int * pmaior) {
	if (raiz != NULL) {
		if (raiz->dir != NULL) {
			raiz->dir = remover_maior(raiz->dir, pmaior);
		} else {
			No * aux = raiz;
			*pmaior = raiz->info;
			raiz = raiz->esq;
			free(aux);
		}
	}
	return raiz;
}


No * remover_rec(No * raiz, char * v) {
	if (raiz != NULL) {
		if (strcmp(raiz->info, v) > 0) { 
			raiz->esq = remover_rec(raiz->esq, v);
		} else {
			if (strcmp(raiz->info, v) < 0) {
				raiz->dir = remover_rec(raiz->dir, v);
			} else { //ENCONTROU
				No * aux = raiz;
				// FOLHA (GRAU 0)
				if (raiz->esq == NULL && raiz->dir == NULL) {
					raiz = NULL;	
					free(aux);
				} else {
					//GRAU 1
					if (raiz->esq == NULL || raiz->dir == NULL) {
						raiz = raiz->esq != NULL ? raiz->esq : raiz->dir;
						free(aux);
					} else { //GRAU 2
						int maior;
						raiz->esq = remover_maior(raiz->esq, &maior);
						raiz->info = maior;
					}
				}
			}
		}
	}
	return raiz;
}

void remover(Arvore * arv, char * v) {
	strcat(v, "\n");
	arv->raiz = remover_rec(arv->raiz, v);
}

char * gerar_string_rec(No * raiz) {
	char * str = malloc(sizeof(char)*2000);
	if(raiz != NULL) {
		printf("%s ", str);
		strcat(str, gerar_string_rec(raiz->esq));
		strcat(str, gerar_string_rec(raiz->dir));
		return str;
	}
}

char * gerar_string_txt(Arvore * a){
	return gerar_string_rec(a->raiz);
}

// 6. Listar e remover da memoria todos os nomes que sao maiores.

void remover_maiores(Arvore * a, char * v) {
	strcat(v, "\n");
	remover_maiores_rec(a->raiz, v, a);
	remover_maiores_rec2(a->raiz, v, a);
}

void remover_maiores_rec(No * raiz, char * v, Arvore * a) {
	if(raiz != NULL) {
		if(strcmp(raiz->info, v) > 0) {
			remover(a, raiz->info);
		}
		
		remover_maiores_rec(raiz->esq, v, a);
		remover_maiores_rec(raiz->dir, v, a);
	}
}



// 7. Listar e remover da memoria todos os nomes que sao maiores.

void remover_menores(Arvore * a, char * v) {
	remover_menores_rec(a->raiz, v, a);
	remover_menores_rec2(a->raiz, v, a);
}

void remover_menores_rec(No * raiz, char * v, Arvore * a) {
	if(raiz != NULL) {
		if(strcmp(raiz->info, v) < 0) {
			remover(a, raiz->info);
		}
		remover_menores_rec(raiz->dir, v, a);
		remover_menores_rec(raiz->esq, v, a);
		
	}
}


// FUNÇÕES DE TESTE


void remover_maiores_rec2(No * raiz, char * v, Arvore * a) {
	if(raiz != NULL) {
		if(strcmp(raiz->info, v) > 0) {
			remover(a, raiz->info);
		}
		
		remover_maiores_rec(raiz->esq, v, a);
		remover_maiores_rec(raiz->dir, v, a);
	}
}



void remover_menores_rec2(No * raiz, char * v, Arvore * a) {
	if(raiz != NULL) {
		if(strcmp(raiz->info, v) < 0) {
			remover(a, raiz->info);
		}
		
		remover_menores_rec(raiz->esq, v, a);
		remover_menores_rec(raiz->dir, v, a);
		
	}
}

// GRAVAR

void gravar_arquivo(Arvore * a){
	FILE * arquivo = fopen("database.txt", "w");
    if(arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.txt.");
        return 1;
    }else{
    	gravar_arquivo_rec(a->raiz, arquivo);
	}
	
	fclose(arquivo);
}

void gravar_arquivo_rec(No * raiz, FILE * arquivo){
	fflush(stdin);
	if(raiz != NULL){
		gravar_arquivo_rec(raiz->esq, arquivo);
		fputs(raiz->info, arquivo);
		fputs("\n", arquivo);
		printf("\n");
		gravar_arquivo_rec(raiz->dir, arquivo);
	}

}



















