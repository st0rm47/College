#include <stdio.h>
int main() {
    int n, i, j, k;
    float a[10][20], c;
    printf("Matrix Inversion\n\n");
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)
                a[i][j + n] = 1.0;
            else
                a[i][j + n] = 0.0;
        }
    }
    for (i = 0; i < n; i++) {
        if (a[i][i] == 0.0) {
            printf("Mathematical Error! Division by zero.\n");
            return 0;
        }
        for (j = 0; j < n; j++) {
            if (i != j) {
                c = a[j][i] / a[i][i];
                for (k = 0; k < 2 * n; k++)
                    a[j][k] = a[j][k] - c * a[i][k];
            }
        }
    }
    for (i = 0; i < n; i++) {
        c = a[i][i];
        for (j = 0; j < 2 * n; j++)
            a[i][j] = a[i][j] / c;
    }
    printf("\nThe inverse of the matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = n; j < 2 * n; j++)
            printf("%.2f\t", a[i][j]);
        printf("\n");
    }
    return 0;
}
