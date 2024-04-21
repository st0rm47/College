#include <stdio.h>
#include <math.h>
float f(float x)
{
	return (x*x*x)+1;
}
int main(){
	float x0,xn,h,v,sum;
    printf("Simpson's 3/8 Rule\n\n");
	printf("Enter the lower limit and upper limit: ");
	scanf("%f%f",&x0,&xn);
	h = (xn-x0)/3;
	sum = f(x0) + f(xn);
	for (int i=1;i<3;i++)
	{
		if (i % 3 != 0)
			sum = sum + 3*f(x0 + i*h);
		else
			sum = sum + 2*f(x0 + i*h);
	}
	v = (3.0/8)*h*sum;
	printf("\nThe value obtained after integration is %.4f",v);
}
