#include <stdio.h>
#include <math.h>
float f(float x){
	return sqrt(1+x*x);
}
int main(){
	float x0,xn,k,h,sum,i,v;
	printf("Trapezoidal Rule\n\n");
	printf("Enter the lower limit and upper limit: ");
	scanf("%f%f",&x0,&xn);
	printf("Enter the number of segments: ");
	scanf("%f",&k);
	h = (xn-x0)/k;
	sum = f(x0) + f(xn);
	for (i=1;i<k;i++)
	{
		sum = sum + 2*f(x0 + i*h);
	}
	v = (h/2)*sum;
	printf("\nThe value obtained after integration is %.2f",v);
}
