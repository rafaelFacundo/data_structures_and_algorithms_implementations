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

root* createBinaryTree(int valueToInsert) {
    root* rootOfTree = malloc(sizeof(root));
    node* firstNodeOfTree = malloc(sizeof(node));
    firstNodeOfTree->left = NULL;
    firstNodeOfTree->right = NULL;
    firstNodeOfTree->father = NULL;
    rootOfTree->rootOfTree = firstNodeOfTree;
    rootOfTree->rootOfTree->value = valueToInsert;
    return rootOfTree;
}

node* createNodeToInsertInTree(int value) {
    node* newNode = malloc(sizeof(node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->father = NULL;
    newNode->value = value;
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

void addNode(root *rootOfTree, int value) {
    node* newNodeToInsert = createNodeToInsertInTree(value);
    runThroughTreeToInsertNode(rootOfTree, newNodeToInsert);
}

node *minimum(node *rootOfSomeTree) {
    node *nodeToIterate = rootOfSomeTree;
    while(nodeToIterate->left != NULL) {
        nodeToIterate = nodeToIterate->left;
    };
    return nodeToIterate;

}

node *maximum(node *rootOfSomeTree) {
    node *nodeToIterate = rootOfSomeTree;
    while(nodeToIterate->right != NULL) {
        nodeToIterate = nodeToIterate->right;
    };
    return nodeToIterate;
}

void transplant(root *Tree, node *nodeToBeRemoved, node *nodeToBeMoved) {
    if (nodeToBeRemoved->father == NULL) {
        Tree->rootOfTree = nodeToBeMoved;
    }else if (nodeToBeRemoved == nodeToBeRemoved->father->left) {
        nodeToBeRemoved->father->left = nodeToBeMoved;
    }else {
        nodeToBeRemoved->father->right = nodeToBeMoved;
    }

    if (nodeToBeMoved != NULL) {
        nodeToBeMoved->father = nodeToBeRemoved->father;
    }

    //free(nodeToBeRemoved);
}

void removeNodeFromTree(root *Tree, node *nodeToBeRemoved) {
    if ( nodeToBeRemoved->left == NULL ) {
        transplant(Tree, nodeToBeRemoved, nodeToBeRemoved->right);
    }else if ( nodeToBeRemoved->right == NULL ) {
        transplant(Tree, nodeToBeRemoved, nodeToBeRemoved->left);
    }else {
        //getting the successor of the node to be removed
        node *y = minimum(nodeToBeRemoved);
        transplant(Tree, y, y->right);
        y->left = nodeToBeRemoved->left;
        nodeToBeRemoved->left->father = y;
        y->right = nodeToBeRemoved->right;
        if (nodeToBeRemoved->right != NULL) {
            nodeToBeRemoved->right->father = y;
        }
        transplant(Tree, nodeToBeRemoved, y);
    }

    nodeToBeRemoved = NULL;
    free(nodeToBeRemoved);
}

void printTreeInOrder(node* nodeToVisit) {
    if (nodeToVisit != NULL) {
        printTreeInOrder(nodeToVisit->left);
        printf("-%d-", nodeToVisit->value);
        printTreeInOrder(nodeToVisit->right);
    }
}

node *findAnode(root *Tree, int valueToSearch) {
    node *nodeToIterate = Tree->rootOfTree;
    
    while (nodeToIterate != NULL && nodeToIterate->value != valueToSearch){
        if (valueToSearch < nodeToIterate->value) {
            nodeToIterate = nodeToIterate->left;
        }else if (valueToSearch > nodeToIterate->value) {
            nodeToIterate = nodeToIterate->right;
        }
    }
    
   /*  nodeToIterate = NULL;
    free(nodeToIterate); */
    return nodeToIterate;
    
}

void printInOrder(node* nodeToVisit) {
    printTreeInOrder(nodeToVisit);
    printf("\n");
}


int main() {
    root* rootTree = createBinaryTree(5);
    int n = 0;
    while(n < 7) {
        addNode(rootTree, n);
        n += 1;
    }
     printInOrder(rootTree->rootOfTree);
    node *nodeToRemove = findAnode(rootTree, 4);
    printf("valor do no: %d\n", nodeToRemove->value);
    removeNodeFromTree(rootTree, nodeToRemove); 
    printInOrder(rootTree->rootOfTree); 
    return 0;
}