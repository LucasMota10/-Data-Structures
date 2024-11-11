#include <stdio.h>
#define MAX 10

typedef int node;

typedef struct{
    int start;
    int end;
    int total;    
    node item[MAX];

}queue;

void inicialize_queue(queue *aux){
    aux->start = 0;
    aux->end = 0;
    aux->total = 0;
}

int empty(queue *aux){
    if(aux->total == 0){ 
        printf("Empty Queue\n\n");
        return 1; 
    } else return 0;
}

int full (queue *aux){
    if(aux->total == MAX){
        printf("Full Queue!\n\n");
        return 1;
    }else return 0;

}
int push(queue *aux, int element){

    if(!full(aux)){
        aux->item[aux->end] = element;
        aux->end++;
        if(aux->end == MAX){
            aux->end = 0;
        }
        aux->total++;
        return 1;        
    } else return 0;
     
}

int pop(queue *aux) {
    if (!empty(aux)) {
        int removed_element = aux->item[aux->start];
        aux->start = (aux->start + 1) % MAX; 
        aux->total--; 
        return removed_element;
    }
    return 0;  
}

void show(queue aux){

    while(aux.total > 0){
        printf("%d ", aux.item[aux.start]);
        aux.start++;
        if(aux.start > MAX-1){
            aux.start = 0;
        }
        aux.total--;
    }
}

