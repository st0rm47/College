#include <stdio.h>
#include <math.h>

float f(float n)
{
    return sqrt(1 - n * n);
}

int main()
{
    float h;
    float x0, x2;

    printf("Enter upper limit and lower limit respectively: ");
    scanf("%f%f", &x2, &x0);

    h = (x2 - x0) / 2;
    float x1 = x0 + h;
    float v = (h / 3) * (f(x0) + 4 * f(x1) + f(x2));

    printf("Integration = %f", v);

    return 0;
}
