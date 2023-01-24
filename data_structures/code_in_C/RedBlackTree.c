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
    node *null_of_the_tree;
} root;

/* 
    the value 1 is Red
    the value 0 is black
 */

root *createRedBlackTree(int initialValue) {
    root *rootOfTheTree = malloc(sizeof(root));
    node *firstNode = malloc(sizeof(node));
    node *nullOfT = malloc(sizeof(node));
    nullOfT->father = NULL;
    nullOfT->left = NULL;
    nullOfT->right = NULL;
    nullOfT->value = 1;
    nullOfT->isNullOfT = 1;
    firstNode->value = initialValue;
    firstNode->father = nullOfT;
    firstNode->left = nullOfT;
    firstNode->right = nullOfT;
    firstNode->isNullOfT = 0;
    firstNode->color = 1;
    rootOfTheTree->root_Of_the_rb_tree = firstNode;
    rootOfTheTree->null_of_the_tree = nullOfT;
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
    node *nodeY = nodeX->right;
    nodeX->right = nodeY->left;
    if ( nodeY->left->isNullOfT != 1) {
        nodeY->left->father = nodeX;
    }
    nodeY->father = nodeX->father;
    if (nodeX->father == Tree->null_of_the_tree) {
        Tree->root_Of_the_rb_tree = nodeY;
    }else if (nodeX->father->left = nodeX) {
        nodeX->father->left = nodeY;
    }else {
        nodeX->father->right = nodeY;
    }
    nodeY->left = nodeX;
    nodeX->father = nodeY;
}

void rightRotation(root *Tree, node *nodeY) {
    node *nodeX = nodeY->left;
    nodeY->left = nodeX->right;
    if (nodeX->right->isNullOfT != 1) {
        nodeX->right->father = nodeY;
    }
    nodeX->father = nodeY->father;
    if ( nodeY->father == Tree->null_of_the_tree ) {
        Tree->root_Of_the_rb_tree = nodeX;
    }else if (nodeY->father->left = nodeY) {
        nodeY->father->left = nodeX;
    }else {
        nodeY->father->right = nodeX;
    }
    nodeX->right = nodeY;
    nodeY->father = nodeX;
}

void fixInclusion(root *Tree, node *nodeInserted) {
    node *nodeZ = nodeZ;
    while ( nodeZ->father->color == 1 ) {
        if (nodeZ->father == nodeZ->father->father->left) {
            node *nodeY = nodeZ->father->father->right;
            if (nodeY->color == 1) {
                nodeZ->father->color = 0;
                nodeY->color = 0;
                nodeZ = nodeZ->father;
                nodeZ->color = 1;
            }else { 
                if (nodeZ == nodeZ->father->right) {
                    nodeZ = nodeZ->father;
                    leftRotation(Tree, nodeZ);
                }
                nodeZ->father->color = 0;
                nodeZ->father->father->color = 1;
                rightRotation(Tree, nodeZ->father->father);
            }
        }else {
            node *nodeY = nodeZ->father->father->left;
            if (nodeY->color = 1) {
                nodeZ->father->color = 0;
                nodeY->color = 0;
                nodeZ = nodeZ->father;
                nodeZ->color = 1;
            }else {
                if ( nodeZ = nodeZ->father->left ) {
                    nodeZ = nodeZ->father;
                    rightRotation(Tree, nodeZ);
                }
                nodeZ->father->color = 0;
                nodeZ->father->father->color = 1;
                leftRotation(Tree, nodeZ->father->father);
            }
        }
    };
}

void insertAnode( root *Tree, node *nodeToInsert ) {
    node *nodeY = Tree->null_of_the_tree;
    node *nodeX = Tree->root_Of_the_rb_tree;
    while (nodeX != Tree->null_of_the_tree) {
        nodeY = nodeX;
        if (nodeToInsert->value < nodeX->value) {
            nodeX = nodeX->left;
        }else {
            nodeX = nodeX->right;
        }
    }
    nodeToInsert->father = nodeY;
    if (nodeY = Tree->null_of_the_tree) {
        Tree->root_Of_the_rb_tree = nodeToInsert;
    }else if (nodeToInsert->value < nodeY->value) {
        nodeY->left  = nodeToInsert;
    }else {
        nodeY->right = nodeToInsert;
    }
    nodeToInsert->left = Tree->null_of_the_tree;
    nodeToInsert->right = Tree->null_of_the_tree;
    nodeToInsert->color = 1;
    fixInclusion(Tree, nodeToInsert);
}

int main () {
    return 0;
}






