#include <stdio.h>
#include <stdlib.h>
#define MAXCHAR 30
#define MAX_NUMBER_STRINGS 50



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


// Menu principal onde estar�o as opera��es principais do programa
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
				// Adicionar texto valor inv�lido
		}
		
}

void valorInvalido(){
	printf("O valor inserido e invalido");
	system("pause");
	menuPrincipal();

}

// ********************** BASE DE DADOS ************************ //

//Se��o para manipula��o da base de dados(.txt)

void escreverDB(int op) {
	// Qualquer valor chamado na ausencia da db
	// ir� criar uma nova
	char arr[MAX_NUMBER_STRINGS][MAXCHAR]; 
	strcpy(arr[0], "igor mascarenhas");
	strcpy(arr[1], "liana maria ");
	
	
	FILE * fp;
	fp = fopen("database.txt", "w"); // A letra w sobre escreve o que j� existe
	
	// 1 - escrever na database
	if(op == 1) {
			fprintf(fp, arr[0]);// Aqui vai a lista j� montada e n�o um nome por vez
			fprintf(fp, arr[1]);// Aqui vai a lista j� montada e n�o um nome por vez
		
	}
	
	fclose(fp);
} 

void carregarDB() {
	
	FILE *fp; //Vari�vel do tipo arquivo
	char str[MAXCHAR];
	char * filename = "database.txt";
	
	fp = fopen(filename, "r");
	if(fp == NULL) {
		escreverDB(0);
		fp = fopen(filename, "r");
		if(fp == NULL) {
			printf("N�o foi poss�vel carregar a base de dados %s", filename);
			return 1;
		}
	}
	
	while (fgets(str, MAXCHAR, fp) != NULL)
		printf("\n%s \n\n", str);
	fclose(fp);
	return 0;
	
}

// ********************** BASE DE DADOS - FIM ************************ //

int main(int argc, char *argv[]) {
	
	menuPrincipal();
	
}
