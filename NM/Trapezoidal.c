#include <stdio.h>
#include <math.h>
/* Define function here */
#define f(x) 1 / (1 + pow(x, 2))
int main()
{
    float x0, xn, integration = 0.0, h, a;
    int i,k;
    printf("Composite Trapezoidal Rule\n\n");
    printf("Enter lower and upper limit: ");
    scanf("%f%f", &x0, &xn);
    printf("Enter number of segments: ");
    scanf("%d", &k);
    h = (xn - x0) / k;
    integration = f(x0) + f(xn);
    for (i = 1; i < k-1; i++)
    {
        a = x0 + i * h;
        integration += 2 * f(a);
    }
    integration *= h / 2;
    printf("\nValue of integration is: %.3f", integration);
    return 0;
}
