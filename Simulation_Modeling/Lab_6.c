#include <stdio.h>
#define SIZE 100

int main() {
    printf("\t=================================");
    printf("\n\t  Linear Congruential Generator  ");
    printf("\n\t=================================\n");

    int x[SIZE + 1];
    int m = 100, a = 5, c = 13;
    x[0] = 11;

    for (int i = 0; i < SIZE; i++) {
        x[i + 1] = (a * x[i] + c) % m;
    }

    printf("\nGenerated Random Numbers:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d\t", x[i]);
        if ((i + 1) % 10 == 0) printf("\n");  // Newline every 10 numbers for readability
    }

    printf("\nCompiled by : Subodh Ghimire ");
    return 0;
}
