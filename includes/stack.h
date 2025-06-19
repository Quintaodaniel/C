#ifndef STACK_H
#define STACK_H

typedef struct {
    int arrayCapacity;
    int topIndex;
    int* data;
} Stack;

Stack* createStack(int capacity);
void clear(Stack* s);
int isEmpty(Stack* s);
int isFull(Stack* s);

void push(Stack* s, int value);
int pop(Stack* s);
int top(Stack* s);
void destroyStack(Stack* s);

#endif