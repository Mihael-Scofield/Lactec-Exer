/* Mihael Scofield de Azevedo, Junho - 2019 */
/* Cabeçalho responsável pelas estruturas do programa */

/* Representa cada cliente que pode ser cadastrado,
	Na verdade é um nó de lista encadeada */
struct cliente {
	int ID;
	char nome[100];
	int idade; // Chave que será usada.
	char telefone[13]; // 41 91234-5678 é o número mais longo possível.

	struct cliente* prox; // Proximo da lista na posição atual da Hash.
};

/* Lista para ligar cada elemento da posição atual da Hash */
struct listaHash {
	struct cliente* head; // Primeiro elemento da posição atual da Hash;
	struct cliente* tail; // Ultimo elemento da posição atual da Hash.
};