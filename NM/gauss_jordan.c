#include <stdio.h>

#define N 3 // Number of equations

// Function to perform Gauss-Jordan elimination
void gaussJordan(double A[N][N+1]) {
    int i, j, k;
    double temp, pivot;

    // Applying Gauss-Jordan elimination
    for(i=0; i<N; i++) {
        pivot = A[i][i];
        for(j=0; j<N+1; j++) {
            A[i][j] /= pivot;
        }
        for(j=0; j<N; j++) {
            if(j != i) {
                temp = A[j][i];
                for(k=0; k<N+1; k++) {
                    A[j][k] -= temp * A[i][k];
                }
            }
        }
    }

    // Displaying the solution
    printf("\nThe solution is:\n");
    for(i=0; i<N; i++) {
        printf("x[%d] = %.2f\n", i+1, A[i][N]);
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

    // Applying Gauss-Jordan elimination
    gaussJordan(A);

    return 0;
}
