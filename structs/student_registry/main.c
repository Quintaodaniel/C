// Student Management System
// Trains: structs and typedef, array of structs, input handling, passing structs to functions, menu-driven program
// Functions: addStudent, listPassedStudents, listFailedStudents, showClassAverage
// Manages students' names and grades (two grades per student), validates inputs
// Max: 100 students

#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    float grade1;
    float grade2;
} Student;

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nThe maximum number of students has been reached.\n");
        return;
    }
    printf("\nEnter student name: ");
    scanf(" %[^\n]", students[*count].name);
    printf("Enter first grade: ");
    scanf("%f", &students[*count].grade1);
    printf("Enter second grade: ");
    scanf("%f", &students[*count].grade2);
    (*count)++;
}

void listPassedStudents(const Student students[], int count) {
    printf("\n--- PASSED STUDENTS (average >= 7.0) ---\n");
    for (int i = 0; i < count; i++) {
        float average = (students[i].grade1 + students[i].grade2) / 2.0f;
        if (average >= 7.0f) {
            printf("%s - Average: %.2f\n", students[i].name, average);
        }
    }
}

void listFailedStudents(const Student students[], int count) {
    printf("\n--- FAILED STUDENTS (average < 7.0) ---\n");
    for (int i = 0; i < count; i++) {
        float average = (students[i].grade1 + students[i].grade2) / 2.0f;
        if (average < 7.0f) {
            printf("%s - Average: %.2f\n", students[i].name, average);
        }
    }
}

void showClassAverage(const Student students[], int count) {
    if (count == 0) {
        printf("\nNo students registered.\n");
        return;
    }
    float totalSum = 0.0f;
    for (int i = 0; i < count; i++) {
        totalSum += (students[i].grade1 + students[i].grade2) / 2.0f;
    }
    printf("\nClass Average: %.2f\n", totalSum / count);
}

int main() {
    Student students[MAX_STUDENTS];
    int total = 0, choice;

    while (1) {
        printf("\n--- MAIN MENU ---\n");
        puts("[1] Add Student");
        puts("[2] List Passed Students (average >= 7.0)");
        puts("[3] List Failed Students (average < 7.0)");
        puts("[4] Show Class Average");
        puts("[0] Exit");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("\nExiting the program. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                addStudent(students, &total);
                break;
            case 2:
                listPassedStudents(students, total);
                break;
            case 3:
                listFailedStudents(students, total);
                break;
            case 4:
                showClassAverage(students, total);
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}
