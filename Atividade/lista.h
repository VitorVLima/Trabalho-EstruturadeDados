#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

struct lista {
    int info;
    struct lista *prox;
}; 

typedef struct lista Lista;

Lista* criaLista();
void inserirLista_inicio(Lista **lista, int i); 
void inserirLista_fim(Lista **lista, int i);
void inserirLista_indice(Lista **lista, int i, int index);
void inserirOrdem(Lista **lista, int i);
void imprimeLista(Lista *l); 
void buscaLista(Lista *l, int val);
bool listaVazia(Lista **lista);
void retiraLista(Lista **lista, int val); //retira pelo valor inserido caso exista
void liberaLista(Lista *l);

#endif
