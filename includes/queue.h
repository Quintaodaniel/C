#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    int cap;
    int frontIndex, rearIndex;
    int* data;
} Queue;

Queue* createQueue(int cap);
void clearQueue(Queue* q);
int isEmpty(const Queue* q);
int isFull(const Queue* q);

void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(const Queue* q);
void destroyQueue(Queue* q);

#endif