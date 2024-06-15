#include<stdio.h>
#include<math.h>
int main(){
    int n, i;
    float x, a[n+1], b[n];
    printf("Horner's Method\n\n");
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficients of the polynomial: ");
    for (i=0; i<=n; i++){
        scanf("%f", &a[i]);
    }
    printf("Enter the value of x: ");
    scanf("%f", &x);
    b[0] = a[0];
    for (i=1; i<=n; i++){
        b[i] = a[i] + b[i-1]*x;
    }
    printf("\nThe value of the polynomial at x = %.2f is %.2f\n", x, b[n]);
    return 0;
}