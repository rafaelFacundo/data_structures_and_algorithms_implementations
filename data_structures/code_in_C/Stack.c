#include <stdio.h>
#include <stdlib.h>

typedef struct node_ {
    int value;
    struct node_ * up;
    struct node_ * down;
    
} node;

typedef struct Stack_ {
    node *firstElement;
} stack;



void add_node_to_stack(stack *theStack) {
    node* newNode = malloc(sizeof(node));
    
    printf("digite o valor: ");
    scanf("%d", &newNode->value);
    if ( theStack->firstElement != NULL ) {
        theStack->firstElement->up = newNode;
        newNode->down = theStack->firstElement;
        theStack->firstElement = newNode;
    }else {
        theStack->firstElement = newNode;
        newNode->down = NULL;
    }
    
}

void remove_from_stack(stack* stack) {
    node *holdingNode = stack->firstElement;
    if ( stack->firstElement != NULL ) {
        stack->firstElement = holdingNode->down;
        stack->firstElement->up = NULL;
    }else {
        printf("A pilha já está vazia");
    }
    free(holdingNode);
}

void printeStack(stack* theStack) {
    node *nodeToPrint = theStack->firstElement;
    if ( nodeToPrint != NULL ) {
        while (nodeToPrint != NULL) {
            printf("----------\n");
            printf("|   %d    |\n", nodeToPrint->value);
            nodeToPrint = nodeToPrint->down;
        }
        printf("----------\n");
    }else {
        printf("pilha vazia, não é possível printá-la.");
    }
}


int main() {
    stack *theStack = malloc(sizeof(stack));
    add_node_to_stack(theStack);
    add_node_to_stack(theStack);
    add_node_to_stack(theStack);
    add_node_to_stack(theStack);
    printf("antes\n");
    printeStack(theStack);
    remove_from_stack(theStack);
    printf("depois\n");
    printeStack(theStack);
}