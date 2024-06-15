#include <stdio.h>
#include <math.h>

#define N 2 // Number of equations
#define MAX_ITER 50 // Maximum number of iterations
#define TOLERANCE 1e-6 // Tolerance for convergence

// Function to perform Jacobi iteration
void jacobi(double A[N][N], double B[N], double X[N]) {
    int i, j, iter;
    double X_new[N], error, sum;

    // Initializing X_new with zeros
    for(i=0; i<N; i++)
        X_new[i] = 0;

    // Performing Jacobi iteration
    for(iter=0; iter<MAX_ITER; iter++) {
        for(i=0; i<N; i++) {
            sum = 0;
            for(j=0; j<N; j++) {
                if(i != j)
                    sum += A[i][j] * X[j];
            }
            X_new[i] = (B[i] - sum) / A[i][i];
        }

        // Checking for convergence
        error = 0;
        for(i=0; i<N; i++)
            error += fabs(X_new[i] - X[i]);
        if(error < TOLERANCE)
            break;

        // Updating X
        for(i=0; i<N; i++)
            X[i] = X_new[i];
    }

    // Copying the final solution to X
    for(i=0; i<N; i++)
        X[i] = X_new[i];
}

int main() {
    double A[N][N]; // Coefficient matrix
    double B[N];    // Constants matrix
    double X[N];    // Solution matrix
    int i, j;

    // Reading the coefficient matrix
    printf("Enter the coefficient matrix A:\n");
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            printf("Enter A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    // Reading the constants matrix
    printf("\nEnter the constants matrix B:\n");
    for(i=0; i<N; i++) {
        printf("Enter B[%d]: ", i);
        scanf("%lf", &B[i]);
    }

    // Performing Jacobi iteration
    jacobi(A, B, X);

    // Displaying the solution
    printf("\nThe solution is:\n");
    for(i=0; i<N; i++)
        printf("X[%d] = %.6f\n", i, X[i]);

    return 0;
}
