#ifndef BINARY_TREE
#define BINARY_TREE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int val;
    struct node *smaller;
    struct node *bigger;
} node;

typedef struct binary_tree {
    node *root;
    int quantity;
} binary_tree;

node* create_node(int x) {
    node *aux = (node *)malloc(sizeof(node)); 

    if (aux == NULL) {
        printf("Erro: Falha ao alocar memória.\n");
        return NULL;
    }
    aux->bigger = NULL;
    aux->smaller = NULL;
    aux->val = x;
    return aux;
}

binary_tree* inicialize_tree(binary_tree *tree) {
    tree->quantity = 0;
    tree->root = NULL;
    return tree;
}

bool empty(binary_tree *tree) {
    return tree->quantity == 0;
}

void insert_node(binary_tree *tree, node *x) {
    if (empty(tree)) { // Configura a raiz se a árvore estiver vazia
        tree->root = x;
        tree->quantity++;
        return;
    }

    node *aux = tree->root;
    while (1) {
        if (x->val < aux->val) {
            if (aux->smaller == NULL) {
                aux->smaller = x;
                tree->quantity++;
                break;
            } else {
                aux = aux->smaller;
            }
        } else if (x->val > aux->val) {
            if (aux->bigger == NULL) {
                aux->bigger = x;
                tree->quantity++;
                break;
            } else {
                aux = aux->bigger;
            }
        } else {
            // Valor já existe na árvore, não insere novamente
            break;
        }
    }
}

void print_infixo(node *aux) {
    if (aux == NULL) {
        return;
    }

    print_infixo(aux->smaller); // Subárvore esquerda
    printf("%d\n", aux->val);  // Nó atual
    print_infixo(aux->bigger); // Subárvore direita
}

void print_prefix(node *aux){
    if(aux == NULL){
        return ;
    }

    printf("%d\n",aux->val);
    print_prefix(aux->smaller);
    print_prefix(aux->bigger);
}

void print_posfix(node *aux){
    if(aux == NULL){
        return;
    }

    print_posfix(aux->smaller);
    print_posfix(aux->bigger);
    printf("%d\n",aux->val);
}

bool val_exist(node *aux,int x){

    if(aux == NULL){
        return false;
    }

    if(aux->val == x){
        return true;
    }

    if(x > aux->val){
        val_exist(aux->bigger,x);
    }else{
        val_exist(aux->smaller,x);
    }
}

int max_val(binary_tree tree){

    if(empty(&tree)){
        return -1;
    }

    node* aux = tree.root;

    while(aux->bigger != NULL){
        aux = aux->bigger;
    }
    return aux->val;
}

int min_val(binary_tree tree){

    if(empty(&tree)){
        return -1;
    }
    
    node* aux = tree.root;

    while(aux->smaller != NULL){
        aux = aux->smaller;
    }
    return aux->val;
}

#endif
