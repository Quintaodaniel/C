/*
Project: Reverse Linked List Printer (using Recursion)

Skills practiced:
- Recursion
- Pointer manipulation
- Linked list traversal
- Custom data structures
- Function decomposition
- Memory management (allocation and deallocation)
- Modular programming with header files

Instruction to run: 
    gcc challenges/reverse-linked-list.c data_structures/linked_list/ll.c -Iincludes -o challenge
    ./challenge
*/

#include <stdio.h>
#include "../includes/linkedlist.h"

void reverseLinkedList(const Node* head) {
    if (head == NULL)
        return;

    reverseLinkedList(head->next);
    printf("%d ", head->value);
}

int main() {
    LinkedList list;
    createList(&list);

    insertInOrder(1, &list);
    insertInOrder(2, &list);
    insertInOrder(3, &list);
    insertInOrder(4, &list);
    insertInOrder(5, &list);

    reverseLinkedList(list.head);

    freeList(&list);
    return 0;
}
