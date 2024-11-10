#include <stdio.h>
#define MAX 10

typedef int node;
typedef struct stack {

    int top;
    node item[MAX];

} stack;

void initstack(stack *aux){
    aux->top = -1;
}

int empty(stack *aux){
    if(aux->top == -1){
        printf("stack empty!");
        return 1;
    }else{  
        return 0;
    }
}

int push(stack *aux, int element){
    
    if(aux->top < MAX-1){
        aux->top++;
        aux->item[aux->top] = element;  
        return 1;
    } else return 0;
    
}

int pop(stack *aux){

    if(!empty(aux)){
        return aux->item[aux->top--];
    } else return 0;
}

int top(stack aux){

    if(!empty(&aux)){

        return aux.item[aux.top];

    } else return 0;
}

int height(stack aux){

    return aux.top + 1;
}

void clear(stack *aux){

    aux->top = -1;
}

void show(stack aux){

    for(int i = aux.top; i > -1; i--){
        printf("%d\n",aux.item[i]);
    }
    
}