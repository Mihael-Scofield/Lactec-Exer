/* Mihael Scofield de Azevedo, Junho - 2019 */
/* cabeçalho com as funções focadas no tratamento da Hash */

// -----------------------------------------------------------------------------------------------------------------
/* Início das funções utilitárias. */
/* Possuem diversas chamadas e repetições ao longo do código */
// -----------------------------------------------------------------------------------------------------------------

/* Inicializa a tabela hash, setando todas as posições como vázia. */
void inicia_hash(struct listaHash* Hash);

/* Faz o levantamento de dados para incluir o cliente na tabela */
struct cliente* levantamento_de_dados();

/* Função que calcula o índice da tabela hash */
int func_hash(int chave);

/* Procura um cliente na lista atual, retornando o indice de onde ele está ou -1 caso não se encontre. */
int procura_na_lista(struct cliente* lista, int ID);

/* Extrai um nó da lista e o devolve para impressão/manipulação */
struct cliente* extrai_cadastro(struct cliente* lista, int ind_encontrado);

// -----------------------------------------------------------------------------------------------------------------
/* Fim das funções utilitárias. */
// ----------------------------------------------------------------------------------------------------------------


// -----------------------------------------------------------------------------------------------------------------
/* Início das funções principais. */
/* São chamadas apenas uma vez, mas executam a demanda do fluxo do programa */
// -----------------------------------------------------------------------------------------------------------------

/* Função que faz o cadastro (inserção na tabela Hash) */
void insere_hash(struct listaHash* hash, int *qnt);

/* Busca algum cliente cadastrado no sistema */
void busca_hash(struct listaHash* hash);

// -----------------------------------------------------------------------------------------------------------------
/* Fim das funções principais. */
// ----------------------------------------------------------------------------------------------------------------