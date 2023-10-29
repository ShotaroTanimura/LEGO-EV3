#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Enum to represent the hands in Rock-Paper-Scissors
typedef enum {
    ROCK = 1,    // Rock
    SCISSORS,    // Scissors
    PAPER        // Paper
} Hand;

// Function to get user's choice
Hand getUserInput() {
    int choice;
    printf("1: Rock, 2: Scissors, 3: Paper\n");
    printf("Please choose your hand: ");
    scanf("%d", &choice);
    
    while (choice < 1 || choice > 3) {
        printf("Invalid input. Please choose again: ");
        scanf("%d", &choice);
    }
    return (Hand)choice;
}

// Function to get the computer's random choice
Hand getComputerChoice() {
    return (Hand)(rand() % 3 + 1);
}

// Function to determine the winner
int judge(Hand user, Hand computer) {
    if (user == computer) {
        printf("It's a draw\n");
        return 0;  // Return 0 in case of a draw
    } else if ((user == ROCK && computer == SCISSORS) ||
               (user == SCISSORS && computer == PAPER) ||
               (user == PAPER && computer == ROCK)) {
        printf("You win\n");
        return 1;
    } else {
        printf("You lose\n");
        return 1;
    }
}

int main() {
    // Initialize random number generator
    srand((unsigned)time(NULL));

    Hand userChoice, computerChoice;
    int result = 0;

    printf("Rock-Paper-Scissors...\n");
    
    while (!result) {
        userChoice = getUserInput();
        computerChoice = getComputerChoice();
        printf("Computer's choice: %d\n", computerChoice);
        result = judge(userChoice, computerChoice);
    }
    
    return 0;
}
