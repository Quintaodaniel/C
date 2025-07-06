#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

void createList(LinkedList* list);
int isEmpty(const LinkedList* list);
void freeList(LinkedList* list);

void insertAtBeginning(int value, LinkedList* list);
void insertAtEnd(int value, LinkedList* list);
void insertInOrder(int value, LinkedList* list);
void insertAtIndex(int value, int index, LinkedList* list);

void removeFromBeginning(LinkedList* list);
void removeFromEnd(LinkedList* list);
void removeByValue(int value, LinkedList* list);
void removeByIndex(int index, LinkedList* list);

void printList(const LinkedList* list);
int listSize(const LinkedList* list);

Node* searchByValue(int value, const LinkedList* list);
Node* searchByIndex(int index, const LinkedList* list);

void reverseList(LinkedList* list);
void concatenateLists(LinkedList* list1, LinkedList* list2);

#endif