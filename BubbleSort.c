#include "Lista.h"
#include "Ordenacao.h"

void troca_bubble (No *ant, No *atual) {

    int temp;

    temp = ant->dado;
    ant->dado = atual->dado;
    atual->dado = temp;
}

// Função que implementa o algoritmo de ordenação Bubble Sort.
void bubble_sort (Lista *lista) {
    int i, j;

    No *atual, *anda;

    for (atual = lista->inicio; atual != lista->fim; atual = atual->prox) {
        for (anda = atual->prox; anda != NULL; anda = anda->prox) {
            if (atual->dado > anda->dado)
                troca_bubble(atual, anda);
        }
    }
}
