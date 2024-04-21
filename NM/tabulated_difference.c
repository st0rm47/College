#include <stdio.h>

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    float xp, h, s, val, prevterm, term1, term2;
    int n, i, j, k;

    printf("Enter number of points: ");
    scanf("%d", &n);

    printf("Enter point at which derivative is needed: ");
    scanf("%f", &xp);

    float x[n], fx[n], fd[n];

    printf("\nEnter the data points:\n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("\nPoint %d:\n", i);
        printf("Enter x: ");
        scanf("%f", &x[i]);
        printf("Enter fx: ");
        scanf("%f", &fx[i]);
    }

    h = x[1] - x[0];
    s = (xp - x[0]) / h;

    for (i = 0; i <= n - 1; i++)
    {
        fd[i] = fx[i];
    }

    for (i = 0; i <= n - 1; i++)
    {
        for (j = n - 1; j >= i + 1; j--)
        {
            fd[j] -= fd[j - 1];
        }
    }

    val = fd[1];
    prevterm = 1;

    for (i = 2; i <= n - 1; i++)
    {
        term1 = 1;

        for (k = 2; k <= i; k++)
        {
            term1 *= (s - k + 2);
        }

        term2 = term2 + (s - i + 1) * prevterm;
        prevterm = term1 + term2;
        val = val + (fd[i] * (term1 + term2)) / factorial(i);
    }

    val = val / h;
    printf("\nValue of first derivative = %.3f", val);

    return 0;
}