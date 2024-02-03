#include <stdio.h>
#include <math.h>
int a3, a2, a1, a0;
float f(float x) {
    return (a3 * x * x * x + a2 * x * x + a1 * x + a0);
}
int main()
{
    float x0, x1, x2, fx1, fx0, E, Era;
    printf("Secant Method\n\n");
    printf("Enter the coefficients of a3, a2, a1, and a0: \n");
    scanf("%d%d%d%d", &a3, &a2, &a1, &a0);
    printf("Enter initial guesses and Error : \n");
    scanf("%f%f%f", &x1, &x0, &E);
    fx1 = f(x1);
    fx0 = f(x0);
    while (1)
    {
        x2 = x1 - ((f(x1) * (x1 - x0)) / (f(x1) - f(x0)));
        fx1 = f(x2);
        Era = fabs((x2 - x1) / x2);
        if (Era < E)
        {
            printf("Root = %f\n", x2);
            break;
        }
        x0 = x1;
        x1 = x2;
    }
    return 0;
}