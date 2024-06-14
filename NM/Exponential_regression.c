#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the coefficients (a and b) of the exponential equation y = ae^(bx)
void exponentialRegression(int *x, int *y, int n, float *a, float *b) {
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_x_squared = 0;

    // Calculate the sum of x, y, xy, and x^2
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += log(y[i]);
        sum_xy += x[i] * log(y[i]);
        sum_x_squared += x[i] * x[i];
    }

    // Calculate b and a using the least squares formulas
    *b = (n * sum_xy - sum_x * sum_y) / (n * sum_x_squared - sum_x * sum_x);
    *a = exp((sum_y - *b * sum_x) / n);
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

    float a, b;
    exponentialRegression(x, y, n, &a, &b);

    printf("The exponential equation that fits the data points is:\n");
    printf("y = %.2f * e^(%.2f * x)\n", a, b);

    // Free dynamically allocated memory
    free(x);
    free(y);

    return 0;
}
