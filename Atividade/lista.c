#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

Lista* criaLista() {
    return NULL;
}

void inserirLista_inicio(Lista **lista, int i) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
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

void inserirOrdem(Lista **lista, int i){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL) { 
        fprintf(stderr, "Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    novo->info = i;
    novo->prox = NULL; 

    if(*lista == NULL){
        *lista = novo;
        printf("valor adicionado a lista em ordem crescente\n");
        return;
    }
    Lista * p = *lista;
    Lista * ant = NULL;
    while(p!=NULL && p->info < i){
        ant = p;
        p = p->prox;
    }
    if(ant==NULL){
        *lista = novo;
        novo->prox = p;
    }else{
        ant->prox = novo;
        novo->prox = p;
    }
    printf("valor adicionado a lista em ordem crescente\n");
}


void imprimeLista(Lista *l) { 
    Lista *p;
    for (p = l; p != NULL; p = p->prox) {
        printf("%d\n", p->info);
    }
}

void buscaLista(Lista *l, int val){
    Lista *p;
    for(p = l; p != NULL; p = p->prox){
        if(p->info == val){
            printf("valor %d encontrado na lista\n", val);
            return;
         }
    }
    printf("valor nao encontrado na lista\n");
}

bool listaVazia(Lista **lista){
    if(*lista == NULL){
        return true;
    }else{
        return false;
    }
}

void retiraLista(Lista **lista, int val){
    Lista * ant = NULL;
    Lista * p = *lista;
    while(p != NULL && p->info != val){
        ant = p;
        p = p->prox;
    }
    if(p == NULL){
        printf("valor nao encontrado");
        return;
    }
    if(ant == NULL){
        *lista = p->prox;
    }else{
        ant->prox = p->prox;
    }
    free(p);
    printf("valor removido com sucesso\n");
}

void liberaLista(Lista *l){
    Lista *p = l;
    while(p != NULL){
        //guarda referência para o próximo elemento
        Lista *t = p->prox;
        free(p); //libera a memória apontada por p
        p = t; //faz p apontar para o próximo
    }
    l=NULL;
}