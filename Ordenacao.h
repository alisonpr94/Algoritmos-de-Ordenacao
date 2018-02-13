#ifndef ORDENACAO_H
#define ORDENACAO_H

#include "Lista.h"

void bubble_sort(Lista *lista);

void heap_sort(Lista *lista, No *temp);

void insertion_sort(Lista *lista);

void quick_sort(Lista *lista);

void selection_sort(Lista *lista);

void shell_sort(Lista *lista);

#endif