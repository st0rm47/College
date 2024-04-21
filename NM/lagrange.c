//lagrange interpretation
#include <stdio.h>
#include <math.h>
#include <conio.h>
int main()
{
	float x,v,l;
	int i,j,n;
	printf("Enter the number of points: ");
	scanf("%d",&n);
	printf("Enter value of x: ");
	scanf("%f",&x);
	float xi[n],L[n],fx[n];
	for (i=0;i<n;i++)
	{
		printf("\nPoint %d:\n",i+1);
		printf("Enter x: ");
		scanf("%f",&xi[i]);
		printf("Enter fx:");
		scanf("%f",&fx[i]);
	}
	for (i=0;i<n;i++)
	{
		l=1.0;
		for(j=0;j<n;j++)
		{
			if (j!=i)
			{
				l=l*((x-xi[j])/(xi[i]-xi[j]));
			}
		}
		L[i]=l;
	}
	for (i=0;i<n;i++)
	{
		v= v + (fx[i] * L[i]);
	}
	printf("Value of v = %f",v);
	return 0;
}