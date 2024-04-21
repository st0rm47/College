#include <stdio.h>
#include <math.h>
int main()
{
    float x[15], fx[15], dd[15], xp, v, p;
    int i, j, n;
    printf("Divided Difference Interpolation\n\n");
    printf("Enter the number of data pairs: ");
    scanf("%d", &n);
    printf("Enter data pairs x(i) and values f(i): ");
    for (i = 0; i < n; i++)
        scanf("%f%f", &x[i], &fx[i]);
    printf("\nEnter the value at which interpolation is required: ");
    scanf("%f", &xp);
    for (i = 0; i < n; i++){
        dd[i] = fx[i];
	} 
	for (i = 0; i < n; i++){
        for (j = n - 1; j > i; j--){
            dd[j] = (dd[j] - dd[j - 1]) / (x[j] - x[j - 1 - i]);
    	}
	}
    v = 0;
    p = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
            p = p * (xp - x[j]);
        v = v + dd[i] * p;
        p = 1;
    }
    printf("Interpolated function value at x = %.4f is %.4f.", xp, v);
    return 0;
}
