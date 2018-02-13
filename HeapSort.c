#include "Ordenacao.h"
#include "Lista.h"

void swap_heap (int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

// Função que implementa o algoritmo de ordenação Heap Sort.
void heap_sort (Lista *lista, No *temp) {

    if (!temp->prox && !temp->ant) 
        return;

    if (!temp->prox) {
        if (temp->ant->dado > temp->dado)
            swap_heap(&temp->ant->dado, &temp->dado);
    }
    else {
        if (temp->prox->dado > temp->ant->dado) {
            if (temp->prox->dado > temp->dado) {
                swap_heap(&temp->prox->dado, &temp->dado);
                heap_sort(lista, temp->prox);
            }
        }
        else {
            if (temp->ant->dado > temp->dado) {
                swap_heap(&temp->ant->dado, &temp->dado);
                heap_sort(lista, temp->ant);
            }
        }
    }
}