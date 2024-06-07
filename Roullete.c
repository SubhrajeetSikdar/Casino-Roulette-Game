#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define BLACK 2
#define GREEN 3

int main() {
    int bet;
    int guess;
    int result;
    char choice;
    srand(time(NULL)); // Seed the random number generator
    printf("Welcome to the Roulette Game!\n");
    printf("Red numbers:1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36\n");
    printf("Black numbers:2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35\n");
    printf("Green numbers: 0, 00\n");
    do {
        printf("\nPlace your bet (1 for Red, 2 for Black, 3 for Green): ");
        scanf("%d",&bet);
        if (bet <1 || bet > 3) {
            printf("Invalid bet! Please choose again.\n");
            continue;
        }
        printf("Enter your guess: ");
        scanf("%d", &guess);
        if (guess < 0 || guess > 36) {
            printf("Invalid guess! Please choose a number between 0 and 36.\n");
            continue;
        }
        result = rand() % 37; 
        printf("The result is: %d\n", result);
        if (result == 0 || result == 00) {
            if (bet == GREEN) {
                printf("Congratulations! You won!\n");
            } else {
                printf("Sorry, you lost.\n");
            }
        } else if ((result % 2 == 0 && bet == BLACK) || (result % 2 != 0 && bet == RED)) {
            printf("Congratulations! You won!\n");
        } else {
            printf("Sorry, you lost.\n");
        }
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    printf("Thanks for playing!\n");
    return 0;
}
