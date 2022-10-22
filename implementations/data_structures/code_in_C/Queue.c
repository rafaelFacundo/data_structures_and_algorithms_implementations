#include <stdio.h>
#include <stdlib.h>

typedef struct node_ {
    int value;
    struct node_ * next;
    struct node_ * previous;
} node;

typedef struct Queue_ {
    node *firstElement;
    node *lastElement;
} queue;

void add_node_to_queue(queue *theQueue) {
    node* newNode = malloc(sizeof(node));
    newNode->next = NULL;
    printf("digite o valor: ");
    scanf("%d", &newNode->value);
    if ( theQueue->lastElement != NULL ) {
        theQueue->lastElement->next = newNode;
        newNode->previous = theQueue->lastElement;
        theQueue->lastElement = newNode;
    }else {
        newNode->previous = NULL;
        theQueue->firstElement = newNode;
        theQueue->lastElement = newNode;
    }
    
}

void remove_from_queue(queue* theQueue) {
    node *holdingNode = theQueue->firstElement;
    if ( theQueue->firstElement != NULL ) {
        theQueue->firstElement = holdingNode->next;
        theQueue->firstElement->previous = NULL;
    }else {
        printf("A fila já está vazia");
    }
    free(holdingNode);
}

void printeQueue(queue* theQueue) {
    node *nodeToPrint = theQueue->firstElement;
    if ( nodeToPrint != NULL ) {
        while (nodeToPrint != NULL) {
            printf("|   %d    ", nodeToPrint->value);
            nodeToPrint = nodeToPrint->next;
        }
        printf("|\n");
    }else {
        printf("pilha fila, não é possível printá-la.");
    }
}


int main() {
    queue *theQueue = malloc(sizeof(queue));
    add_node_to_queue(theQueue);
    add_node_to_queue(theQueue);
    add_node_to_queue(theQueue);
    add_node_to_queue(theQueue);
  
    /* printf("antes\n"); */
    printeQueue(theQueue);
    remove_from_queue(theQueue);
    printf("depois\n");
    printeQueue(theQueue);
}