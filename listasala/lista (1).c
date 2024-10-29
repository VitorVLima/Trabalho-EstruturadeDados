#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

Lista* criaLista() {
    return NULL;
}

void inserirLista_inicio(Lista **lista, int i) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL) { // Verifica se a alocação de memória foi bem-sucedida
        fprintf(stderr, "Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    novo->info = i;
    novo->prox = *lista;
    *lista = novo;
}


void inserirLista_fim(Lista **lista, int i) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL) { 
        fprintf(stderr, "Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    
    novo->info = i;
    novo->prox = NULL; 

    if (*lista == NULL) { 
        *lista = novo;
    } else {
        Lista* p = *lista; 
        while (p->prox != NULL) { 
            p = p->prox;
        }
        p->prox = novo; 
    }
}

void inserirLista_indice(Lista **lista, int i, int index) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL) { 
        fprintf(stderr, "Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    novo->info = i;
    novo->prox = NULL;

    if (index == 0) { 
        novo->prox = *lista;
        *lista = novo; 
        return;
    }
    
    int cont = 0;
    Lista* p = *lista;
     for (int cont = 0; cont < index - 1; cont++) {
        if (p == NULL) {
            printf("Lista nao possui elementos suficientes para acessar essa posicao\n");
            free(novo);
            return;
        }
        p = p->prox;
    }
        if (p == NULL) {
        printf("Lista nao possui elementos suficientes para acessar essa posicao\n");
        free(novo);
        return;
        }
        novo->prox = p->prox;
        p->prox = novo;
}


void imprimeLista(Lista *l) { // Mudou o tipo de retorno para void
    Lista *p;
    for (p = l; p != NULL; p = p->prox) {
        printf("%d\n", p->info);
    }
}
