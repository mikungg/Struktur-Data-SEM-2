#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double f(double x) {
    // Define the function f(x) here
    return x * x;
}

double estimate_integral(int num_points) {
    int points_below_curve = 0;

    for (int i = 0; i < num_points; i++) {
        double x = (double)rand() / RAND_MAX;  // Generate a random x value between 0 and 1
        double y = (double)rand() / RAND_MAX;  // Generate a random y value between 0 and 1

        if (y < f(x)) {
            points_below_curve++;
        }
    }

    double integral = (double)points_below_curve / num_points;
    return integral;
}

int main() {
    srand(time(NULL));  // Initialize the random number generator with the current time as the seed

    int num_points = 100000;  // Number of points to generate
    double estimated_integral = estimate_integral(num_points);

    printf("Estimated integral: %.6f\n", estimated_integral);

    return 0;
}
