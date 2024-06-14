#include <stdio.h>
#include <stdlib.h>

// Function to find the maxima and minima of tabulated functions
void findMaximaMinima(int *x, int *y, int n) {
    // Initialize flags for maxima and minima
    int maxima = 0, minima = 0;

    // Iterate through the data points
    for (int i = 1; i < n - 1; i++) {
        if (y[i] > y[i - 1] && y[i] > y[i + 1]) {
            printf("Local maximum found at x = %d, y = %d\n", x[i], y[i]);
            maxima = 1;
        } else if (y[i] < y[i - 1] && y[i] < y[i + 1]) {
            printf("Local minimum found at x = %d, y = %d\n", x[i], y[i]);
            minima = 1;
        }
    }

    if (!maxima) {
        printf("No local maximum found.\n");
    }

    if (!minima) {
        printf("No local minimum found.\n");
    }
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Dynamically allocate memory for x and y arrays
    int *x = (int *)malloc(n * sizeof(int));
    int *y = (int *)malloc(n * sizeof(int));

    printf("Enter the data points:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
        printf("y[%d]: ", i);
        scanf("%d", &y[i]);
    }

    findMaximaMinima(x, y, n);

    // Free dynamically allocated memory
    free(x);
    free(y);

    return 0;
}
