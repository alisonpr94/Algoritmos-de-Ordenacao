#include "Ordenacao.h"
#include "Lista.h"

void troca_selection (No *i, No *min) {
    int temp;

    temp = i->dado;
    i->dado = min->dado;
    min->dado = temp;
}

// Função que implementa o algoritmo de ordenação Selection Sort.
void selection_sort (Lista *lista) {
    No  *i, *j, *min;

    for (i = lista->inicio; i != lista->fim; i = i->prox) {
        min = i;

        for (j = i->prox; j != NULL; j = j->prox) {
            if (j->dado < min->dado)
                min = j;
        }

        if (i != min)
            troca_selection(i, min);
    }
}