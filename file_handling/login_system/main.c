// Login and registration system
// trains: structs and typedef, dynamic arrays, file I/O, string.h for string handling
// Functions: countUsers, loadUsers, addUser, newUser, loginUser
// Features: validates username and password, allows new account creation, switch/case menu
// Persists data in file (Users.txt) with username and password
// Max: unlimited users (limited only by available memory)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
} User;

int countUsers(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return -1;
    int count = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') count++;
    }
    fclose(file);
    return count;
}

User* loadUsers(const char* filename, int count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }
    User* users = malloc(count * sizeof(User));
    for (int i = 0; i < count; i++) {
        fscanf(file, "%s %s", users[i].name, users[i].password);
    }
    fclose(file);
    return users;
}

void addUser(User user, const char* filename) {
    FILE* file = fopen(filename, "a");
    if (!file) exit(1);
    fprintf(file, "%s %s\n", user.name, user.password);
    fclose(file);
}

User* newUser(User* users, int* countUsers, const char* filename) {
    User newUser;
    printf("Enter new username: ");
    scanf("%s", newUser.name);
    printf("Enter new password: ");
    scanf("%s", newUser.password);
    addUser(newUser, filename);
    (*countUsers)++;
    users = realloc(users, (*countUsers) * sizeof(User));
    users[(*countUsers)-1] = newUser;
    return users;
}

int loginUser(User* users, int countUsers) {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int choice;
    while (1) {
        printf("User: ");
        scanf("%s", name);
        printf("Password: ");
        scanf("%s", password);
        int logged = 0;
        for (int i = 0; i < countUsers; i++) {
            if (strcmp(name, users[i].name) == 0 && strcmp(password, users[i].password) == 0) {
                logged = 1;
                break;
            }
        }
        if (logged) return 1;
        printf("Name or password invalid\n");
        printf("[1] Try again\n[2] Create new user\nAny other number to exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) continue;
        else if (choice == 2) return 2;
        else return 0;
    }
}

int main() {
    const char* filename = "Users.txt";
    int count = countUsers(filename);
    User* users = NULL;
    if (count > 0) {
        users = loadUsers(filename, count);
    }

    int choice;
    while (1) {
        printf("\n[1] Login\n[2] New User\n[3] Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int result = loginUser(users, count);
                if (result == 1) {
                    printf("Welcome!\n");
                } else if (result == 2) {
                    users = newUser(users, &count, filename);
                }
                break;
            }
            case 2:
                users = newUser(users, &count, filename);
                break;
            case 3:
                free(users);
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
