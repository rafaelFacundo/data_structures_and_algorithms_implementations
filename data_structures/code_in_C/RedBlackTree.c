#include <stdio.h>
#include <stdlib.h>

typedef struct node_ {
    struct node_ *father;
    struct node_ *right;
    struct node_ *left;
    int isNullOfT;
    int color;
    int value;
} node;



typedef struct root_ {
    node *root_Of_the_rb_tree;
} root;

/* 
    the value 1 is Red
    the value 0 is black
 */

root *createRedBlackTree(int initialValue) {
    root *rootOfTheTree = malloc(sizeof(root));
    node *firstNode = malloc(sizeof(node));
    node *nullOfT = malloc(sizeof(node));
    nullOfT->isNullOfT = 1;
    firstNode->value = initialValue;
    firstNode->father = nullOfT;
    firstNode->left = nullOfT;
    firstNode->right = nullOfT;
    firstNode->isNullOfT = 0;
    firstNode->color = 1;
    rootOfTheTree->root_Of_the_rb_tree = firstNode;
    return rootOfTheTree;
};

void printTheRBTreeInOrder(node *nodeToPrint) {
    if (nodeToPrint->isNullOfT == 0) {
        printTheRBTreeInOrder(nodeToPrint->left);
        printf("%d - ", nodeToPrint->value);
        printTheRBTreeInOrder(nodeToPrint->right);
    };
}

void runThroughtTreeToPrint(node *nodeToStart) {
    printTheRBTreeInOrder(nodeToStart);
    printf("\n");
}

void leftRotation (root *Tree, node *nodeX) {
    node *nodeY = nodeX->left;
    nodeX->right = nodeY->left;
    if ( nodeY->left->isNullOfT != 1) {
        nodeY->left->father = nodeX;
    }
    nodeY->father = nodeX->father;
    if (nodeX->father->isNullOfT == 1) {
        Tree->root_Of_the_rb_tree = nodeY;
    }else if (nodeX->father->left = nodeX) {
        nodeX->father->left = nodeY;
    }else {
        nodeX->father->right = nodeY;
    }
    nodeY->left = nodeX;
    nodeX->father = nodeY;
}



int main () {
    return 0;
}






