#include <stdio.h>

#define MAX 10

typedef int node;

typedef struct pilha {

    int topo;
    node item[MAX];

} pilha;

void initpilha(pilha *aux){
    aux->topo = -1;
}

int empty(pilha *aux){
    if(aux->topo == -1){
        printf("Pilha Vazia!");
        return 1;
    }else{  
        return 0;
    }
}

int push(pilha *aux, int element){
    
    if(aux->topo < MAX-1){
        aux->topo++;
        aux->item[aux->topo] = element;  
        return 1;
    } else return 0;
    
}

int pop(pilha *aux){

    if(!empty(aux)){
        return aux->item[aux->topo--];
    } else return 0;
}

int top(pilha aux){

    if(!empty(&aux)){

        return aux.item[aux.topo];

    } else return 0;
}

int altura(pilha aux){

    return aux.topo + 1;
}

void clear(pilha *aux){

    aux->topo = -1;
}

void show(pilha aux){

    for(int i = aux.topo; i > -1; i--){
        printf("%d\n",aux.item[i]);
    }
    
}

int main(){
    pilha aux;
    initpilha(&aux);
}