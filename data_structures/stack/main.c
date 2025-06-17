// Stack Implementation (Dynamic)
// ------------------------------
// Goal: Create a basic dynamic stack structure with push, pop, top, isEmpty, isFull, clear, and destroy operations.
// Trains: structs, dynamic memory (malloc/free), stack logic, defensive programming.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arrayCapacity;
    int topIndex;
    int* data;
} Stack;

Stack* createStack(int capacity) {
    Stack* s = malloc(sizeof(Stack));
    if (s == NULL) {
        puts("Memory allocation error for stack!");
        exit(1);
    }

    s->topIndex = -1;
    s->arrayCapacity = capacity;
    s->data = malloc(capacity * sizeof(int));
    if (s->data == NULL) {
        puts("Memory allocation error for stack data!");
        free(s);
        exit(1);
    }

    return s;
}

void clear(Stack* s) {
    s->topIndex = -1;
}

int isEmpty(Stack* s) {
    return s->topIndex == -1;
}

int isFull(Stack* s) {
    return s->topIndex == s->arrayCapacity - 1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        puts("Stack is full!");
        exit(1);
    }

    s->topIndex++;
    s->data[s->topIndex] = value;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        puts("Stack is empty!");
        exit(1);
    }

    int value = s->data[s->topIndex];
    s->topIndex--;
    return value;
}

int top(Stack* s) {
    if (isEmpty(s)) {
        puts("Stack is empty!");
        exit(1);
    }

    return s->data[s->topIndex];
}

void destroyStack(Stack* s) {
    if (s != NULL) {
        free(s->data);
        free(s);
    }
}
