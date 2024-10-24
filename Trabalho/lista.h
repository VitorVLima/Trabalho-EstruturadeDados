#ifndef LISTA_H
#define LISTA_H

typedef struct _node Node;
typedef struct _linked_list LinkedList;

LinkedList * LinkedList_create(); //Cria nova lista
Node * Node_create(); //inicializa dados de nova fruta
void LinkedList_add(LinkedList *L); //Adiciona nova fruta a lista (adiciona no início da lista)
void LinkedList_print(const LinkedList *L); //Exibe frutas cadastradas
void LinkedList_search(const LinkedList *L); //Pesquisa elemento pelo índice da posição na lista
void LinkedList_remove(LinkedList *L); //Remove elemento na posição do indice passado
void LinkedList_update(LinkedList *L); //Altera dados do elemento selecionado
void LinkedList_sell(LinkedList *L); //funcão de venda e impressão em arquivo txt
#endif