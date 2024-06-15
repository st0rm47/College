#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k;
    float A[10][10], L[10][10] = {0}, B[10], Y[10], X[10], sum;

    printf("Enter the number of equations: ");
    scanf("%d", &n);

   printf("Enter the coefficients of the equations:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n + 1; j++)
            scanf("%f", &A[i][j]);

    // Cholesky decomposition
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            sum = 0;
            if (j == i) {
                for (k = 0; k < j; k++)
                    sum += pow(L[j][k], 2);
                L[j][j] = sqrt(A[j][j] - sum);
            } else {
                for (k = 0; k < j; k++)
                    sum += (L[i][k] * L[j][k]);
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }

    // Forward substitution
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < i; j++)
            sum += L[i][j] * Y[j];
        Y[i] = (B[i] - sum) / L[i][i];
    }

    // Backward substitution
    for (i = n - 1; i >= 0; i--) {
        sum = 0;
        for (j = i + 1; j < n; j++)
            sum += L[j][i] * X[j];
        X[i] = (Y[i] - sum) / L[i][i];
    }

    printf("\nThe solution is:\n");
    for (i = 0; i < n; i++)
        printf("x%d = %.2f\n", i + 1, X[i]);

    return 0;
}
