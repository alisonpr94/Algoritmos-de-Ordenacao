#include "Ordenacao.h"
#include "Lista.h"

void swap_quick (int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

No *particiona (No *l, No *h) {
    // Elemento pivô.
    int pivo = h->dado;

    No *j, *i = l->ant;

    for (j = l; j != h; j = j->prox) {
        if (j->dado <= pivo) {
            // Similar ao i++ para o array.
            i = (i == NULL) ? l : i->prox;
            swap_quick(&(i->dado), &(j->dado));
        }
    }

    i = (i == NULL) ? l : i->prox; // Similar a i++.
    swap_quick(&(i->dado), &(h->dado));
    return i;
}

// Implementação recursiva.
void _quick_sort (No *l, No *h) {
    if (h != NULL && l != h && l != h->prox){
        No *p = particiona(l, h);
        _quick_sort(l, p->ant);
        _quick_sort(p->prox, h);
    }
}

// Função que implementa o algoritmo de ordenação Quick Sort.
void quick_sort (Lista *lista) {
    // Recebe o final da lista.
    No *h = lista->fim;

    // Chamada recursiva do quick sort.
    _quick_sort(lista->inicio, h);
}