#include <stdio.h>
#include <math.h>
int main() {
    float a[10][10], l[10][10] = {0}, u[10][10] = {0}, x[10] = {0}, z[10] = {0}, b[10] = {0};
    int i = 0, j = 0, k = 0, n;
    float sum = 0;
    printf("Cholesky Method\n\n");
    printf("Enter Dimension of Matrix\n");
    scanf("%d", &n);

    printf("Enter coefficients Matrix\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%f", &a[i][j]);

    printf("Enter RHS vector\n");
    for (i = 0; i < n; i++)
        scanf("%f", &b[i]);

    // Decomposing matrix into Upper and Lower triangular matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sum = 0;
            if (j < i)
                l[j][i] = 0;
            else {
                l[j][i] = a[j][i];
                for (k = 0; k < i; k++) {
                    l[j][i] = l[j][i] - l[j][k] * u[k][i];
                }
            }
        }
        for (j = 0; j < n; j++) {
            if (j < i)
                u[i][j] = 0;
            else if (j == i)
                u[i][j] = 1;
            else {
                u[i][j] = a[i][j] / l[i][i];
                for (k = 0; k < i; k++) {
                    u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
                }
            }
        }
    }

    // Solve for Z using Forward Substitution
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < i; j++)
            sum += l[i][j] * z[j];
        z[i] = (b[i] - sum) / l[i][i];
    }

    // Solve for X using Backward Substitution
    for (i = n - 1; i >= 0; i--) {
        sum = 0;
        for (j = i + 1; j < n; j++)
            sum += u[i][j] * x[j];
        x[i] = (z[i] - sum) / u[i][i];
    }

    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %f\n", i + 1, x[i]);
    }

    return 0;
}
