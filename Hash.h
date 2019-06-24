/* Mihael Scofield de Azevedo, Junho - 2019 */
/* cabeçalho com as funções focadas no tratamento da Hash */

/* Inicializa a tabela hash, setando todas as posições como vázia. */
void inicia_hash(struct listaHash* Hash);

/* Faz o levantamento de dados para incluir o cliente na tabela */
struct cliente* levantamento_de_dados();

/* Função que calcula o índice da tabela hash */
int func_hash(int chave);

/* Procura um cliente na lista atual, retornando o indice de onde ele está ou -1 caso não se encontre. */
int procura_na_lista(struct cliente* lista, int ID);

/* Função que faz o cadastro (inserção na tabela Hash) */
void insere_hash(struct listaHash* hash, int qnt);
