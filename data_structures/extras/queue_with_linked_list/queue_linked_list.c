// Linked Queue Implementation (Dynamic)
// -------------------------------------
// Goal: Implement a dynamic queue using a singly linked list, with basic operations such as 
// enqueue, dequeue, front, isEmpty, clear, and destroy.
// Trains: dynamic memory allocation (malloc/free), linked list manipulation, 
// FIFO queue logic, modularization, and safe memory handling.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* frontIndex;
    Node* rearIndex;
} Queue;

Queue* createLinkedQueue() {
    Queue* q = malloc(sizeof(Queue));
    if(!q) {
        puts("Memomory allocation error!");
        exit(1);
    }

    q->frontIndex = NULL;
    q->rearIndex = NULL;
    return q;
}

int isEmpty(const Queue* q) {
    return q->frontIndex == NULL;
}

void enqueue(Queue* q, int value) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        puts("Memory allocation error!");
        exit(1);
    }

    newNode->value = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->frontIndex = q->rearIndex = newNode;
        return;
    }

    q->rearIndex->next = newNode;
    q->rearIndex = newNode;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        puts("Queue is empty!");
        exit(1);
    }

    Node* temp = q->frontIndex;
    int value = temp->value;
    q->frontIndex = q->frontIndex->next;

    if (q->frontIndex == NULL) {
        q->rearIndex == NULL;
    }

    free(temp);
    temp = NULL;

    return value;
}

int front(const Queue* q) {
    if (isEmpty(q)) {
        puts("Queue is empty!");
        exit(1);
    }

    return q->frontIndex->value;
}

void destroyQueue(Queue* q) {
    while (!isEmpty(q)) dequeue(q);
    free(q);
}