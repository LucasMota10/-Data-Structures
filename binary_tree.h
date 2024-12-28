#ifndef BINARY_TREE
#define BINARY_TREE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int val;
    struct node *smaller;
    struct node *bigger;
}node;

typedef struct binary_tree{
    node* root;
    int quantity;
}binary_tree;

node* create_node(int x){

    node *aux = (node *)malloc(sizeof(node)); 

    if (aux == NULL) {
        printf("Error: failure to allocate memory.\n");
        return NULL;
    }
    aux->bigger = NULL;
    aux->smaller = NULL;
    aux->val = x;
    return aux;
}

binary_tree* inicialize_tree(binary_tree *tree){
    tree->quantity = 0;
    tree->root = NULL;
    return tree;
}

bool empty(binary_tree *tree){

    if(tree->quantity == 0){
        return true;
    }else{
        return false;
    }
    
}

void insert_node(binary_tree *tree, node *x){
    if(!empty(tree)){
        tree->root = x;
        tree->quantity++;
    }else{
        node *aux = tree->root;
        while(1){
            if(x->val < aux->val){
                if(aux->smaller == NULL){
                    aux->smaller = x;
                    tree->quantity++;
                    break;
                }else{
                    aux = aux->smaller;
                    continue;
                }
            }
            else if(x->val > aux->val){
                if(aux->bigger == NULL){
                    aux->bigger = x;
                    tree->quantity++;
                    break;
                }else{
                    aux = aux->bigger;
                    continue;
                }
            }
            else{
                break;
            }
        }
    }
}

bool remove_node(int x, binary_tree *tree) {
    if (empty(tree)) {
        printf("Error: The tree is empty\n");
        return false;
    }

    node *aux = tree->root;
    node *aux2 = NULL;

    while (aux != NULL) {
        if (x > aux->val) {
            aux2 = aux;
            aux = aux->bigger;
        } else if (x < aux->val) {
            aux2 = aux;
            aux = aux->smaller;
        } else { // Nó encontrado
            // Caso 1: Nó sem filhos
            if (aux->bigger == NULL && aux->smaller == NULL) {
                if (aux2 == NULL) { // É a raiz
                    tree->root = NULL;
                } else if (aux2->bigger == aux) {
                    aux2->bigger = NULL;
                } else {
                    aux2->smaller = NULL;
                }
                free(aux);
            }
            // Caso 2: Nó com um único filho
            else if (aux->bigger == NULL || aux->smaller == NULL) {
                node *child = (aux->smaller != NULL) ? aux->smaller : aux->bigger;
                if (aux2 == NULL) { // É a raiz
                    tree->root = child;
                } else if (aux2->bigger == aux) {
                    aux2->bigger = child;
                } else {
                    aux2->smaller = child;
                }
                free(aux);
            }
            // Caso 3: Nó com dois filhos
            else {
                node *successor = aux->bigger;
                node *successor_parent = aux;

                while (successor->smaller != NULL) {
                    successor_parent = successor;
                    successor = successor->smaller;
                }

                // Substituir valor
                aux->val = successor->val;

                // Ajustar ponteiros do sucessor
                if (successor_parent->smaller == successor) {
                    successor_parent->smaller = successor->bigger;
                } else {
                    successor_parent->bigger = successor->bigger;
                }
                free(successor);
            }

            tree->quantity--; // Decrementar após remoção
            return true;
        }
    }

    // Se não encontrar o valor
    printf("Error: Node with value %d not found\n", x);
    return false;
}

#endif