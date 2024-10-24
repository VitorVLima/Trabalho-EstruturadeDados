#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
int main(){

    LinkedList * lista = LinkedList_create();
    int opcao;
    printf("bem vindo ao mercado de frutas\n");
    printf("digite [1] para cadastrar nova fruta\n[2] para listar frutas em estoque\n[3] para fazer uma busca especifica\n");
    printf("[4] para alterar dados de uma fruta\n[5] para excluir fruta caso esteja sem estoque\n[6] realizar uma venda \n ou [0] para sair ");
    scanf("%d", &opcao);

    while(opcao!=0){
        switch (opcao){
        case 1:
            LinkedList_add(lista);
            break;
        case 2:
            LinkedList_print(lista);
            break;
        case 3:
            LinkedList_search(lista);
            break;
        case 4:
            LinkedList_update(lista);
            break;
        case 5:
            LinkedList_remove(lista);
            break;
        case 6:
            LinkedList_sell(lista);
            break;
        default:
            printf("digito invalido\n");
            break;
        }
        printf("\ndigite [1] para cadastrar nova fruta\n[2] para listar frutas em estoque\n[3] para fazer uma busca especifica\n");
        printf("[4] para alterar dados de uma fruta\n[5] para excluir fruta caso esteja sem estoque\n[6] realizar uma venda \n ou [0] para sair ");
        scanf("%d", &opcao);
    }
    printf("\nfim do programa\n");

    return 0;
}