#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    Lista* l = criaLista();

    inserirLista_inicio(&l, 23);
    inserirLista_inicio(&l, 40);
    inserirLista_inicio(&l, 10);
    inserirLista_inicio(&l, 20);
    inserirLista_indice(&l, 70,4);
    inserirLista_fim(&l,90);
    imprimeLista(l); 
    return 0;
}
