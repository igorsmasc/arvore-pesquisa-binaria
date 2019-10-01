#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Arvore * a = criar();
	menuPrincipal(a);
	
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
	apresentacao();
		char op;
		char nome[30];
		op = getch();
		
		switch(op){
			case '1':
				a = criar();
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
				printf("Digite o que deseja remover (MAIORES): \n");
				gets(nome);
				remover_maiores(a, nome);
				system("pause");
				menuPrincipal(a);
				break;
			case '7':
				printf("Digite o que deseja remover (MENORES): \n");
				gets(nome);
				remover_menores(a, nome);
				system("pause");
				menuPrincipal(a);
				break;
				break;
			case '8':
				
				escreverDB(1, a);
				system("pause");
				menuPrincipal(a);
				break;
			case '9':
				destruir(a);
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

void escreverDB(int op, Arvore * a) {
	// Qualquer valor chamado na ausencia da db
	// irá criar uma nova
	char * v;
	v = gerar_string_txt(a);
	
	FILE * fp;
	fp = fopen("database.txt", "w"); // A letra w sobre escreve o que já existe
	
	// 1 - escrever na database
	if(op == 1) {
			fprintf(fp, v); // Aqui vai a lista já montada e não um nome por vez
		
	}
	
	fclose(fp);
} 

void carregarDB(Arvore * a) {
	
	FILE *fp; // Variável do tipo arquivo
	char str[30];
	char * nome;
	char * filename = "database.txt";
	size_t len= 100; // valor arbitrário
	
	
	fp = fopen(filename, "r");
	if(fp == NULL) {
		escreverDB(0, "");
		fp = fopen(filename, "r");
		if(fp == NULL) {
			printf("Não foi possível carregar a base de dados %s", filename);
			return 1;
		}
	}
	printf("\n");
	while (fgets(str, 30, fp) != NULL){
		printf("\n%s\n", str);
		inserir(a, str);
	}
		
	fclose(fp);
	return 0;
	
}

/* 1. Recarregar a listagem de nomes a partir do arquivo. 
*	Para tanto, todo o conteúdo da árvore anterior deverá ser removido
*	e uma nova carga deverá ser feita, como descrito acima.
*/


// ********************** BASE DE DADOS - FIM ************************ //


