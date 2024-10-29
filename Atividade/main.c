#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

//nome: vitor vinicius lima silva

int main() {
    Lista* l = criaLista();
    
    inserirOrdem(&l, 23);
    inserirOrdem(&l, 40);
    inserirOrdem(&l, 10);
    inserirOrdem(&l, 20);
    imprimeLista(l); 
    if(listaVazia(&l)){
        printf("lista vazia\n");
    }else{
        printf("lista nao vazia\n");
    }
    


    return 0;
}
