#include<stdio.h>
#include<math.h>
int main(){
    int n, i, j, k, p;
    float a[10][10], x[10], c, sum = 0.0, temp;
    printf("DoLittle's LU Decomposition Method\n\n");
    printf("Enter the number of equations: ");
    scanf("%d", &n);
    printf("Enter the coefficients of the equations:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n + 1; j++)
            scanf("%f", &a[i][j]);
    for (i = 0; i < n; i++) {
        if (a[i][i] == 0.0) {
            printf("Mathematical Error!");
            return 0;
        }
        for (j = 0; j < n; j++) {
            if (i != j) {
                c = a[j][i] / a[i][i];
                for (k = 0; k < n + 1; k++)
                    a[j][k] = a[j][k] - c * a[i][k];
            }
        }
    }
    printf("\nThe solution is:\n");
    for (i = 0; i < n; i++) {
        x[i] = a[i][n] / a[i][i];
        printf("x%d = %.2f\n", i + 1, x[i]);
    }
    return 0;
}