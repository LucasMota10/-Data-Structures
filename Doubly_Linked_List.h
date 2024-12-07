#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST
#define MAX 10
#include <stdio.h>

typedef struct {
    struct node *tp_prox;
    struct node *tp_ant;
    int val;
} node;

typedef struct{
    int start;
    int end;
    int length;
    node itens[MAX];
} list;

void inicialize_list(list *aux){
    aux->start = -1;
    aux->end = -1;
    aux->length = 0;
}

int empty(list aux){
    
    return aux.length == 0;

}

int insert_end(list *aux, int x){

    if(aux->length >= MAX){
        printf("Lista Cheia!\n");
        return 0;
    }

    if(aux->length == 0){
        aux->itens[0].val = x; 
        aux->itens[0].tp_prox = NULL;
        aux->itens[0].tp_ant = NULL;
        aux->end = 0;
        aux->start = 0;    
    }
    else{
        int new_index = aux->end+1;
        aux->itens[new_index].val = x;
        aux->itens[new_index].tp_ant = &aux->itens[new_index-1];
        aux->itens[new_index].tp_prox = NULL;
        aux->itens[aux->end].tp_prox = &aux->itens[new_index];
        aux->end = new_index;
    }   
    aux->length++;
    return 1;
}

int insert_start(list *aux, int x){

    if(aux->length >= MAX){
        printf("Lista Cheia!\n");
        return 0;
    }

    if(aux->length == 0){
        aux->itens[0].val = x; 
        aux->itens[0].tp_prox = NULL;
        aux->itens[0].tp_ant = NULL;
        aux->end = 0;
        aux->start = 0;    
    }
    else{
        int new_index = aux->start-1;
        aux->itens[new_index].val = x;
        aux->itens[new_index].tp_ant = NULL;
        aux->itens[new_index].tp_prox = &aux->itens[aux->start];
        aux->itens[aux->start].tp_ant = &aux->itens[new_index];
        aux->start = new_index;
    }   
    aux->length++;
    return 1;
}

int pop_end(list *aux){
    if(aux->length == 0){
        printf("Lista Vazia!\n");
        return 0;
    }
    if(aux->length == 1){
        aux->start = -1;
        aux->end = -1;
    }else{
        aux->end--;
        aux->itens[aux->end].tp_prox = NULL;
        aux->itens[aux->end + 1].tp_ant = NULL;
    }
    aux->length--;
    return 1;
}

void print_list(list *aux) {
    if (empty(*aux)) {
        printf("Lista Vazia!\n");
        return;
    }

    printf("Lista: ");
    for (int i = aux->start; i <= aux->end; i++) {
        printf("%d ", aux->itens[i].val);
    }
    printf("\n");
}
    
#endif