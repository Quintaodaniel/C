// Queue Implementation (Circular Dynamic)
// ---------------------------------------
// Goal: Create a circular queue structure with enqueue, dequeue, front, isEmpty, isFull, clear, and destroy operations.
// Trains: structs, dynamic memory (malloc/free), queue logic with circular indexing, error handling.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cap;
    int frontIndex, rearIndex;
    int* data;
} Queue;

Queue* createQueue(int cap) {
    Queue* q = malloc(sizeof(Queue));
    if (!q) {
        puts("Memory allocation error for the queue!");
        exit(1);
    }

    q->frontIndex = -1;
    q->rearIndex = -1;
    q->cap = cap;
    q->data = malloc(cap * sizeof(int));

    if (!q->data) {
        puts("Memory allocation error for the queue array!");
        free(q);
        exit(1);
    }

    return q;
}

void clearQueue(Queue* q) {
    q->frontIndex = -1;
    q->rearIndex = -1;
}

int isEmpty(const Queue* q) {
    return (q->frontIndex == -1);
}

int isFull(const Queue* q) {
    return ((q->rearIndex + 1) % q->cap == q->frontIndex);
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        puts("Error: Queue is full!");
        return;
    }

    if (isEmpty(q)) {
        q->frontIndex = 0;
    }

    q->rearIndex = (q->rearIndex + 1) % q->cap;
    q->data[q->rearIndex] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        puts("Error: Queue is empty!");
        exit(1);
    }

    int value = q->data[q->frontIndex];

    if (q->frontIndex == q->rearIndex) {
        clearQueue(q);
    } else {
        q->frontIndex = (q->frontIndex + 1) % q->cap;
    }

    return value;
}

int front(const Queue* q) {
    if (isEmpty(q)) {
        puts("Error: Queue is empty!");
        exit(1);
    }

    return q->data[q->frontIndex];
}

void destroyQueue(Queue* q) {
    if (q != NULL) {
        free(q->data);
        free(q);
    }
}
