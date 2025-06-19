// Linked Stack Implementation (Dynamic)
// -------------------------------------
// Goal: Implement a stack using a singly linked list with support for core operations such as
// push, pop, top, isEmpty, and destroy.
// Trains: dynamic memory allocation (malloc/free), pointer manipulation, stack logic (LIFO),
// and modularization.


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* prev;
} Node;

typedef struct {
    Node* topNode;
} Stack;

Stack* createLinkedStack() {
    Stack* s = malloc(sizeof(Stack));
    if (!s) {
        puts("Error: memory allocation failed!");
        exit(1);
    }
    s->topNode = NULL;
    return s;
}

int isEmpty(const Stack* s) {
    return s->topNode == NULL;
}

void push(Stack* s, int value) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        puts("Error: memory allocation failed!");
        exit(1);
    }

    newNode->value = value;
    newNode->prev = s->topNode;
    s->topNode = newNode;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        puts("Error: stack is empty!");
        exit(1);
    }

    Node* temp = s->topNode;
    int value = temp->value;
    s->topNode = temp->prev;
    free(temp);
    return value;
}

int top(const Stack* s) {
    if (isEmpty(s)) {
        puts("Error: stack is empty!");
        exit(1);
    }
    return s->topNode->value;
}

void destroyStack(Stack* s) {
    while (!isEmpty(s)) pop(s);
    free(s);
}
