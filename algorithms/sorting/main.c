// Sorting Algorithms Implementation
// ----------------------------------
// Goal: Practice common sorting techniques and understand their complexities.
// Includes: Bubble Sort, Selection Sort, Insertion Sort, and Merge Sort.
// Use: Sort integer arrays in ascending order.
// Complexity: O(n^2) for Bubble/Selection/Insertion, O(n log n) for Merge Sort.

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* arr, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void selectionSort(int* arr, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = tmp;
    }
}

void insertionSort(int* arr, size_t size) {
    for (size_t i = 1; i < size; i++) {
        int key = arr[i];
        int j = (int)i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

static void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

static void mergeSortHelper(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(int* arr, size_t size) {
    mergeSortHelper(arr, 0, (int)size - 1);
}
