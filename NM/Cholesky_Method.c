#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j, k;
    float A[10][10], L[10][10], U[10][10] = {0}, B[10], Z[10], X[10], sum;

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    printf("Enter the coefficients of the equations:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%f", &A[i][j]);

    printf("Enter the constants (B matrix):\n");
    for (i = 0; i < n; i++)
        scanf("%f", &B[i]);

    // Cholesky decomposition
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            sum = 0;
            if (i == j)
            {
                for (k = 0; k < j; k++)
                    sum += pow(U[k][i], 2);
                U[i][i] = sqrt(A[i][i] - sum);
            }
            else
            {
                for (k = 0; k < i; k++)
                    sum += (U[k][i] * U[k][j]);
                U[i][j] = (A[i][j] - sum) / U[i][i];
            }
        }
    }

    // Find Transpose of L
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            L[i][j] = U[j][i];
    }

    // Forward substitution
    Z[0] = B[0];// Corrected initialization
    for (i = 1; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < i; j++)
            sum += (L[i][j] * Z[j]);
            Z[i] = (B[i] - sum);
    }

    // Backward substitution
    X[n - 1] = Z[n - 1] / U[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        sum = 0;
        for (j = i + 1; j < n; j++)
            sum += U[i][j] * X[j];
            X[i] = (Z[i] - sum) / U[i][i];
    }

    printf("\nThe solution is:\n");
    for (i = 0; i < n; i++)
        printf("x%d = %.2f\n", i + 1, X[i]);

    return 0;
}
