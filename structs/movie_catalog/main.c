// Simple Movie Catalog
// Trains: structs and typedef, array of structs, input handling, menu-driven program
// Functions: addMovie, listAll, searchByTitle, listByGenre
// Manages movies with title, genre, and release year
// Max: 100 movies

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100

typedef struct {
    char title[100];
    char genre[50];
    int year;
} Movie;

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("\nThe maximum number of movies has been reached.\n");
        return;
    }
    printf("\nEnter movie title: ");
    scanf(" %[^\n]", movies[*count].title);
    printf("Enter movie genre: ");
    scanf(" %[^\n]", movies[*count].genre);
    printf("Enter release year: ");
    scanf("%d", &movies[*count].year);
    (*count)++;
}

void listAll(const Movie movies[], int count) {
    if (count == 0) {
        printf("\nNo movies registered.\n");
        return;
    }
    printf("\n--- All Movies ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d) %s | Genre: %s | Year: %d\n",
               i + 1, movies[i].title, movies[i].genre, movies[i].year);
    }
}

void searchByTitle(const Movie movies[], int count) {
    char title[100];
    printf("\nEnter title or part of the title to search: ");
    scanf(" %[^\n]", title);
    printf("\n--- Search Results ---\n");

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(movies[i].title, title) != NULL) {
            printf("%d) %s | Genre: %s | Year: %d\n",
                   i + 1, movies[i].title, movies[i].genre, movies[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No movies found with the given title.\n");
    }
}

void listByGenre(const Movie movies[], int count) {
    char genre[50];
    printf("\nEnter the genre you want to list: ");
    scanf(" %[^\n]", genre);
    printf("\n--- Movies of Genre: %s ---\n", genre);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].genre, genre) == 0) {
            printf("%d) %s | Year: %d\n",
                   i + 1, movies[i].title, movies[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No movies found for this genre.\n");
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int total = 0, choice;

    while (1) {
        printf("\n--- MOVIE CATALOG MENU ---\n");
        puts("[1] Add Movie");
        puts("[2] List All Movies");
        puts("[3] Search by Title");
        puts("[4] List Movies by Genre");
        puts("[0] Exit");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("\nExiting the program. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                addMovie(movies, &total);
                break;
            case 2:
                listAll(movies, total);
                break;
            case 3:
                searchByTitle(movies, total);
                break;
            case 4:
                listByGenre(movies, total);
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}
