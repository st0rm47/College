#include <stdio.h>
#include <math.h>
int a1, a2, a3, a0;
float f(float x)
{
    return a3 * x * x * x + a2 * x * x + a1 * x + a0;
}
float g(float x)
{
    return (-a0 - a3 * x * x * x - a2 * x * x) / a1;
}
int main()
{
    float x0, gx0, x1, E, Era;
    int i = 1;
    printf("Fixed Point Method\n\n");
    printf("Enter the coefficients of a3, a2, a1, and a0: \n");
    scanf("%d%d%d%d", &a3, &a2, &a1, &a0);
    printf("Enter initial guess and error precision:\n");
    scanf("%f%f", &x0, &E);
    while (1)
    {
        x1 = g(x0);
        Era = fabs((x1 - x0) / x1);
        if (Era >= E){
            x0 = x1;
            i++;
        }
        else{
            printf("The root is %f.\n", x1);
            printf("No. of iteration = %d", i);
            break;
        }
    }
}