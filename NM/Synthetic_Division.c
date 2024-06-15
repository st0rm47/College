#include<stdio.h>
#include<math.h> 
int main()
{
    int n, i, j, k;
    printf("Synthetic Division\n\n");
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &n);
    float a[n+1], b[n], c[n-1];
    printf("Enter the coefficients of the polynomial: ");
    for (i=0; i<=n; i++){
        scanf("%f", &a[i]);
    }
    printf("Enter the divisor: ");
    float d;
    scanf("%f", &d);
    b[0] = a[0];
    for (i=1; i<=n; i++){
        b[i] = a[i] + b[i-1]*d;
    }
    c[0] = b[1];
    for (i=1; i<n; i++){
        c[i] = b[i+1] + c[i-1]*d;
    }
    printf("\nThe coefficients of the quotient are: ");
    for (i=0; i<n; i++){
        printf("%.2f ", b[i]);
    }
    printf("\nThe remainder is: %.2f\n", c[n-1]);
    return 0;
}