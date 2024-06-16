#include<stdio.h>
#include<math.h>
#define f(x) x * x*x +1
int main(){
    float x0,x1,x2,xn,h,sum,v;
    printf("Simpson's 3/8 Rule\n\n");
    printf("Enter the lower limit and upper limit: ");
    scanf("%f%f",&x0,&xn);
    h = (xn - x0) / 3;
    x1 = x0 + h;
    x2 = x1 + h;
    sum = f(x0) + 3*f(x1) + 3*f(x2) + f(xn);
    v = (3.0 / 8) * h * sum;
    printf("\nThe value obtained after integration is %.2f",v);
    return 0;
}