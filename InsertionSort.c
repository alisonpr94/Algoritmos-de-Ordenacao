#include "Ordenacao.h"
#include "Lista.h"

// Função que implementa o algoritmo de ordenação Insertion Sort.
void insertion_sort (Lista *lista) {
    No *i, *j;
    int chave;

    for (j = lista->inicio->prox; j != NULL; j = j->prox) {
        chave = j->dado;
        i = j->ant;

        while (i->ant != NULL && i->dado > chave) {
            i->prox->dado = i->dado;
            i = i->ant;
        }

        i->prox->dado = chave;
    }
}