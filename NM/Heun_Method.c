#include<stdio.h>
#include<math.h>
#define f(x,y) x*x +y
int main()
{
    float x0, y0, h, x, y,xp, m1, m2;
    printf("Heun's Method\n\n");
    printf("Enter the value of x0, y0 and x: ");
    scanf("%f%f%f", &x0, &y0, &xp);
    printf("Enter the step size: ");
    scanf("%f", &h);
    x = x0;
    y = y0;
    for (x= x0; x < xp ; x=x+h){
        m1 = f(x, y);
        m2 = f(x+h, y + h * m1);
        y = y + (h/2) * (m1 + m2);
    }
    printf("\nThe value of y at x = %.2f is approximately %.4f\n", x, y);
    return 0;
}