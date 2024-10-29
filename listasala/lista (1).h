#ifndef LISTA_H
#define LISTA_H

struct lista {
    int info;
    struct lista *prox;
}; 

typedef struct lista Lista;

Lista* criaLista();
void inserirLista_inicio(Lista **lista, int i); 
void inserirLista_fim(Lista **lista, int i);
void inserirLista_indice(Lista **lista, int i, int index);
void imprimeLista(Lista *l); 

#endif
