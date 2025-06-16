// String Toolkit
// --------------
// Goal: Implement basic string operations like length, copy, and concatenation without using string.h functions or pointers.
// Trains: char arrays, loops, string manipulation with indexes, functions.

#include <stdio.h>

int stringLength(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void stringCopy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void stringConcat(char dest[], char src[]) {
    int destLen = stringLength(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[destLen + i] = src[i];
        i++;
    }
    dest[destLen + i] = '\0';
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    fgets(str1, 100, stdin);

    for (int i = 0; i < 100; i++) {
        if (str1[i] == '\n') {
            str1[i] = '\0';
            break;
        }
    }

    printf("Enter second string: ");
    fgets(str2, 100, stdin);

    for (int i = 0; i < 100; i++) {
        if (str2[i] == '\n') {
            str2[i] = '\0';
            break;
        }
    }

    printf("\nLength of first string: %d\n", stringLength(str1));

    char copy[200];
    stringCopy(copy, str1);
    printf("Copy of first string: %s\n", copy);

    stringConcat(copy, str2);
    printf("Concatenation of copy and second string: %s\n", copy);

    return 0;
}
