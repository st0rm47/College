#include<stdio.h>
#include<math.h>
int main(){
    int n, i, j, k, p;
    float a[10][10], x[10], c, sum = 0.0, temp;
    printf("Gauss Elimination with Pivoting\n\n");
    printf("Enter the number of equations: ");
    scanf("%d", &n);
    printf("Enter the coefficients of the equations:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n + 1; j++)
            scanf("%f", &a[i][j]);
    for (i = 0; i < n; i++) {
        p = i;
        for (j = i + 1; j < n; j++)
            if (fabs(a[j][i]) > fabs(a[p][i]))
                p = j;
        for (k = 0; k < n + 1; k++) {
            temp = a[i][k];
            a[i][k] = a[p][k];
            a[p][k] = temp;
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