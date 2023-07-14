#include <stdio.h>
#include <stdlib.h>

int simulate_collection() {
    int caps = 0;
    int a_count = 0;
    int e_count = 0;
    int p_count = 0;
    int l_count = 0;

    while (1) {
        caps++;
        int random_num = rand() % 100 + 1;

        if (random_num <= 40) {
            a_count++;
            if (a_count == 2)
                break;
        } else if (random_num <= 80) {
            e_count++;
            if (e_count == 2)
                break;
        } else if (random_num <= 90) {
            p_count++;
            if (p_count == 1)
                break;
        } else {
            l_count++;
            if (l_count == 1)
                break;
        }
    }

    return caps;
}

double simulate_multiple_times(int num_simulations) {
    double total_caps = 0;

    for (int i = 0; i < num_simulations; i++) {
        total_caps += simulate_collection();
    }

    double average_caps = total_caps / num_simulations;
    return average_caps;
}

int main() {
    srand(0); // Initialize random number generator with a seed of 0

    int num_simulations = 50;
    double average_caps_per_simulation = simulate_multiple_times(num_simulations);
    printf("Average number of caps per simulation: %.2f\n", average_caps_per_simulation);

    return 0;
}