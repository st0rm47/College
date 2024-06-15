#include <stdio.h>
#include <math.h>
#define y1(x) 1 + x + pow(x,2)/2
#define y2(x) 1 + x + pow(x,2)/2 + pow(x,3)/3 + pow(x,4)/8
#define y3(x) 1 + x + pow(x,2)/2 + pow(x,3)/3 + pow(x,4)/8 + pow(x,5)/15 + pow(x,6)/48

int main(){
    float x0, y0, h, x, y, xp;
    printf("Picard's Method\n\n");
    printf("Enter the value of x0, y0: ");
    scanf("%f%f", &x0, &y0);
    printf("Enter the value of x to be evaluated: ");
    scanf("%f", &xp);
    y = y0;
    y = y1(xp);
    y = y2(xp);
    y = y3(xp);
    printf("\nThe value of y at x = %.2f is approximately %.4f\n", xp, y);
    return 0;

}

