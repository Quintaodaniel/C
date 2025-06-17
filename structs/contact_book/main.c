// Simple contact agenda
// trains: structs and typedef, arrays of structs, string.h, ctype.h, validating input, passing structs to functions, searching by substring, editing fields
// Functions: add, list, search, edit name, edit phone
// Validates phone numbers (10 or 11 digits)
// Max: 100 contacts


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
} Person;

int validatePhone(const char* phone) {
    int length = strlen(phone);

    if (length != 10 && length != 11) return 0;

    for (int i = 0; i < length; i++) {
        if (!isdigit(phone[i])) return 0;
    }

    return 1;
}

Person newPerson(const char* name, const char* phone) {
    Person person;
    strcpy(person.name, name);
    strcpy(person.phone, phone);
    return person;
}

void displayPerson(Person person) {
    printf("\nName: %s\nPhone: %s\n", person.name, person.phone);
}

void displayContacts(Person* contacts, size_t size) {
    puts("\nYour contact list:");
    for (size_t i = 0; i < size; i++) {
        displayPerson(contacts[i]);
    }
}

void searchContact(const char* name, Person* contacts, size_t size) {
    int found = 0;

    for (size_t i = 0; i < size; i++) {
        if (strstr(contacts[i].name, name) != NULL) {
            displayPerson(contacts[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No contact found containing \"%s\" in the name.\n", name);
    }
}

void editName(char* name, Person* contacts, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("New name: ");
            fgets(contacts[i].name, sizeof(contacts[i].name), stdin);
            contacts[i].name[strcspn(contacts[i].name, "\n")] = '\0';
            printf("Name updated!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void editPhone(char* name, Person* contacts, size_t size) {
    char newPhone[20];
    for (size_t i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            do {
                printf("New phone (10 or 11 digits): ");
                fgets(newPhone, sizeof(newPhone), stdin);
                newPhone[strcspn(newPhone, "\n")] = '\0';
                if (!validatePhone(newPhone))
                    printf("Invalid phone number, try again.\n");
            } while (!validatePhone(newPhone));

            strcpy(contacts[i].phone, newPhone);
            printf("Phone updated!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    Person contacts[MAX_CONTACTS];
    size_t size = 0;

    int option;
    char name[50], phone[20];

    do {
        printf("\n==== CONTACTS ====\n");
        printf("[1] Add contact\n");
        printf("[2] Show contacts\n");
        printf("[3] Search contact by name\n");
        printf("[4] Edit contact name\n");
        printf("[5] Edit contact phone\n");
        printf("[0] Exit\n");
        printf("Choice: ");
        scanf("%d", &option);
        getchar(); // clear buffer

        switch (option) {
            case 1:
                printf("Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // remove \n

                do {
                    printf("Phone (numbers only, 10 or 11 digits): ");
                    fgets(phone, sizeof(phone), stdin);
                    phone[strcspn(phone, "\n")] = '\0';
                    if (!validatePhone(phone)) {
                        printf("Invalid phone! Try again.\n");
                    }
                } while (!validatePhone(phone));

                if (size < MAX_CONTACTS) {
                    contacts[size++] = newPerson(name, phone);
                    printf("Contact added!\n");
                } else {
                    printf("Contact list is full!\n");
                }
                break;

            case 2:
                displayContacts(contacts, size);
                break;

            case 3:
                printf("Enter name (or part of it): ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                searchContact(name, contacts, size);
                break;
            
            case 4:
                printf("Enter the contact's name you want to edit: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                editName(name, contacts, size);
                break;

            case 5:
                printf("Enter the contact's name you want to edit: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                editPhone(name, contacts, size);
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid option!\n");
        }

    } while (option != 0);

    return 0;
}
