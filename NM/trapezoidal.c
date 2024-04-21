#include <stdio.h>
#include <conio.h>
#include <math.h>
float func(float x)
{
	return sqrt(1+x*x);
}
int main()
{
	float x0,xn,k,h,sum,i,v;
	printf("Enter the lower limit and upper limit:\n");
	printf("\nLower Limit = ");
	scanf("%f",&x0);
	printf("\nUpper Limit = ");
	scanf("%f",&xn);
	printf("\nEnter the number of segments:\t");
	scanf("%f",&k);
	h = (xn-x0)/k;
	sum = func(x0) + func(xn);
	for (i=1;i<k;i++)
	{
		sum = sum + 2*func(x0 + i*h);
	}
	v = (h/2)*sum;
	printf("\nThe value obtained after integration is %.2f",v);
}
