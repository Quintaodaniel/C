// Simple Text Editor
// Trains: dynamic memory allocation, malloc, realloc, free, strings
// Functions: main
// Implements a simple text editor that allows the user to input text until an empty line, storing it in dynamically growing memory

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 1024

int main() {
    char *text = malloc(INITIAL_CAPACITY);
    if (!text) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }
    size_t capacity = INITIAL_CAPACITY;
    size_t length = 0;

    printf("Enter text (end with an empty line):\n");
    while (1) {
        char buffer[256];
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            break;
        }
        if (strcmp(buffer, "\n") == 0) {
            break;
        }
        size_t buffer_len = strlen(buffer);
        if (length + buffer_len + 1 > capacity) {
            capacity *= 2;
            text = realloc(text, capacity);
            if (!text) {
                printf("Error: Memory reallocation failed.\n");
                return 1;
            }
        }
        strcpy(text + length, buffer);
        length += buffer_len;
    }

    printf("\nFinal Text:\n%s\n", text);
    free(text);
    return 0;
}
