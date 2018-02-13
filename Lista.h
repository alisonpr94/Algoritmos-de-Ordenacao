#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;
    struct no *ant;
} No;

typedef struct lista {
    int tamanho;
    No *inicio;
    No *fim;
} Lista;

void inicializa (Lista *lista);

int lista_vazia (Lista *lista);

void inserir_inicio (Lista *lista, int valor);

void inserir_fim (Lista *lista, int valor);

void imprimir_lista (Lista *lista);

void liberar_lista (Lista *lista);

#endif