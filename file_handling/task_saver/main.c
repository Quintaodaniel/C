// Task management system
// trains: structs and typedef, dynamic memory allocation, file I/O, string.h for string operations
// Functions: countTasks, loadTasks, saveTasks, listByStatus, addTask, removeTask, editTask
// Features: list tasks by status (pending, completed, in-progress), add/remove/edit tasks, file persistence (Tasks.txt)
// Max: unlimited tasks (limited only by available memory)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char status[100];
} Task;

int countTasks(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return 0;

    int count = 0;
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        count++;
    }
    fclose(file);
    return count;
}

Task* loadTasks(const char* filename, int count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        puts("Error: Failed to open file!");
        exit(1);
    }
    Task* tasks = malloc(count * sizeof(Task));
    if (!tasks) {
        puts("Error: Failed to allocate memory!");
        fclose(file);
        exit(1);
    }
    for (int i = 0; i < count; i++) {
        char line[256];
        if (!fgets(line, sizeof(line), file)) {
            puts("Error: Failed to read line!");
            fclose(file);
            exit(1);
        }
        sscanf(line, "%99[^;];%99[^\n]", tasks[i].name, tasks[i].status);
    }
    fclose(file);
    return tasks;
}

void saveTasks(const char* filename, Task* tasks, int count) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        puts("Error: Failed to open file for writing!");
        exit(1);
    }
    for (int i = 0; i < count; i++) {
        if (tasks[i].name[0] != '\0') {
            fprintf(file, "%s;%s\n", tasks[i].name, tasks[i].status);
        }
    }
    fclose(file);
}

void listByStatus(Task* tasks, int count, const char* status) {
    for (int i = 0; i < count; i++) {
        if (strcmp(tasks[i].status, status) == 0) {
            printf("%s (%s)\n", tasks[i].name, tasks[i].status);
        }
    }
}

void addTask(const char* filename) {
    FILE* file = fopen(filename, "a");
    if (!file) {
        puts("Error: Failed to open file for adding!");
        return;
    }
    Task t;

    printf("Enter task name: ");
    fgets(t.name, sizeof(t.name), stdin);
    t.name[strcspn(t.name, "\n")] = '\0';

    printf("Enter status: ");
    fgets(t.status, sizeof(t.status), stdin);
    t.status[strcspn(t.status, "\n")] = '\0';

    fprintf(file, "%s;%s\n", t.name, t.status);
    fclose(file);
}

void removeTask(const char* filename, Task* tasks, int count) {
    if (!tasks) {
        puts("No tasks to remove.");
        return;
    }
    char name[100];
    printf("Enter name of task to remove: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    FILE* file = fopen(filename, "w");
    if (!file) {
        puts("Error: Failed to open file for removing!");
        return;
    }
    for (int i = 0; i < count; i++) {
        if (strcmp(tasks[i].name, name) != 0) {
            fprintf(file, "%s;%s\n", tasks[i].name, tasks[i].status);
        }
    }
    fclose(file);
}

void editTask(const char* filename, Task* tasks, int count) {
    if (!tasks) {
        puts("No tasks to edit.");
        return;
    }
    char name[100];
    printf("Enter name of task to edit: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(tasks[i].name, name) == 0) {
            printf("Enter new status for %s: ", name);
            fgets(tasks[i].status, sizeof(tasks[i].status), stdin);
            tasks[i].status[strcspn(tasks[i].status, "\n")] = '\0';
        }
    }

    saveTasks(filename, tasks, count);
}

int main() {
    const char* filename = "Tasks.txt";
    int count = countTasks(filename);
    Task* tasks = NULL;

    if (count > 0) {
        tasks = loadTasks(filename, count);
    }

    int option;
    puts("--- MENU ---");
    puts("[1] List pending tasks");
    puts("[2] List completed tasks");
    puts("[3] List in-progress tasks");
    puts("[4] New task");
    puts("[5] Remove task");
    puts("[6] Edit task");
    scanf("%d", &option);
    getchar(); // Limpa '\n' do scanf

    switch (option) {
        case 1:
            listByStatus(tasks, count, "pending");
            break;
        case 2:
            listByStatus(tasks, count, "completed");
            break;
        case 3:
            listByStatus(tasks, count, "in-progress");
            break;
        case 4:
            addTask(filename);
            break;
        case 5:
            removeTask(filename, tasks, count);
            break;
        case 6:
            editTask(filename, tasks, count);
            break;
    }

    free(tasks);
    return 0;
}
