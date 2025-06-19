#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    Node* left;
    Node* right
} Node;

typedef struct {
    Node* root;
} Tree;

void createTree(Tree* t) {
    t->root = NULL;
}

void isEmpty(Tree* t) {
    return t->root == NULL;
}

Node* createNewNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        puts("Error: memory allocation failed!");
        exit(1);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        Node* newNode = malloc(sizeof(Node));
        if (!newNode) {
            puts("Erro: memory allocation failed!");
            exit(1);
        }

        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (value < root->value) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);

    return root;
}