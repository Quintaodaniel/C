// Binary Tree Implementation
// ----------------------------------
// Goal: Create a Binary Tree structure with operations to initialize the tree, insert nodes,
//       search for a value, remove a node, traverse the tree (pre-order, in-order, post-order),
//       compute the tree's height, count total nodes, and free the allocated memory.
// Trains: structs, dynamic memory (malloc/free), pointer manipulation (left/right), 
//         binary tree logic (insertion, deletion, traversal), and recursion.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* root;
} Tree;

void createTree(Tree* t) {
    t->root = NULL;
}

int isEmpty(Tree* t) {
    return t->root == NULL;
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d", root->value);
        inOrder(root->right);
    }
}

void posOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        inOrder(root->right);
        printf("%d", root->value);
    }
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
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
    if (value == root->value) {
        puts("This value already exists in the tree!");
    } else if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

void insert(Tree* t, int value) {
    t->root = insertNode(t->root, value);
}

Node* search(Node* root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    } else if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

Node* removeNode(Node* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    if (value < root->value) {
        root->left = removeNode(root->left, value);
    } else if (value > root->value) {
        root->right = removeNode(root->right, value);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;

        } else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;

        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;

        } else {
            Node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->value = temp->value;
            root->right = removeNode(root->right, temp->value);
        }
    }
    return root;
}

int height(Node* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void clear(Node* root) {
    if (root != NULL) {
        clear(root->left);
        clear(root->right);
        free(root);
    }
}