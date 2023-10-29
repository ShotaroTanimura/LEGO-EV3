#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ev3.h>

typedef enum {
    ROCK = 1,
    SCISSORS,
    PAPER
} Hand;

Hand getSensorInput() {
    int color = ColorSensorRead();
    if (color == RED) return ROCK;
    if (color == GREEN) return SCISSORS;
    if (color == BLUE) return PAPER;
}

int judge(Hand user, Hand computer) {
    if (user == computer) {
        PlayTone(440, 500); // Draw sound
        return 0;
    } else if ((user == ROCK && computer == SCISSORS) ||
               (user == SCISSORS && computer == PAPER) ||
               (user == PAPER && computer == ROCK)) {
        PlayTone(880, 500); // Win sound
        return 1;
    } else {
        PlayTone(220, 500); // Lose sound
        return 1;
    }
}

int main() {
    InitEV3();

    Hand userChoice, computerChoice;
    int result = 0;

    while (1) {
        // Wait for touch sensor to be pressed
        while (!ButtonIsDown(BTN1)) {}

        PlayTone(660, 500); // Start sound

        userChoice = getSensorInput();
        computerChoice = (Hand)(rand() % 3 + 1);
        
        result = judge(userChoice, computerChoice);
        
        Wait(2000); // Wait for a short duration before the next round
    }

    FreeEV3();
    return 0;
}
