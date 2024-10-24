#ifndef LISTA_H
#define LISTA_H
#include <stdbool.h>

typedef struct _node Node;
typedef struct _linked_list LinkedList;

Node * Node_create( int val); //Cria novo nó
LinkedList * LinkedList_create(); //Cria nova lista
void LinkedList_add_first(LinkedList *L, int val); //Adiciona no inicio
void LinkedList_add_last(LinkedList *L, int val); //Adiciona no fim
void LinkedList_add_element(LinkedList *L, int val, int index); //Adiciona no índice passado pelo usuário
bool LinkedList_empty(LinkedList *L); //Verifica se a lista está vazia
void LinkedList_Order(LinkedList *L); //Ordena em ordem crescente os valores já adicionados
void LinkedList_add_Order(LinkedList *L, int val); //Insere novo valor em ordem crescente
void LinkedList_search(LinkedList *L, int index); //Pesquisa elemento pelo índice da posição na lista
void LinkedList_remove_first(LinkedList *L); //Remove primeiro elemento
void LinkedList_remove_last(LinkedList *L); //Remove ultimo elemento
void LinkedList_remove_element(LinkedList *L, int index); //Remove elemento na posição do indice passado
void LinkedList_print(LinkedList *L); //Exibe elementos


#endif