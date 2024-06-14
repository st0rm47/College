#include<stdio.h>
#include<math.h>
#define f(x,y) 2*x +y
int main()
{
    float x0, y0, h, x, y, xp, m1, m2, m3, m4;
    printf("Fourth Order Runge-Kutta Method\n\n");
    printf("Enter the value of x0 and y0 and x:");
    scanf("%f%f%f", &x0, &y0, &xp);
    printf("Enter the step size: ");
    scanf("%f", &h);
    x = x0;
    y = y0;
    for (x= x0; x < xp ; x=x+h){
        m1 = f(x,y);
        m2 = f(x+h/2, y+h/2*m1);
        m3 = f(x+h/2, y+h/2*m2);
        m4 = f(x+h, y+h*m3);
        y = y + h/6*(m1+2*m2+2*m3+m4);
    }
    printf("\nValue of y at x = %f is %f\n", xp, y);
    return 0;
}
        