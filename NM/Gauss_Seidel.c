#include <stdio.h>
#include <math.h>

#define N 3 // Number of equations

void gaussSeidel(double A[N][N+1], double X[N]) {
    int i, j, iter;
    double sum;

    double epsilon = 1e-9; // Error tolerance
    int maxIterations = 10000; // Maximum number of iterations

    for (iter = 0; iter < maxIterations; iter++) {
        double maxError = 0.0;
        for (i = 0; i < N; i++) {
            sum = 0;
            for (j = 0; j < N; j++) {
                if (j != i) {
                    sum += A[i][j] * X[j];
                }
            }
            double newX = (A[i][N] - sum) / A[i][i];
            double error = fabs(newX - X[i]);
            if (error > maxError) {
                maxError = error;
            }
            X[i] = newX;
        }
        if (maxError < epsilon) {
            break; // Convergence reached
        }
    }

    printf("Iterations: %d\n", iter + 1);
}

int main() {
    double A[N][N+1]; // Augmented matrix
    double X[N]; // Variables

    // Reading the augmented matrix from the user
    printf("Enter the augmented matrix (%d x %d elements):\n", N, N + 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++) {
            printf("Enter element A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    // Reading the initial guess for the variables from the user
    printf("Enter the initial guess for the variables:\n");
    for (int i = 0; i < N; i++) {
        printf("Enter X[%d]: ", i);
        scanf("%lf", &X[i]);
    }

    gaussSeidel(A, X);

    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("X[%d] = %.9f\n", i, X[i]);
    }

    return 0;
}
