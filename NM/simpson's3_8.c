#include <stdio.h>
#include <conio.h>
#include <math.h>
float func(float x)
{
	return 1/(x+4);
}
int main()
{
	int i,k;
	float x0,xn,h,sum,v;
	printf("Enter the lower limit and upper limit:\n");
	printf("\nLower Limit = ");
	scanf("%f",&x0);
	printf("\nUpper Limit = ");
	scanf("%f",&xn);
	printf("\nEnter the number of segments:\t");
	scanf("%d",&k);
	h = (xn-x0)/k;
	sum = func(x0) + func(xn);
	for (i=1;i<k;i++)
	{
		if (i % 3 != 0)
			sum = sum + 3*func(x0 + i*h);
		else
			sum = sum + 2*func(x0 + i*h);
	}
	v = (3.0/8)*h*sum;
	printf("\nThe value obtained after integration is %.4f",v);
}
