#include <stdio.h>
#include <stdlib.h>

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

void menuPrincipal() {
	apresentacao();
		char op;
		op = getch();
		
		switch(op){
			case '1':
				break;
			case '2':
				
				break;
			case '3':
				
				break;
			case '4':
				
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
}

int main(int argc, char *argv[]) {
	
	menuPrincipal();
	
}
