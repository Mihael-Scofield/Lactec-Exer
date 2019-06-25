/* Mihael Scofield de Azevedo, Junho - 2019 */
/* Main que controla o fluxo do programa, contendo
   as chamadas para os demais arquivos */

#include "Includes.h"

/* Responsável pelo controle de fluxo do programa e impressão dos menus */
int main (void) {
	/* Inicialização da Hash. */
	struct listaHash* hash;
	hash = (struct listaHash*) malloc(MAX * sizeof(struct listaHash)); // Aponta para inicio da hash (Vetor de tamanho MAX)
	inicia_hash(hash);
	int qnt; // Quantidade de itens atuais na tabela
	qnt = 0; 

	/* Impressão do menu. */
	int escolha, controle;
	controle = 1;

	system("clear"); // Introdução inicial ao usuário.
	printf("Ola! Seja bem-vindo ao sistema de cadastramento de clientes. \n");
	do {
		printf("Por favor, selecione quais das opcoes abaixo deseja executar: \n");
		printf( "\n1. Cadastramento de cliente;" // Menu propriamente dito.
				"\n2. Busca de cliente;"
				"\n3. Exclusao de cadastro;"
				"\n4. Sair. \n\n");
		scanf("%d", &escolha);

		switch(escolha) { // Direcionamento do tratamento a Hash
			case 1:
				insere_hash(hash, &qnt);
				break;

			case 2:
				busca_hash(hash);
				break;

			case 3:
				remove_hash(hash);
				break;

			case 4:
				printf("Usuário escolheu sair. \n");
				sleep(2);
				controle = 0; // Diz ao programa que deve encerrar.
				break;

			default:
				printf("Opcao invalida, poderia digitar novamente uma das 4 opcoes? \n");
				sleep(2);
				break;		
		} 
		system("clear");
	} while (controle == 1);
	return 0;
}