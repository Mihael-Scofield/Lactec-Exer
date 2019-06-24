/* Mihael Scofield de Azevedo, Junho - 2019 */
/* Arquivo focado no tratamento da Hash */

#include "Includes.h"

// -----------------------------------------------------------------------------------------------------------------
/* Início das funções utilitárias. */
/* Possuem diversas chamadas e repetições ao longo do código */
// -----------------------------------------------------------------------------------------------------------------

/* Inicializa a tabela hash, setando todas as posições como vázia. */
void inicia_hash(struct listaHash* hash) {
	int i = 0;
	for (i = 0; i < MAX; i++) {
		hash[i].head = NULL;
		hash[i].tail = NULL;
	}
}

/* Faz o levantamento de dados para incluir o cliente na tabela */
struct cliente* levantamento_de_dados() {
	struct cliente* novo_cliente; // novo_cliente que sera cadastrado.
	novo_cliente = (struct cliente*) malloc(sizeof(struct cliente));

	printf("Por favor, digite a ID do cliente: \n");
	scanf("%d", &novo_cliente->ID);
	
	printf("\nAgora, digite o nome dele: \n");
	scanf(" %[^\n]s", novo_cliente->nome); // Importante ter um espaço antes do "%[^\n]s". Pois ele é utilizado para ignorar os espaços vazios.
	
	printf("\nQual a idade do cliente? \n");
	scanf("%d", &novo_cliente->idade);

	printf("\nPor fim, qual o telefone do cliente? \n");
	scanf(" %[^\n]s", novo_cliente->telefone);

	novo_cliente->prox = NULL;
	printf("\nObrigado! Estamos Adicionando o cadastro do cliente... \n\n");
	return novo_cliente;
}

/* Função que calcula o índice da tabela hash */
int func_hash(int chave) {
	return (chave % MAX);
}

/* Procura um cliente na lista atual, retornando o indice de onde ele está ou -1 caso não se encontre. */
int procura_na_lista(struct cliente* lista, int ID) {
	int ind_encontrado = 0;
	struct cliente* lista_aux = lista; // Para não perder meu ponteiro do inicio/final da lista.

	while (lista_aux != NULL) {
		if (lista_aux->ID == ID) { // Encontrei quem eu estava procurando na lista.
			return ind_encontrado;
		}
		lista_aux = lista_aux->prox; // Passo para o próximo.
		ind_encontrado++;
	}
	return -1; // Caso não tenha encontrado.
}

// -----------------------------------------------------------------------------------------------------------------
/* Fim das funções utilitárias. */
// ----------------------------------------------------------------------------------------------------------------




// -----------------------------------------------------------------------------------------------------------------
/* Início das funções principais. */
/* São chamadas apenas uma vez, mas executam a demanda do fluxo do programa */
// -----------------------------------------------------------------------------------------------------------------

/* Função que faz o cadastro (inserção na tabela Hash) */
void insere_hash(struct listaHash* hash, int *qnt) {
	struct cliente* novo_cliente; // Nó que será adicionado
	novo_cliente = (struct cliente*) malloc(sizeof(struct cliente));
	novo_cliente = levantamento_de_dados();

	int indice = func_hash(novo_cliente->idade); // Cálculo Hash modular para saber onde será adicionado.

	struct cliente* lista;
	lista = (struct cliente*) hash[indice].head; // Extrai a lista da posição atual.

	/* Casos distintos de inserção */
	if (lista == NULL) { // Ainda não existe uma lista no índice atual;
		hash[indice].head = novo_cliente; // Inicio a lista.
		hash[indice].tail = novo_cliente;
		*qnt += 1;	
	}
	else { // Já existe uma lista vinculada a esta posição.
		int ind_encontrado;
		ind_encontrado = procura_na_lista(lista, novo_cliente->ID); // Procuro se o cliente já existe na lista atual.
		if (ind_encontrado == -1) { // Não encontrei, basta adicionar no final da lista.
			hash[indice].tail->prox = novo_cliente;
			hash[indice].tail = novo_cliente;
			*qnt += 1;
		}
		else {
			printf("\nUsuário já existente nos cadastros. Não há necessidade de cadastra-lo. \n");
		}
	}
}

// /* Busca algum cliente cadastrado no sistema */
// int busca_hash(struct listaHash* hash) {
// 	
// }

// -----------------------------------------------------------------------------------------------------------------
/* Fim das funções principais. */
// ----------------------------------------------------------------------------------------------------------------













