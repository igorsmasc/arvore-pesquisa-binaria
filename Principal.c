#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Arvore * a = criar();
	inserir(a, "ca");
	inserir(a, "aa");
	inserir(a, "cb");
	inserir(a, "b");
	//printf(buscar2(a, "0") == 1 ? "Sim" : "Nao");
	
	imprimir(a);
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
void menuPrincipal() {
	apresentacao();
		char op;
		op = getch();
		
		switch(op){
			case '1':
				carregarDB();
				system("pause");
				menuPrincipal();
				break;
			case '2':
				
				break;
			case '3':
				
				break;
			case '4':
				escreverDB(1);
				system("pause");
				menuPrincipal();
				break;
			case '5':
				
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
				menuPrincipal(); 
				// Adicionar texto valor inválido
		}
		
}

void valorInvalido(){
	printf("O valor inserido e invalido");
	system("pause");
	menuPrincipal();

}

// ********************** BASE DE DADOS ************************ //

//Seção para manipulação da base de dados(.txt)

void escreverDB(int op) {
	// Qualquer valor chamado na ausencia da db
	// irá criar uma nova
	char * arr; 
	strcpy(arr[0], "igor mascarenhas\n");
	strcpy(arr[1], "liana maria\n");
	
	
	FILE * fp;
	fp = fopen("database.txt", "w"); // A letra w sobre escreve o que já existe
	
	// 1 - escrever na database
	if(op == 1) {
			fprintf(fp, arr[0]); // Aqui vai a lista já montada e não um nome por vez
			fprintf(fp, arr[1]); // Aqui vai a lista já montada e não um nome por vez
		
	}
	
	fclose(fp);
} 

void carregarDB() {
	
	FILE *fp; //Variável do tipo arquivo
	char str[100];
	char * filename = "database.txt";
	
	fp = fopen(filename, "r");
	if(fp == NULL) {
		escreverDB(0);
		fp = fopen(filename, "r");
		if(fp == NULL) {
			printf("Não foi possível carregar a base de dados %s", filename);
			return 1;
		}
	}
	
	while (fgets(str, 100, fp) != NULL)
		printf("\n%s \n\n", str);
	fclose(fp);
	return 0;
	
}

// ********************** BASE DE DADOS - FIM ************************ //


