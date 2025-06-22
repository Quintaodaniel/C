// Dynamic Integer Array
// Trains: dynamic memory allocation, malloc, realloc, free, structs
// Functions: initArray, addElement, printArray, freeArray
// Implements a dynamic array that grows automatically when full

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

void initArray(DynamicArray *arr, int initialCapacity) {
    arr->data = malloc(sizeof(int) * initialCapacity);
    if (!arr->data) {
        printf("Failed to allocate memory\n");
        exit(1);
    }
    arr->size = 0;
    arr->capacity = initialCapacity;
}

void freeArray(DynamicArray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

void addElement(DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        // dobra o tamanho
        int newCapacity = arr->capacity * 2;
        int *temp = realloc(arr->data, sizeof(int) * newCapacity);
        if (!temp) {
            printf("Failed to reallocate memory\n");
            freeArray(arr);
            exit(1);
        }
        arr->data = temp;
        arr->capacity = newCapacity;
    }
    arr->data[arr->size++] = value;
}

void printArray(const DynamicArray *arr) {
    printf("Array contents (size: %d, capacity: %d): ", arr->size, arr->capacity);
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray arr;
    initArray(&arr, 2);

    addElement(&arr, 10);
    addElement(&arr, 20);
    addElement(&arr, 30);
    addElement(&arr, 40);

    printArray(&arr);

    freeArray(&arr);

    return 0;
}
