#include<stdio.h>
#include<math.h>
#define f(x) x+2
int main(){
    float x0,xn,k,h,sum,i,v;
    printf("Trapezoidal Rule\n\n");
    printf("Enter the lower limit and upper limit: ");
    scanf("%f%f",&x0,&xn);
    h = (xn-x0);
    sum = f(x0) + f(xn);
    v = (h/2)*sum;
    printf("\nThe value obtained after integration is %.2f",v);
}