// Number Guessing Game
// --------------------
// Goal: Build a simple game where the user tries to guess a random number between 1 and 100.
// Trains: random number generation, loops (do-while), input handling, conditionals, counters.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret, guess, attempts = 0;

    srand(time(NULL));  // random seed

    secret = (rand() % 100) + 1;  // number between 1 and 100

    printf("=== Game: Guess the number from 1 to 100 ===\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < secret) {
            printf("Too low!\n");
        } else if (guess > secret) {
            printf("Too high!\n");
        } else {
            printf("Congrats! You guessed it in %d attempts.\n", attempts);
        }
    } while (guess != secret);

    return 0;
}
