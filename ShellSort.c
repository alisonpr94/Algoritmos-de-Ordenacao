#include "Ordenacao.h"
#include "Lista.h"

// Função que implementa o algoritmo de ordenação Shell Sort.
void shell_sort (Lista *lista) {
    No *inicio = lista->inicio;
    
    if (inicio) {
        int step = 0;
        int lenght = 0;
        No *p = inicio;
        while (p) {
            lenght++;
            p = p->prox;
        }
        while (2*(3*step+1) <= lenght)
            step = 3*step+1;
        for (step;step>0;step/=3) {
            for (int i=step;i>0;i--) {
                for (int j=step-i;j<lenght;j+=step) {
                    p = inicio;
                    int k;
                    for (k=0;k<j;k++)
                        p = p->prox;
                    No *c=p;
                    int temp = k+step;
                    while (c) {
                        for(k;k<temp;) {
                            if (c) {
                                k++;
                                c=c->prox;
                            }
                            else {
                                break;
                            }
                            if(c) {
                                if(p->dado>c->dado){
                                    int t=p->dado;
                                    p->dado=c->dado;
                                    c->dado=t;
                                }
                                temp+=step;
                            }
                        }
                    }
                }
            }
        }
    }
}