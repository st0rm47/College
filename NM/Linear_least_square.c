#include <stdio.h>
#include <stdlib.h>

// Function to calculate the coefficients (m and c) of the linear equation y = mx + c
void linearLeastSquares(int *x, int *y, int n, float *m, float *c) {
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_x_squared = 0;

    // Calculate the sum of x, y, xy, and x^2
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x_squared += x[i] * x[i];
    }

    // Calculate m and c using the least squares formulas
    *m = (n * sum_xy - sum_x * sum_y) / (n * sum_x_squared - sum_x * sum_x);
    *c = (sum_y - *m * sum_x) / n;
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

    float m, c;
    linearLeastSquares(x, y, n, &m, &c);

    printf("The linear equation that fits the data points is: y = %.2fx + %.2f\n", m, c);

    // Predict y for a given x
    int given_x;
    printf("Enter the value of x to predict y: ");
    scanf("%d", &given_x);
    float predicted_y = m * given_x + c;
    printf("Predicted y for x = %d is: %.2f\n", given_x, predicted_y);

    // Free dynamically allocated memory
    free(x);
    free(y);

    return 0;
}
