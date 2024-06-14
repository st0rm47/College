#include <stdio.h>

#define N 3 // Size of the square matrix

// Function to perform Doolittle LU decomposition
void doolittleLU(double A[N][N], double L[N][N], double U[N][N]) {
    int i, j, k;
    double sum;

    // Decomposing matrix into LU
    for (i = 0; i < N; i++) {

        // Upper Triangular
        for (j = i; j < N; j++) {
            // Summation of L(i, k) * U(k, j)
            sum = 0;
            for (k = 0; k < i; k++)
                sum += (L[i][k] * U[k][j]);

            // Evaluating U(i, j)
            U[i][j] = A[i][j] - sum;
        }

        // Lower Triangular
        for (j = i; j < N; j++) {
            if (i == j)
                L[i][i] = 1; // Diagonal as 1
            else {
                // Summation of L(j, k) * U(k, i)
                sum = 0;
                for (k = 0; k < i; k++)
                    sum += (L[j][k] * U[k][i]);

                // Evaluating L(j, i)
                L[j][i] = (A[j][i] - sum) / U[i][i];
            }
        }
    }
}

int main() {
    double A[N][N]; // Input matrix
    double L[N][N]; // Lower triangular matrix
    double U[N][N]; // Upper triangular matrix

    // Reading the matrix from the user
    printf("Enter the matrix:\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("Enter element A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    // Performing Doolittle LU decomposition
    doolittleLU(A, L, U);

    // Displaying the Lower triangular matrix
    printf("\nLower Triangular Matrix L:\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%.2f\t", L[i][j]);
        }
        printf("\n");
    }

    // Displaying the Upper triangular matrix
    printf("\nUpper Triangular Matrix U:\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%.2f\t", U[i][j]);
        }
        printf("\n");
    }

    return 0;
}
