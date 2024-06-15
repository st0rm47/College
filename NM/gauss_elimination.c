#include <stdio.h>
#include <stdlib.h>

#define N 3 // Number of equations

// Function to perform Gauss elimination
void gaussElimination(double A[N][N+1]) {
    int i, j, k;
    double ratio, temp;

    // Forward Elimination
    for(i=0; i<N-1; i++) {
        for(j=i+1; j<N; j++) {
            ratio = A[j][i] / A[i][i];
            for(k=i; k<N+1; k++) {
                A[j][k] -= ratio * A[i][k];
            }
        }
    }

    // Back Substitution
    double x[N];
    for(i=N-1; i>=0; i--) {
        x[i] = A[i][N];
        for(j=i+1; j<N; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    // Displaying the solution
    printf("\nThe solution is:\n");
    for(i=0; i<N; i++) {
        printf("x[%d] = %.2f\n", i+1, x[i]);
    }
}

int main() {
    double A[N][N+1]; // Augmented matrix

    // Reading augmented matrix coefficients
    printf("Enter the coefficients of the equations:\n");
    for(int i=0; i<N; i++) {
        printf("Equation %d:\n", i+1);
        for(int j=0; j<=N; j++) {
            printf("Enter coefficient A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    // Applying Gauss elimination
    gaussElimination(A);

    return 0;
}
