#include <stdio.h>
#include <stdlib.h>

typedef struct node_ {
    int value;
    struct node_ *father;
    struct node_ *right;
    struct node_ *left;
} node;

typedef struct root_ {
    node *rootOfTree;
} root;

root* createBinaryTree() {
    root* rootOfTree = malloc(sizeof(root));
    node* firstNodeOfTree = malloc(sizeof(node));
    firstNodeOfTree->left = NULL;
    firstNodeOfTree->right = NULL;
    firstNodeOfTree->father = NULL;
    rootOfTree->rootOfTree = firstNodeOfTree;
    
    printf("Enter the root value: ");
    scanf("%d", &rootOfTree->rootOfTree->value);
    return rootOfTree;
}

node* createNodeToInsertInTree() {
    node* newNode = malloc(sizeof(node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->father = NULL;
    printf("Enter the node value: ");
    scanf("%d", &newNode->value);
    return newNode;
}

void runThroughTreeToInsertNode(root* Tree, node* newNode) {
    node* nodeThatWillBeTheFather = NULL;
    node* nodeImIn = Tree->rootOfTree;
    while (nodeImIn != NULL) {
        nodeThatWillBeTheFather = nodeImIn;
        if ( newNode->value < nodeImIn->value ){
            nodeImIn = nodeImIn->left;
        }else {
            nodeImIn = nodeImIn->right;
        }
    }
    newNode->father = nodeThatWillBeTheFather;
    if (nodeThatWillBeTheFather == NULL) {
        Tree->rootOfTree = newNode;
    }else if (newNode->value < nodeThatWillBeTheFather->value) {
        nodeThatWillBeTheFather->left = newNode;
    }else {
        nodeThatWillBeTheFather->right = newNode;
    }
}

void addNode(root *rootOfTree) {
    node* newNodeToInsert = createNodeToInsertInTree();
    runThroughTreeToInsertNode(rootOfTree, newNodeToInsert);
}

void printTreeInOrder(node* nodeToVisit) {
    if (nodeToVisit != NULL) {
        printTreeInOrder(nodeToVisit->left);
        printf("-%d-", nodeToVisit->value);
        printTreeInOrder(nodeToVisit->right);
    }
}


int main() {
    root* rootTree = createBinaryTree();
    int n = 0;addNode(rootTree);
    while(n < 7) {
        addNode(rootTree);
        n += 1;
    }
    printTreeInOrder(rootTree->rootOfTree);
    return 0;
}