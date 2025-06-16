// Grades Statistics
// -----------------
// Goal: Input multiple grades and calculate average, highest, and lowest grades.
// Trains: arrays, loops, functions, float arithmetic, input validation.

#include <stdio.h>

float averageGrades(float grades[], int size) {
    float sum = 0;  // mudar para float pra média ficar certa
    for (int i = 0; i < size; i++) {
        sum += grades[i];
    }
    return sum / size;
}

float highestGrade(float grades[], int size) {
    float highest = grades[0];

    for (int i = 1; i < size; i++) {
        if (grades[i] > highest) highest = grades[i];
    }
    return highest;
}

float lowestGrade(float grades[], int size) {
    float lowest = grades[0];

    for (int i = 1; i < size; i++) {
        if (grades[i] < lowest) lowest = grades[i];
    }
    return lowest;    
}

int main() {
    float grades[50];
    float grade;
    int size = 0;

    for (int i = 0; i < 50; i++) {
        printf("Enter grade #%d (Enter -1 to finish): ", i+1);

        if (scanf("%f", &grade) != 1) {
            puts("Invalid grade! Try again.");
            i--;
            continue;
        }

        if (grade == -1) {
            puts("\nFinishing and calculating results...");
            break;
        }

        grades[i] = grade;
        size++;
    }    

    printf("\n");
    if (size > 0) {
        printf("Average of %d grades -> %.2f\n", size, averageGrades(grades, size));
        printf("Highest of %d grades -> %.2f\n", size, highestGrade(grades, size));
        printf("Lowest of %d grades -> %.2f\n", size, lowestGrade(grades, size));
    } else {
        printf("No grades entered.\n");
    }

    return 0;
}
