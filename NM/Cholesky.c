#include <stdio.h>
#include <math.h>

#define N 3 // Size of the square matrix

// Function to perform Cholesky decomposition
void cholesky(double A[N][N], double L[N][N]) {
    int i, j, k;
    double sum;

    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
            sum = 0;
            if (j == i) {
                for (k = 0; k < j; k++)
                    sum += L[j][k] * L[j][k];
                L[j][j] = sqrt(A[j][j] - sum);
            } else {
                for (k = 0; k < j; k++)
                    sum += L[i][k] * L[j][k];
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
}

int main() {
    double A[N][N]; // Input matrix
    double L[N][N] = {0}; // Lower triangular matrix

    // Reading the matrix from the user
    printf("Enter the matrix:\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("Enter element A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    // Performing Cholesky decomposition
    cholesky(A, L);

    // Displaying the Lower triangular matrix
    printf("\nLower Triangular Matrix L:\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%.2f\t", L[i][j]);
        }
        printf("\n");
    }

    return 0;
}
