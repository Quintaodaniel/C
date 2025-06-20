// Search Algorithms Implementation
// --------------------------------
// Goal: Practice common search techniques and understand their complexities.
// Trains: linear search, binary search, exponential search, and interpolation search.
// Use: find indexes of elements in integer arrays efficiently, with sorted and unsorted data.

#include <stdio.h>
#include <stdlib.h>

int linearSearch(int* arr, size_t size, int value) {
    for (size_t i = 0; i < size; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

int binarySearch(int* arr, size_t size, int value) {
    size_t low = 0, high = size - 1;
    while (low <= high) {
        size_t mid = low + (high - low) / 2;
        if (arr[mid] == value) return mid;
        else if (arr[mid] < value) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int exponentialSearch(int* arr, size_t size, int value) {
    if (size == 0) return -1;
    if (arr[0] == value) return 0;

    size_t i = 1;
    while (i < size && arr[i] <= value) {
        i *= 2;
    }

    size_t low = i / 2;
    size_t high = (i < size) ? i : size - 1;
    
    return binarySearch(arr + low, high - low + 1, value) + low;
}

int interpolationSearch(int* arr, size_t size, int value) {
    size_t low = 0, high = size - 1;

    while (low <= high && value >= arr[low] && value <= arr[high]) {
        size_t pos = low + ((double)(value - arr[low]) * (high - low) / (arr[high] - arr[low]));

        if (arr[pos] == value) return pos;
        if (arr[pos] < value) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}
