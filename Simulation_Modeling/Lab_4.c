#include <stdio.h>
#include <math.h>

int main() {
    printf("\t========================");
    printf("\n\t  Poisson Distribution  ");
    printf("\n\t========================\n");

    float lambda;
    printf("Enter arrival rate (cars per hour): ");
    scanf("%f", &lambda);

    for (int x = 0; x <= 15; x++) {
        double factorial = 1.0;
        for (int i = 1; i <= x; i++) {
            factorial *= i;
        }
        double probability = (exp(-lambda) * pow(lambda, x)) / factorial;
        printf("P(X = %2d) = %.6f\n", x, probability);
    }

    printf("\nCompiled by : Subodh Ghimire ");
    return 0;
}
