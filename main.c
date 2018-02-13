/*
*   Autor: Alison Pereira Ribeiro
*   Algoritmos de ordenação - Trabalho de Algoritmos e Estruturas de Dados I
*   
*   - Lista Duplamente encadeada
*   - Bubble Sort
*   - Heap Sort
*   - Insertion Sort
*   - Quick Sort
*   - Selection Sort
*   - Shell Sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Lista.h"
#include "GeraNumeros.c"
#include "Ordenacao.h"
#include "BubbleSort.c"
#include "HeapSort.c"
#include "InsertionSort.c"
#include "QuickSort.c"
#include "SelectionSort.c"
#include "ShellSort.c"

// Inicializa a lista.
void inicializa (Lista *lista) {
    lista->tamanho = 0;
    lista->inicio = NULL;
    lista->fim = NULL;
}

// Verifica se a lista está vazia.
int lista_vazia (Lista *lista) {
    return (lista->tamanho == 0);
}

// Função inserir no início da lista.
void inserir_inicio (Lista *lista, int valor) {
    No *novo = malloc (sizeof(No));

    if (novo == NULL)
        exit(1);

    novo->dado = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if (lista_vazia(lista)) {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else {
        novo->prox = lista->inicio;
        lista->inicio->ant = novo;
        lista->inicio = novo;
    }

    lista->tamanho++;
}

// Função inserir no fim da lista.
void inserir_fim (Lista *lista, int valor) {
    No *novo = malloc (sizeof(No));

    if (novo == NULL)
        exit(1);

    novo->dado = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if (lista_vazia(lista)) {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else {
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
    }

    lista->tamanho++;
}

// Impre a lista.
void imprimir_lista (Lista *lista) {
    No *temp;
    
    if (lista->tamanho == 0) {
        printf("\nA lista esta vazia!\n\n");
        return;
    }
    else {
        for (temp = lista->inicio; temp != NULL; temp = temp->prox)
            printf("%d ", temp->dado);
        printf("\n\n");
    }
}

// Libera memória desalocando a lista.
void liberar_lista (Lista *lista) {
    No *temp, *lixo;

    if (lista->tamanho == 0) {
        printf("\nA lista esta vazia!\n\n");
        return;
    }
    else {
        for (temp = lista->inicio; temp->prox != NULL; temp = temp->prox) {
            lixo = temp;
            lista->tamanho--;
            free(lixo);
        }
        lista->tamanho--;
    }
}

// Função auxiliar que chama as funções de ordenação.
void ordena (Lista *lista, char *algoritmo) {

    if (strcmp(algoritmo, "bubblesort") == 0) {
        bubble_sort(lista);
    }
    else if (strcmp(algoritmo, "heapsort") == 0) {
        heap_sort(lista, lista->inicio->prox);
    }
    else if (strcmp(algoritmo, "insertionsort") == 0) {
        insertion_sort(lista);
    }
    else if (strcmp(algoritmo, "quicksort") == 0) {
        quick_sort(lista);
    }
    else if (strcmp(algoritmo, "selectionsort") == 0) {
        selection_sort(lista);
    }
    else if (strcmp(algoritmo, "shellsort") == 0) {
        shell_sort(lista);
    }
    else {
        printf("\nAlgoritmo incorreto!\n\n");
    }
}

int main (int argc, char *argv[]) {
    clock_t tempo_ini, tempo_fim;
    double tempo_gasto;

    Lista *lista = (Lista *) malloc (sizeof(Lista));

    int i, op, *numeros, k, qtd;
    char *algoritmo;

    op = atoi(argv[1]);
    qtd = atoi(argv[2]);
    algoritmo = argv[3];

    srand((unsigned)time(NULL));
    
    inicializa(lista);

    // Modo crescente.
    if (op == 0) {
        numeros = crescente(0, qtd);
        
        for (i = 0; i < qtd; i++)
            inserir_fim(lista, numeros[i]);
    }
    // Modo decrescente.
    else if (op == 1) {
        numeros = decrescente(1, qtd);
        
        for (i = 0; i < qtd; i++)
            inserir_fim(lista, numeros[i]);
    } 
    // Modo aleatório.
    else if (op == 2) {
        numeros = aleatorio(2, qtd);
        
        for (i = 0; i < qtd; i++)
            inserir_inicio(lista, numeros[i]);
    } 
    else {
        printf("\nOpcao invalida!\n\n");
    }

    //printf("\nLista original:\n");
    //imprimir_lista(lista);

    tempo_ini = clock();
    ordena(lista, algoritmo);
    tempo_fim = clock();

    //printf("\nLista ordenada:\n");
    //imprimir_lista(lista);

    tempo_gasto = (tempo_fim - tempo_ini) / (CLOCKS_PER_SEC / 1000);

    printf("Tempo de execucao do %s: %lf milissegundos\n", algoritmo, tempo_gasto);

    return 0;
}