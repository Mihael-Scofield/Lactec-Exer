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
		printf("Cliente não encontrado. \n");
		press_s();
		}
	else { // Já existe uma lista vinculada a esta posição.
		int ind_encontrado;
		ind_encontrado = procura_na_lista(lista, ID_b); // Procuro cliente na lista.
		if (ind_encontrado == -1) { // Não o encontrei
			printf("Cliente não encontrado. 2 \n");
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

/* Remove elementos da tabela hash */
void remove_hash(struct listaHash* hash) {
	int ID_b, idade_b; // ID e Idade a buscar.
	
	/* Levantamento de dados */
	system("clear");
	printf("Qual o ID do cliente que gostaria de excluir? \n");
	scanf("%d", &ID_b);
	printf("Agora, para agilizar a busca, por favor digite a idade do cliente. \n");
	scanf("%d", &idade_b);
	system("clear");
	printf("Procurando... \n\n");

	int indice = func_hash(idade_b); // Procura indice onde se encontra o cliente.

	struct cliente* lista;
	lista = (struct cliente*) hash[indice].head; // Extrai a lista da posição atual.	

	/* Casos distintos de remoção */
	if (lista == NULL) { // Não existe lista na posição atual.
		printf("O cliente procurado não existe. \n");
		press_s();
	}
	else { // Existe uma lista na posição atual da tabela
		int ind_encontrado;
		ind_encontrado = procura_na_lista(lista, ID_b);
		if (ind_encontrado == -1) { // Cliente não encontrado na lista.
			printf("O cliente procurado não existe. \n");
			press_s();
		}
		else { // Está dentro dessa lista.
			/* Casos de remoção de fila encadeada */
			struct cliente *lista_aux = lista;

			/* Se encontra na cabeça */
			if (lista_aux->ID == ID_b) {
				hash[indice].head = lista_aux->prox;
				free(lista_aux);
				printf("Cliente excluido com sucesso! \n");
				press_s();
				return;
			}
			
			/* Está no meio/cauda da lista */
			while (lista_aux->prox->ID != ID_b) { // Caminho até o prox. ser quem eu quero.
				lista_aux = lista_aux->prox; // Não aponto para quem eu quero, pois ele pode ser a cauda
			}
			if (hash[indice].tail == lista_aux->prox) { // Está na cauda.
				lista_aux->prox = NULL; // Excluo a cauda atual;
				hash[indice].tail = lista_aux; // e aponto para onde estou.
			}
			else { // Está no meio da lista
				free(lista_aux->prox);
				lista_aux->prox = lista_aux->prox->prox; // Simplesmente "pulo", fazendo a exclusão.
			}
			printf("Cliente excluido com sucesso! \n");
			press_s();
		}
	}
}

/* Função que faz a impressão da Hash, conforme solicitado pelo menu */
void listar_clientes(struct listaHash* hash, int opcao) {
	int verificador = 0; // Verifica se existem elementos na Hash.
	struct cliente* lista_aux;

	system("clear");

	/* Aqui é feita a verificação de qual listagem deve ser feita, se é a rápida ou com ordenação.
	 * Fiz aqui em cima, para economizar e evitar comparações dentro do laço, economizando processamento. */
	if (opcao == 0) { // Listagem rápida escolhida
		for (int i = 0; i < MAX; i++) {
			lista_aux = hash[i].head; // Pego cabeça da lista atual;
			if (lista_aux == NULL) { // Não há nada aqui
				continue;
			}
			else { // Existem coisas a serem printadas na lista
				verificador = 1;
				while (lista_aux != NULL) { // Agora caminharei na lista
					printf("ID: %d, Nome: %s \n", lista_aux->ID, lista_aux->nome);
					lista_aux = lista_aux->prox;
				}
			}
		}
	}

	else { // Listagem com Ordenação escolhida.
		for (int i = 0; i < MAX; i++) {
			lista_aux = hash[i].head; // Pego cabeça da lista atual;
			if (lista_aux == NULL) { // Não há nada aqui
				continue;
			}
			else { // Existem coisas a serem printadas na lista
				verificador = 1;
				while (lista_aux != NULL) { // Agora caminharei na lista
					printf("ID: %d, Nome: %s, Idade: %d, Telefone: %s \n", lista_aux->ID, lista_aux->nome, lista_aux->idade, lista_aux->telefone);
					lista_aux = lista_aux->prox;
				}
			}
		}
	}

	if (verificador == 0) { // Não existem elementos na tabela
		printf("Ainda nenhum cliente foi cadastrado na sistema. \n");
	}

	press_s();
}


// -----------------------------------------------------------------------------------------------------------------
/* Fim das funções principais. */
// ----------------------------------------------------------------------------------------------------------------






















