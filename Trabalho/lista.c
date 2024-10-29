#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _node{
    int codigo;
    char nome[20];
    int quantidade;
    float preco;
    struct _node *next;
}Node;

typedef struct _linked_list{
    Node *begin;
    Node *end;
}LinkedList;

Node * Node_create(){ //Cria novo nó
    Node * node = (Node*)calloc(1,sizeof(Node));
    printf("digite o nome da fruta a ser adicionada no seu estoque: ");
    getchar(); 
    fgets(node->nome, sizeof(node->nome), stdin);
    node->nome[strcspn(node->nome, "\n")] = 0;
    printf("digite o codigo da fruta: ");
    scanf("%d", &node->codigo);
    getchar(); 
    printf("digite o preco inicial da fruta: ");
    scanf("%f", &node->preco);
    getchar(); 
    printf("digite a quantidade de frutas a serem adicionadas em estoque: ");
    scanf("%d", &node->quantidade);
    getchar();
     node->next = NULL;
    printf("fruta adicionada com sucesso\n");
    printf("\n");

    return node;
}

LinkedList * LinkedList_create(){ //Cria nova lista 
    LinkedList * L = (LinkedList *)calloc(1, sizeof(LinkedList));
    L->begin = NULL;
    L->end = NULL;
    return L;
}



void LinkedList_add(LinkedList *L) {
    Node *new_node = Node_create();
   
    // Verifica se o código já existe na lista
    Node *p = L->begin;
    while (p != NULL) {
        if (new_node->codigo == p->codigo) {
            printf("Codigo digitado ja esta associado a outra fruta, tente novamente\n");
            free(new_node);
            return;
        }
        p = p->next;
    }

    new_node->next = L->begin;
    L->begin = new_node;

    if (L->end == NULL) {
        L->end = new_node; 
    }
}

void LinkedList_print(const LinkedList *L){
     if (L->begin == NULL) { // lista vazia
        printf("Lista vazia\n");
        return;
    }
    Node * p;
    p = L->begin;
    printf("\n");
    while(p != NULL){
        printf("Nome da fruta: %s\n", p->nome);
        printf("Codigo da fruta: %d\n", p->codigo);
        printf("preco da fruta: %.2f\n", p->preco);
        printf("quantidade da fruta: %d\n\n", p->quantidade);
        p = p->next;
    }
}

void LinkedList_search(const LinkedList *L){
    if (L->begin == NULL) { // lista vazia
        printf("Lista vazia\n");
        return;
    }
    Node * p = L->begin;
    int codigo;
    printf("\ndigite o valor do codigo da fruta para buscar seus dados: ");
    scanf("%d", &codigo);
    while(p!= NULL){
        if(p->codigo == codigo){
            printf("codigo encontrado !\n");
            printf("Nome da fruta: %s\n", p->nome);
            printf("Codigo da fruta: %d\n", p->codigo);
            printf("preco da fruta: %.2f\n", p->preco);
            printf("quantidade da fruta: %d\n\n", p->quantidade);
            return;
        }
        p = p->next;
    }
    printf("codigo nao encontrado\n");
}

void LinkedList_remove(LinkedList *L) {
    if (L->begin == NULL) { // Lista vazia
        printf("Lista vazia\n");
        return;
    }

    int codigo;
    printf("\nDigite o valor do codigo da fruta a excluir: ");
    scanf("%d", &codigo);

    Node *p = L->begin;
    Node *ant = NULL;

    while (p != NULL && p->codigo != codigo) {
        ant = p;
        p = p->next;
    }

    if (p == NULL) { // Se o nó não foi encontrado
        printf("Codigo nao encontrado\n");
        return;
    }

    if (p->quantidade > 0) {
        printf("Item nao pode ser removido pois ainda tem estoque\n");
        return;
    }

    if (p == L->begin && p == L->end) { // lista com apenas um elemento
        L->begin = NULL;
        L->end = NULL;
    } else if (p == L->begin) { // elemento a remover é o primeiro
        L->begin = p->next;
    } else if (p == L->end) { // elemento a remover é o último
        L->end = ant;
        ant->next = NULL;
    } else { // elemento a remover está no meio
        ant->next = p->next;
    }

    free(p); 
    printf("Item removido com sucesso\n");
}

void LinkedList_update(LinkedList *L){
    if (L->begin == NULL) { // lista vazia
        printf("Lista vazia\n");
        return;
    }
    Node * p = L->begin;
    int codigo;
    printf("\ndigite o valor do codigo da fruta para alterar seus dados: ");
    scanf("%d", &codigo);
    while(p!= NULL){
        if(p->codigo == codigo){
            printf("digite o novo preco para a(o) %s: ", p->nome);
            scanf("%f", &p->preco);
            getchar(); 
            printf("digite a nova quantidade em estoque para a(o) %s: ", p->nome);
            scanf("%d", &p->quantidade);
            getchar(); 
            printf("dados alterados com sucesso\n");
            return;
        }
        p = p->next;
    }
    printf("codigo nao encontrado\n");
}

void LinkedList_sell(LinkedList *L){
    if (L->begin == NULL) { // lista vazia
        printf("Lista vazia\n");
        return;
    }

    Node * p = L->begin;
    int codigo;
    int quantidade;
    printf("\ndigite o valor do codigo da fruta que deseja vender: ");
    scanf("%d", &codigo);
     while(p!=NULL && p->codigo != codigo){
        p = p->next;
    }

    if (p == NULL) { // Se o nó não foi encontrado
        printf("Codigo nao encontrado\n");
        return;
    }

    printf("digite a quantidade de %s que deseja vender: ", p->nome);
    scanf("%d", &quantidade);

    if(p->quantidade < quantidade){
        printf("estoque de %s insuficiente para venda\n",p->nome);
        return;
    }

     p->quantidade = p->quantidade - quantidade;

    FILE *file = fopen("historico_vendas.txt", "a"); // Abre o arquivo em modo de adição
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para gravar a venda\n");
        return;
    }

    fprintf(file,"=========Historico de venda======\n");
    fprintf(file,"%d unidade de %s\n",quantidade, p->nome);
    fprintf(file,"valor a receber: %.2f\n", quantidade*p->preco);
    fprintf(file,"===================================\n\n");

    fclose(file);
    printf("venda concluida e adicionada ao historico com sucesso.\n");
}





