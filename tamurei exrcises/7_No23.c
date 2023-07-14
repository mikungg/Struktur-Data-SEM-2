#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice() {
    return rand() % 6 + 1;  // Generate a random number between 1 and 6
}

int draw_card() {
    return rand() % 13 + 1;  // Generate a random number between 1 and 13 (representing the card's value)
}

int play_game() {
    int dice1 = roll_dice();
    int dice2 = roll_dice();
    int sum = dice1 + dice2;

    if (sum % 2 == 0) {
        return -5;  // Gambler loses the bet
    } else {
        int card = draw_card();

        if (card == 1 || card == 3 || card == 5 || card == 7 || card == 9) {
            return card + 5;  // Gambler wins the card's value plus $5
        } else {
            return -5;  // Gambler loses the bet
        }
    }
}

double simulate_multiple_games(int num_games) {
    int total_winnings = 0;

    for (int i = 0; i < num_games; i++) {
        total_winnings += play_game();
    }

    double average_winnings = (double)total_winnings / num_games;
    return average_winnings;
}

int main() {
    srand(time(NULL));  // Initialize the random number generator with the current time as the seed

    int num_games = 20;
    double average_winnings_per_game = simulate_multiple_games(num_games);

    printf("Average amount won per game: $%.2f\n", average_winnings_per_game);

    return 0;
}
