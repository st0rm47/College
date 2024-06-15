#include <stdio.h>

#define N 3 // Size of the square matrix

// Function to perform Gauss-Jordan elimination for matrix inversion
void gaussJordan(double A[N][N*2]) {
    int i, j, k;
    double temp, pivot;

    // Applying Gauss-Jordan elimination
    for(i=0; i<N; i++) {
        pivot = A[i][i];
        for(j=0; j<N*2; j++) {
            A[i][j] /= pivot;
        }
        for(j=0; j<N; j++) {
            if(j != i) {
                temp = A[j][i];
                for(k=0; k<N*2; k++) {
                    A[j][k] -= temp * A[i][k];
                }
            }
        }
    }

    // Displaying the inverse matrix
    printf("\nThe inverse matrix is:\n");
    for(i=0; i<N; i++) {
        for(j=N; j<N*2; j++) {
            printf("%.2f\t", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double A[N][N*2]; // Augmented matrix for matrix inversion

    // Reading the matrix to be inverted
    printf("Enter the matrix to be inverted:\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("Enter element A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    // Creating an identity matrix as the right side of the augmented matrix
    for(int i=0; i<N; i++) {
        for(int j=N; j<N*2; j++) {
            A[i][j] = (i == j-N) ? 1.0 : 0.0;
        }
    }

    // Applying Gauss-Jordan elimination for matrix inversion
    gaussJordan(A);

    return 0;
}
