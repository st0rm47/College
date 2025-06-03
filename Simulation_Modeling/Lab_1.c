#include <stdio.h>

int main() {
    printf("\t=========================");
    printf("\n\t  Distributed Lag Model  ");
    printf("\n\t=========================\n");

    float Y_prev, Y, I, T, C[5];
    float G[5] = {20, 25, 30, 35, 40};
    int i;

    printf("Enter initial value of lagged variable Y-1: ");
    scanf("%f", &Y_prev);

    printf("\nThe growth in consumption over five years is:\n");
    printf("Year\tConsumption\n");

    for (i = 0; i < 5; i++) {
        I = 2 + 0.1 * Y_prev;
        Y = 45.45 + 2.27 * (I + G[i]);
        T = 0.2 * Y;
        C[i] = 20 + 0.7 * (Y - T);
        printf("%d\t%.2f\n", i + 1, C[i]);

        Y_prev = Y; // Update Y-1 for the next year
    }

    printf("\nCompiled by : Subodh Ghimire ");
    return 0;
}
