// Doubly Linked List Implementation
// ----------------------------------
// Goal: Create a doubly linked list structure with operations to insert at beginning, end, and in order;
//       search for a node; remove a node; display the list; and free allocated memory.
// Trains: structs, dynamic memory (malloc/free), pointer manipulation (prev/next), linked list logic.

#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"

// ====================== Structs ======================

typedef struct Node {
    int key;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
} DoublyLinkedList;

// ====================== Core Functions ======================

void createDoublyLinkedList(DoublyLinkedList* list) {
    list->head = NULL;
}

int isEmpty(const DoublyLinkedList* list) {
    return (list->head == NULL);
}

void freeList(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
}

// ====================== Insertion ======================

void insertAtBeginning(DoublyLinkedList* list, int key) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        puts("Memory allocation error!");
        exit(1);
    }

    newNode->key = key;
    newNode->prev = NULL;
    newNode->next = list->head;

    if (!isEmpty(list))
        list->head->prev = newNode;

    list->head = newNode;
}

void insertAtEnd(DoublyLinkedList* list, int key) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        puts("Memory allocation error!");
        exit(1);        
    }

    newNode->key = key;
    newNode->next = NULL;

    if (isEmpty(list)) {
        newNode->prev = NULL;
        list->head = newNode;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL)
        current = current->next;

    current->next = newNode;
    newNode->prev = current;
}

void insertInOrder(DoublyLinkedList* list, int key) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        puts("Memory allocation error!");
        exit(1);        
    }

    newNode->key = key;

    if (isEmpty(list) || key < list->head->key) {
        insertAtBeginning(list, key);
        return;
    }

    Node* current = list->head;
    while (current->next != NULL && current->next->key < key)
        current = current->next;

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL)
        current->next->prev = newNode;

    current->next = newNode;
}

// ====================== Other Operations ======================

Node* search(const DoublyLinkedList* list, int key) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->key == key)
            return current;
        current = current->next;
    }
    return NULL;
}

int removeNode(DoublyLinkedList* list, int key) {
    Node* toRemove = search(list, key);
    if (toRemove == NULL)
        return 0;

    if (toRemove->prev != NULL)
        toRemove->prev->next = toRemove->next;
    else
        list->head = toRemove->next;

    if (toRemove->next != NULL)
        toRemove->next->prev = toRemove->prev;

    free(toRemove);
    return 1;
}

void display(const DoublyLinkedList* list) {
    Node* current = list->head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->key);
        current = current->next;
    }
    printf("\n");
}