/* Mihael Scofield de Azevedo, Junho - 2019 */
/* Arquivo focado no tratamento da Hash */

#include "Includes.h"

/* Inicializa a tabela hash, setando todas as posições como vázia. */
void inicia_hash(struct listaHash* hash) {
	int i = 0;
	for (i = 0; i < MAX; i++) {
		hash[i].head = NULL;
		hash[i].tail = NULL;
	}
}