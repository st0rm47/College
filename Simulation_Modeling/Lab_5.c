#include <stdio.h>

int main() {
    printf("\t====================================");
    printf("\n\t  Markov Chain: Weather Prediction");
    printf("\n\t====================================\n");

    float transMat[2][2] = {
        {0.9, 0.1},  // Sunny today -> [Sunny, Rainy] tomorrow
        {0.5, 0.5}   // Rainy today -> [Sunny, Rainy] tomorrow
    };

    float vect[1][2] = { {1, 0} };
    float result[1][2] = {0};

    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                result[i][j] += vect[i][k] * transMat[k][j];
            }
        }
    }

    printf("\nProbability of weather on next day:\n");
    printf("Sunny: %.2f\n", result[0][0]);
    printf("Rainy: %.2f\n", result[0][1]);

    printf("\nCompiled by : Subodh Ghimire ");
    return 0;
}
