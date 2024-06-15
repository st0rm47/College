#include<stdio.h>
#include<math.h>
#define f(x,y) 2*y/x
int main()
{
    float x0, y0, h, x, y,xp;
    printf("Euler's Method\n\n");
    printf("Enter the value of x0, y0: ");
    scanf("%f%f", &x0, &y0);
    printf("Enter the value of x to be evaluated: ");
    scanf("%f", &xp);
    printf("Enter the step size: ");
    scanf("%f", &h);
    x = x0;
    y = y0;
    for (x= x0; x < xp ; x=x+h){
        y = y + h * f(x, y);
    }
    printf("\nThe value of y at x = %.2f is approximately %.4f\n", x, y);
    return 0;
}