#ifdef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

typedef struct Node {
    int key;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
} DoublyLinkedList;


void createDoublyLinkedList(DoublyLinkedList* list);
int isEmpty(const DoublyLinkedList* list);
void freeList(DoublyLinkedList* list);

void insertAtBeginning(DoublyLinkedList* list, int key);
void insertAtEnd(DoublyLinkedList* list, int key);
void insertInOrder(DoublyLinkedList* list, int key);

Node* search(const DoublyLinkedList* list, int key);
int removeNode(DoublyLinkedList* list, int key);
void display(const DoublyLinkedList* list);

#endif