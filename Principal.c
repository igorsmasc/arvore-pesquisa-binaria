#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
#define _GNU_SOURCE 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Arvore * a = criar();
	apresentacao(a);
	menuPrincipal(a);
	
	destruir(a);
	system("pause");
}

// Mostrar o menu na tela inicial do programa
void apresentacao() {
	
	system("cls");
	printf("\n[                              APB-ED2                              ]\n\n");
	printf("[ (1) = Recarregar a listagem de nomes a partir do arquivo.         ]\n");
	printf("[ (2) = Listar todos os nomes em ordem alfabetica.                  ]\n");
	printf("[ (3) = Listar todos os nomes que contem uma substring fornecida.   ]\n");
	printf("[ (4) = Inserir um novo nome na memoria.                            ]\n");
	printf("[ (5) = Remover um nome da memoria.                                 ]\n");
	printf("[ (6) = Listar e remover da memoria todos os nomes que sao maiores  ]\n");
	printf("[ (7) = Listar e remover da memoria todos os nomes que sao menores. ]\n");
	printf("[ (8) = Salvar o conteudo da memoria em um arquivo texto.           ]\n\n");
	printf("[ (9) = SAIR DO PROGRAMA                                            ]\n");
	printf("                                                   \n");
	printf("Selecione uma das opcoes acima\n");
	
}


// Menu principal onde estarão as operações principais do programa
void menuPrincipal(Arvore * a) {
		apresentacao(a);
		char op;
		char nome[30];
		op = getch();
		
		switch(op){
			case '1':
				carregarDB(a);
				system("pause");
				menuPrincipal(a);
				break;
			case '2':
				imprimir(a);
				system("pause");
				menuPrincipal(a);
				break;
			case '3':
				printf("Digite o que deseja buscar: \n");
				gets(nome);
				listar_substring(a, nome);
				system("pause");
				menuPrincipal(a);
				break;
			case '4':
				printf("Digite o que deseja inserir: \n");
				gets(nome);
				inserir(a, nome);
				system("pause");
				menuPrincipal(a);
				break;
			case '5':
				printf("Digite o que deseja remover: \n");
				gets(nome);
				remover(a, nome);
				system("pause");
				menuPrincipal(a);
				break;
			case '6':
				
				break;
			case '7':
				
				break;
			case '8':
				
				break;
			case '9':
				
				break;
			default:	
				menuPrincipal(a); 
				// Adicionar texto valor inválido
		}
		
}

void valorInvalido(Arvore * a){
	printf("O valor inserido e invalido");
	system("pause");
	menuPrincipal(a);

}

// ********************** BASE DE DADOS ************************ //

//Seção para manipulação da base de dados(.txt)

void escreverDB(int op) {
	// Qualquer valor chamado na ausencia da db
	// ir? criar uma nova
	char arr[50][30]; 
	strcpy(arr[0], "igor mascarenhas");
	strcpy(arr[1], "liana maria");
	
	
	FILE * fp;
	fp = fopen("database.txt", "w"); // A letra w sobre escreve o que j? existe
	
	// 1 - escrever na database
	if(op == 1) {
			
			fprintf(fp, arr[0]);// Aqui vai a lista j? montada e n?o um nome por vez
			fprintf(fp, arr[1]);// Aqui vai a lista j? montada e n?o um nome por vez
		
	}
	
	fclose(fp);
} 

/* 1. Recarregar a listagem de nomes a partir do arquivo. 
*	Para tanto, todo o conteúdo da árvore anterior deverá ser removido
*	e uma nova carga deverá ser feita, como descrito acima.
*/

void carregarDB(Arvore * a) {
	
	FILE *fp; // Variável do tipo arquivo
	char str[30];
	char * nome;
	char * filename = "database.txt";
	size_t len= 100; // valor arbitrário
	
	
	fp = fopen(filename, "r");
	if(fp == NULL) {
		escreverDB(0);
		fp = fopen(filename, "r");
		if(fp == NULL) {
			printf("Não foi possível carregar a base de dados %s", filename);
			return 1;
		}
	}
	printf("\n");
	
	while (fgets(nome, 30, fp) != NULL){
		printf("\n %s \n", nome);
		inserir(a, nome);
	}

		
	fclose(fp);
	getch();
	return 0;
	
}


// ********************** BASE DE DADOS - FIM ************************ //


