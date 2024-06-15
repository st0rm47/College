#include<stdio.h>
#include<math.h>
int main(){
    int n, i, j;
    float A[10][10], X[10], Xnew[10], sum, error, epsilon;
    printf("Gauss Jacobi Iterative Method\n\n");
    printf("Enter the number of equations: ");
    scanf("%d", &n);
    printf("Enter the coefficients of the equations:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n + 1; j++)
            scanf("%f", &A[i][j]);
    printf("Enter the error tolerance: ");
    scanf("%f", &epsilon);
    for (i = 0; i < n; i++)
        X[i] = 0;
    do {
        for (i = 0; i < n; i++) {
            sum = 0;
            for (j = 0; j < n; j++)
                if (j != i)
                    sum += A[i][j] * X[j];
            Xnew[i] = (A[i][n] - sum) / A[i][i];
        }
        error = 0;
        for (i = 0; i < n; i++)
            if (fabs(Xnew[i] - X[i]) > error)
                error = fabs(Xnew[i] - X[i]);
        for (i = 0; i < n; i++)
            X[i] = Xnew[i];
    } while (error > epsilon);
    printf("\nThe solution is:\n");
    for (i = 0; i < n; i++)
        printf("x%d = %.2f\n", i + 1, X[i]);
    return 0;
}