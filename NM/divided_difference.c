//divided difference interpolation
#include <stdio.h>
#include <math.h>
#include <conio.h>
int main()
{
	float x,v,p;
	int i,j,n;
	printf("Enter the number of points: ");
	scanf("%d",&n);
	printf("Enter value of x: ");
	scanf("%f",&x);
	float xi[n],dd[n],fx[n];
	for (i=0;i<n;i++)
	{
		printf("\nPoint %d:\n",i+1);
		printf("Enter x: ");
		scanf("%f",&xi[i]);
		printf("Enter fx: ");
		scanf("%f",&fx[i]);
	}
	for(i=0;i<n;i++)
	{
		dd[i]=fx[i];
	}

	for(i=0;i<n;i++)
	{
		for(j=n-1;j>i;j--)
		{
			dd[j]=(dd[j]-dd[j-1])/(xi[j]-xi[j-1-i]);
		}
	}
	v=0;
	p=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			p=p*(x-xi[j]);
		}
		v=v+dd[i]*p;
		p=1;
	}
	printf("v = %f",v);
	return 0;
}