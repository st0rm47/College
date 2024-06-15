#include <stdio.h>
#include <math.h>
int main()
{
    int n, i, j;
    float a[10][10], old_x[10], new_x[10], sum, E[10], error;
    printf("Gauss Seidel Iterative Method\n\n");
    printf("Enter the number of equations: ");
    scanf("%d", &n);
    printf("Enter the coefficients of the equations:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j <= n; j++)
            scanf("%f", &a[i][j]);

    printf("Enter the error tolerance: ");
    scanf("%f", &error);
    for (i = 0; i <= n; i++)
    {
        new_x[i] = 0;
    }
    while (1)
    {
        for (i = 0; i < n; i++)
        {
            sum = a[i][n];
            for (j = 0; j < n; j++)
            {
                if (i != j)
                    sum = sum - a[i][j] * new_x[j];
            }
            old_x[i] = new_x[i];
            new_x[i] = sum / a[i][i];
            E[i] = fabs(new_x[i] - old_x[i]) / fabs(new_x[i]);
        }
        int flag = 1;
        for (i = 0; i < n; i++)
        {
            if (E[i] > error) {
                break;
            }
        }
        if (i==n)
            break;
        else 
            continue;
    }
    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
        printf("x%d = %6.2f\n", i + 1, new_x[i]);
    return 0;
}
