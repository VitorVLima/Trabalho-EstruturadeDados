#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
 
int main(){

    LinkedList * lista = LinkedList_create();
    LinkedList_add_Order(lista,14);
    LinkedList_add_Order(lista,10);
    LinkedList_add_Order(lista,5);
    LinkedList_add_Order(lista,18);
    LinkedList_add_Order(lista,12);
    LinkedList_print(lista);
    LinkedList_add_Order(lista,9);
    LinkedList_print(lista);

    




    return 0;
}