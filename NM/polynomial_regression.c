#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

// Function to calculate the coefficients (a[]) of the polynomial equation y = a0 + a1*x + a2*x^2 + ... + an*x^n
void polynomialRegression(int *x, int *y, int n, int degree, float *coefficients) {
    // Create the matrix X
    float **X = (float **)malloc((degree + 1) * sizeof(float *));
    for (int i = 0; i <= degree; i++) {
        X[i] = (float *)malloc((degree + 1) * sizeof(float));
        for (int j = 0; j <= degree; j++) {
            X[i][j] = 0;
            for (int k = 0; k < n; k++) {
                X[i][j] += pow(x[k], i + j);
            }
        }
    }

    // Create the matrix Y
    float *Y = (float *)malloc((degree + 1) * sizeof(float));
    for (int i = 0; i <= degree; i++) {
        Y[i] = 0;
        for (int k = 0; k < n; k++) {
            Y[i] += y[k] * pow(x[k], i);
        }
    }

    // Solve the system of linear equations using Gauss-Jordan elimination
    for (int i = 0; i <= degree; i++) {
        float divisor = X[i][i];
        for (int j = 0; j <= degree; j++) {
            X[i][j] /= divisor;
        }
        Y[i] /= divisor;
        for (int k = 0; k <= degree; k++) {
            if (k != i) {
                float factor = X[k][i];
                for (int j = 0; j <= degree; j++) {
                    X[k][j] -= factor * X[i][j];
                }
                Y[k] -= factor * Y[i];
            }
        }
    }

    // Coefficients of the polynomial
    for (int i = 0; i <= degree; i++) {
        coefficients[i] = Y[i];
    }

    // Free dynamically allocated memory
    for (int i = 0; i <= degree; i++) {
        free(X[i]);
    }
    free(X);
    free(Y);
}

int main() {
    int n, degree;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

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

    // Coefficients array for the polynomial equation
    float *coefficients = (float *)malloc((degree + 1) * sizeof(float));

    polynomialRegression(x, y, n, degree, coefficients);

    printf("The polynomial equation that fits the data points is:\n");
    printf("y = ");
    for (int i = degree; i >= 0; i--) {
        printf("%.2f*x^%d ", coefficients[i], i);
        if (i != 0) {
            printf("+ ");
        }
    }
    printf("\n");

    // Free dynamically allocated memory
    free(x);
    free(y);
    free(coefficients);

    return 0;
}
