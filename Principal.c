#include <stdio.h>
#include <stdlib.h>

void apresentacao() {
	
	system("cls");
	printf("\n[                              APB-ED2                              ]\n\n");
	printf("[ (1) = Recarregar a listagem de nomes a partir do arquivo.         ]\n");
	printf("[ (2) = Listar todos os nomes em ordem alfabetica.                  ]\n");
	printf("[ (3) = Listar todos os nomes que contem uma substring fornecida.   ]\n");
	printf("[ (4) = Inserir um novo nome na memoria.                            ]\n");
	printf("[ (4) = Remover um nome da memoria.                                 ]\n");
	printf("[ (4) = Listar e remover da memoria todos os nomes que sao maiores  ]\n");
	printf("[ (4) = Listar e remover da memoria todos os nomes que sao menores. ]\n");
	printf("[ (4) = Salvar o conteudo da memoria em um arquivo texto.           ]\n\n");
	printf("[ (8) = SAIR DO PROGRAMA                                            ]\n");
	printf("                                                   \n");
	printf("Selecione uma das opcoes acima\n");
	
}

void menuPrincipal() {
	apresentacao();
		
}

void valorInvalido(){
	printf("O valor inserido e invalido");
}

int main(int argc, char *argv[]) {
	
	menuPrincipal();
	
}
