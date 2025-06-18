// Circular Linked List Implementation (Singly)
// --------------------------------------------
// Goal: Implement a circular singly linked list with core operations such as creation,
// insertion at the end, removal by value, printing, and memory deallocation.
// Trains: circular linked struct, dynamic memory management (malloc/free), pointer manipulation,
// traversal without infinite loops, handling edge cases in circular lists, and modularization.


#include <stdio.h>
#include <stdlib.h>
#include "../C/includes/linkedlist.h"

// Functions that differ from a normal linked list

void createCircularLinkedList(LinkedList* list) {
    list->head = NULL;
}

void insertAtEndCircular(LinkedList* list, int key) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        puts("Memory allocation error!");
        exit(1);
    }
    newNode->value = key;

    if (isEmpty(list)) {
        list->head = newNode;
        newNode->next = newNode;
        return;
    }

    Node* currentNode = list->head;
    while (currentNode->next != list->head)
        currentNode = currentNode->next;

    currentNode->next = newNode;
    newNode->next = list->head;
}

void printCircularList(const LinkedList* list) {
    if (isEmpty(list)) {
        printf("List is empty.\n");
        return;
    }

    Node* currentNode = list->head;
    do {
        printf("%d -> ", currentNode->value);
        currentNode = currentNode->next;
    } while (currentNode != list->head);

    printf("(back to head)\n");
}

void removeValueCircular(LinkedList* list, int key) {
    if (isEmpty(list)) {
        printf("List is empty.\n");
        return;
    }

    Node *current = list->head, *previous = NULL;
    if (current->value == key && current->next == current) {
        free(current);
        list->head = NULL;
        return;
    }

    if (current->value == key) {
        Node* last = current;
        while (last->next != list->head) last = last->next;
        list->head = current->next;
        last->next = list->head;
        free(current);
        return;
    }

    previous = current;
    current = current->next;
    while (current != list->head && current->value != key) {
        previous = current;
        current = current->next;
    }

    if (current->value == key) {
        previous->next = current->next;
        free(current);
    }
}

void freeCircularList(LinkedList* list) {
    if (isEmpty(list)) return;

    Node* current = list->head;
    Node* next;

    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != list->head);

    list->head = NULL;
}