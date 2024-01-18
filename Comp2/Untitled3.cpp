#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed for random number generation
    srand(time(NULL));

    int randomNumber, userGuess, attempts = 0;
    int bestScore = -1; // Initialize bestScore to an invalid value

    char playAgain;

    do {
        // Generate a random number between 1 and 5000
        randomNumber = rand() % 5000 + 1;

        printf("\nWelcome to the Number Guessing Game!\n");
        printf("Try to guess the number between 1 and 5000.\n");

        do {
            printf("Enter your guess: ");
            scanf("%d", &userGuess);

            // Check the user's guess
            if (userGuess > randomNumber) {
                printf("Too high! Try again.\n");
            } else if (userGuess < randomNumber) {
                printf("Too low! Try again.\n");
            }

            attempts++;

        } while (userGuess != randomNumber);

        printf("\nCongratulations! You guessed the number in %d attempts.\n", attempts);

        // Update the bestScore if it's the first attempt or a new best score
        if (bestScore == -1 || attempts < bestScore) {
            bestScore = attempts;
            printf("New Best Score: %d attempts!\n", bestScore);
        } else {
            printf("Best Score: %d attempts.\n", bestScore);
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

        // Reset attempts for a new game
        attempts = 0;

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing! Goodbye.\n");

    return 0;
}

