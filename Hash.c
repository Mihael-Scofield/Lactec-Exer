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

	system("clear");

	printf("Por favor, digite a ID do cliente: \n");
	scanf("%d", &novo_cliente->ID);
	
	printf("\nAgora, digite o nome dele: \n");
	scanf(" %[^\n]s", novo_cliente->nome); // Importante ter um espaço antes do "%[^\n]s". Pois ele é utilizado para ignorar os espaços vazios.
	
	printf("\nQual a idade do cliente? \n");
	scanf("%d", &novo_cliente->idade);

	printf("\nPor fim, qual o telefone do cliente? \n");
	scanf(" %[^\n]s", novo_cliente->telefone);

	novo_cliente->prox = NULL;
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

/* Extrai um nó da lista e o devolve para impressão/manipulação */
struct cliente* extrai_cadastro(struct cliente* lista, int ind_encontrado) {
	int i = 0;
	struct cliente* lista_aux = lista; // Para não perder meu ponteiro de inicio/final da lista.
	
	while (i != ind_encontrado) {
		lista_aux = lista_aux->prox;
		i++; // Avanço até chegar no nó que desejo extrair
	}
	return lista_aux;
}

/* Trava fluxo do programa, afim de permitir leitura do usuário. */
void press_s(void) {
	char ch;

	printf("\nPor favor, aperte 's' para voltar ao menu inicial\n");
	while (ch != 's') {
		scanf("%c", &ch);
	}
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
		/* Cadastramento */
		hash[indice].head = novo_cliente; // Inicio a lista.
		hash[indice].tail = novo_cliente;
		*qnt += 1;

		/* Interação com usuário */
		system("clear");
		printf("Usuario cadastrado com sucesso! \n");
		press_s();
	}
	else { // Já existe uma lista vinculada a esta posição.
		int ind_encontrado;
		ind_encontrado = procura_na_lista(lista, novo_cliente->ID); // Procuro se o cliente já existe na lista atual.
		if (ind_encontrado == -1) { // Não encontrei, basta adicionar no final da lista.
			/* Cadastramento */
			hash[indice].tail->prox = novo_cliente;
			hash[indice].tail = novo_cliente;
			*qnt += 1;

			/* Interação com usuário */
			system("clear");
			printf("Usuario cadastrado com sucesso! \n");
			press_s();
		}
		else {
			system("clear");
			printf("Usuário já existente nos cadastros. Não há necessidade de cadastra-lo. \n");
			press_s();
		}
	}
}

/* Busca algum cliente cadastrado no sistema */
void busca_hash(struct listaHash* hash) {
	int ID_b, idade_b; // ID e Idade a buscar.
	
	/* Levantamento de dados */
	system("clear");
	printf("Para buscar o cliente, por favor, digite o ID do cliente.\n");
	scanf("%d", &ID_b);
	printf("Agora, para agilizar a busca, por favor digite a idade do cliente. \n");
	scanf("%d", &idade_b);
	system("clear");
	printf("Procurando... \n\n");

	int indice = func_hash(idade_b); // Procura indice onde se encontra o cliente.

	struct cliente* lista;
	lista = (struct cliente*) hash[indice].head; // Extrai a lista da posição atual.

	/* Busca propriamente dita */
	if (lista == NULL) { // Não existe lista
		printf("Cliente não encontrado \n");
		press_s();
		}
	else { // Já existe uma lista vinculada a esta posição.
		int ind_encontrado;
		ind_encontrado = procura_na_lista(lista, ID_b); // Procuro cliente na lista.
		if (ind_encontrado == -1) { // Não o encontrei
			printf("Cliente não encontrado 2 \n");
			press_s();
		}
		else { // Achei o cadastro do cliente, preciso extrair seus dados
			/* Extração de informações. */
			struct cliente* cliente_buscado;
			cliente_buscado = extrai_cadastro(lista, ind_encontrado);

			/* Impressão de informações */
			printf("Cliente encontrado! Suas informações são: \n");
			printf("ID: %d \n", cliente_buscado->ID);
			printf("Nome: %s \n", cliente_buscado->nome);
			printf("Idade: %d \n", cliente_buscado->idade);
			printf("Telefone: %s \n", cliente_buscado->telefone);
			press_s();	
		}
	}
}

// -----------------------------------------------------------------------------------------------------------------
/* Fim das funções principais. */
// ----------------------------------------------------------------------------------------------------------------













