#include <stdio.h>
#include <math.h>
float f(float n){
    return sqrt(1 - n * n);
}
int main(){
	float x0,xn,x1,h,v;
    printf("Simpson's 1/3 Rule\n\n");
	printf("Enter the lower limit and upper limit: ");
	scanf("%f%f",&x0,&xn);
    h = (xn - x0) / 2;
    x1 = x0 + h;
    v = (h / 3) * (f(x0) + 4 * f(x1) + f(xn));
    printf("\nThe value obtained after integration is %.2f",v);
    return 0;
}
