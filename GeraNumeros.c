#include <time.h>
#include <stdlib.h>

#define CRESCENTE 0
#define DECRESCENTE 1
#define ALEATORIO 2

// Função que gera um número conforme o modo escohido.
int *gera_numeros (int modo, int qtd) {
    
    int i, *numeros;

    numeros = (int *) malloc (sizeof(int) * qtd);

    srand((unsigned)time(NULL));

    // Gera uma quantidade N para o modo crescente.
    if (modo == CRESCENTE) {
        for (i = 0; i < qtd; i++)
            numeros[i] = i;
    }
    // Gera uma quantidade N para o modo decrescente.
    else if (modo == DECRESCENTE) {
        int aux = qtd-1;

        for (i = 0; i < qtd; i++) {
            numeros[i] = aux;
            aux--;
        }
    }
    // Gera uma quantidade N para o modo aleatório.
    else if (modo == ALEATORIO) {
        for (i = 0; i < qtd; i++)
            numeros[i] = 1 + rand() % qtd;
    }
    else {
        printf("\nModo invalido!\n\n");
    }

    return numeros;
}

// Função que retorna um vetor de números inteiros em ordem crescente.
int *crescente (int modo, int qtd) {
    return gera_numeros(modo, qtd);
}

// Função que retorna um vetor de números inteiros em ordem decrescente.
int *decrescente (int modo, int qtd) {
    return gera_numeros(modo, qtd);
}

// Funão que retorna um vetor de números inteiros de forma randômica.
int *aleatorio (int modo, int qtd) {
    return gera_numeros(modo, qtd);
}