// String Allocator
// Trains: dynamic memory allocation, malloc, realloc, free, strings
// Functions: initString, appendString, freeString
// Implements a dynamic string that grows automatically when more text is added

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 16

typedef struct {
    char *data;
    size_t length;
    size_t capacity;
} String;

void initString(String *s) {
    s->data = malloc(INITIAL_CAPACITY);
    s->length = 0;
    s->capacity = INITIAL_CAPACITY;
}

void appendString(String *s, const char *text) {
    size_t text_len = strlen(text);
    if (s->length + text_len + 1 > s->capacity) {
        while (s->length + text_len + 1 > s->capacity) {
            s->capacity *= 2;
        }
        s->data = realloc(s->data, s->capacity);
        if (!s->data) {
            printf("Error: Memory reallocation failed.\n");
            exit(1);
        }
    }
    strcpy(s->data + s->length, text);
    s->length += text_len;
}

void freeString(String *s) {
    free(s->data);
}

int main() {
    String s;
    initString(&s);
    printf("Enter strings (end with an empty line):\n");
    while (1) {
        char buffer[256];
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            break;
        }
        if (strcmp(buffer, "\n") == 0) {
            break;
        }
        appendString(&s, buffer);
    }
    printf("\nFinal String:\n%s\n", s.data);
    freeString(&s);
    return 0;
}
