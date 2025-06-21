// Score Tracker System
// Trains: file I/O, pointer usage, basic menu
// Functions: initialize_score, display_score, save_history, display_history, play_game
// Features: track scores for 2 players, save results to a history file, display match history
// Max: unlimited saved match results (limited only by available storage)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialize_score(int *p1, int *p2) {
    *p1 = 0;
    *p2 = 0;
}

void display_score(int p1, int p2) {
    printf("\nCurrent Score:\nPlayer 1: %d | Player 2: %d\n", p1, p2);
}

void save_history(int p1, int p2) {
    FILE *f = fopen("history.txt", "a");
    if (f) {
        fprintf(f, "Result: Player1 = %d, Player2 = %d\n", p1, p2);
        fclose(f);
    } else {
        printf("Error opening the file!\n");
    }
}

void display_history() {
    FILE *f = fopen("history.txt", "r");
    if (!f) {
        printf("\nNo history found.\n");
        return;
    }
    printf("\n-- HISTORY --\n");
    char line[100];
    while (fgets(line, sizeof(line), f))
        printf("%s", line);
    fclose(f);
}

void play_game() {
    int p1, p2, point;
    initialize_score(&p1, &p2);

    while (1) {
        display_score(p1, p2);
        printf("\nWho scored?\n[1] Player 1\n[2] Player 2\n[0] Finish\n> ");
        scanf("%d", &point);

        if (point == 0) {
            save_history(p1, p2);
            printf("Game finished and saved!\n");
            break;
        } else if (point == 1) {
            p1++;
        } else if (point == 2) {
            p2++;
        } else {
            printf("Invalid option, try again!\n");
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- MENU ---\n");
        puts("[1] Start a new game");
        puts("[2] View history");
        puts("[0] Exit");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                play_game();
                break;

            case 2:
                display_history();
                break;

            case 0:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid option, try again!\n");
                break;
        }
    }

    return 0;
}
