#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
int main(){

    LinkedList * lista = LinkedList_create();
    int opcao;
    printf("Bem vindo ao mercado de frutas\n");
    
    do {
        printf("Digite [1] para cadastrar nova fruta\n"
               "[2] para listar frutas em estoque\n"
               "[3] para fazer uma busca especifica\n"
               "[4] para alterar dados de uma fruta\n"
               "[5] para excluir fruta caso esteja sem estoque\n"
               "[6] para realizar uma venda\n"
               "[0] para sair: ");
        
        
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n'); 
            opcao = -1; 
        }

        switch (opcao) {
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
            case 0:
                break;
            default:
                printf("Digite invalido, tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    printf("\nFim do programa\n");

    return 0;
}