// Linked List Implementation (Singly)
// -----------------------------------
// Goal: Practice dynamic memory and linked list operations with struct nodes.
// Trains: linked struct, dynamic allocation, insertion/removal by value and index, search, reverse, concatenation.

#include <stdio.h>
#include <stdlib.h>
#include "../../includes/linkedlist.h"

// ====================== Core Functions (List Management) ======================

void createList(LinkedList* list) {
    list->head = NULL;
}

int isEmpty(const LinkedList* list) {
    return list->head == NULL;
}

void freeList(LinkedList* list) {
    Node* current = list->head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    list->head = NULL;
}

// ====================== Insertion Functions ======================

void insertAtBeginning(int value, LinkedList* list) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        puts("Memory allocation error!");
        exit(1);
    }

    newNode->value = value;
    newNode->next = list->head;
    list->head = newNode;
}

void insertAtEnd(int value, LinkedList* list) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        puts("Memory allocation error!");
        exit(1);
    }

    newNode->value = value;
    newNode->next = NULL;

    if (isEmpty(list)) {
        list->head = newNode;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL) current = current->next;

    current->next = newNode;
}

void insertInOrder(int value, LinkedList* list) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        puts("Memory allocation error!");
        exit(1);
    }

    newNode->value = value;
    newNode->next = NULL;

    if (isEmpty(list) || value < list->head->value) {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL && current->next->value < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void insertAtIndex(int value, int index, LinkedList* list) {
    if (index < 0) {
        puts("Error: Negative index not allowed!");
        return;
    }

    if (index == 0) {
        insertAtBeginning(value, list);
        return;
    }

    Node* prev = list->head;
    for (int i = 0; i < index - 1; i++) {
        if (prev == NULL) {
            puts("Error: Index out of range!");
            return;
        }
        prev = prev->next;
    }

    if (prev == NULL) {
        puts("Error: Index out of range!");
        return;
    }

    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        puts("Memory allocation error!");
        exit(1);
    }

    newNode->value = value;
    newNode->next = prev->next;
    prev->next = newNode;
}

// ====================== Removal Functions ======================

void removeFromBeginning(LinkedList* list) {
    if (isEmpty(list)) {
        puts("The list is empty!");
        return;
    }

    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
}

void removeFromEnd(LinkedList* list) {
    if (isEmpty(list)) {
        puts("The list is empty!");
        return;
    }

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        return;
    }

    Node* current = list->head;
    while (current->next->next != NULL) current = current->next;

    free(current->next);
    current->next = NULL;
}

void removeByValue(int value, LinkedList* list) {
    Node* current = list->head;
    Node* prev = NULL;

    while (current != NULL && current->value != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        puts("Value not found in the list!");
        return;
    }

    if (prev == NULL) {
        list->head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

void removeByIndex(int index, LinkedList* list) {
    if (isEmpty(list)) {
        puts("The list is empty!");
        return;
    }

    Node* temp = list->head;
    Node* prev = NULL;
    int counter = 0;

    if (index == 0) {
        list->head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && counter < index) {
        prev = temp;
        temp = temp->next;
        counter++;
    }

    if (temp == NULL) {
        puts("Index out of range!");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// ====================== Access and Search Functions ======================

void printList(const LinkedList* list) {
    if (isEmpty(list)) {
        puts("The list is empty!");
        return;
    }

    Node* current = list->head;

    while (current != NULL) {
        printf("%d", current->value);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(".\n");
}

int listSize(const LinkedList* list) {
    int size = 0;
    Node* current = list->head;

    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

Node* searchByValue(int value, const LinkedList* list) {
    Node* current = list->head;

    while (current != NULL) {
        if (current->value == value) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

Node* searchByIndex(int index, const LinkedList* list) {
    if (index < 0) return NULL;

    Node* current = list->head;
    int counter = 0;

    while (current != NULL) {
        if (counter == index) return current;
        counter++;
        current = current->next;
    }

    return NULL;
}

// ====================== Special Functions ======================

void reverseList(LinkedList* list) {
    Node* prev = NULL;
    Node* current = list->head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    list->head = prev;
}

void concatenateLists(LinkedList* list1, LinkedList* list2) {
    if (isEmpty(list1)) {
        list1->head = list2->head;
    } else {
        Node* current = list1->head;
        while (current->next != NULL) current = current->next;
        current->next = list2->head;
    }

    list2->head = NULL;
}
