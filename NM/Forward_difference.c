#include <stdio.h>
int a3, a2, a1, a0;
double f(double x){
    return (a3 * x * x * x + a2 * x * x + a1 * x + a0);
}
int main(){
    double h, x;
    printf("Forward Difference Formula\n\n");
    printf("Enter values of a3, a2, a1, and a0 respectively: ");
    scanf("%d%d%d%d", &a3, &a2, &a1, &a0);
    printf("Enter value of h: ");
    scanf("%lf", &h);
    printf("Enter value at which derivative is needed: ");
    scanf("%lf", &x);
    double d = (f(x + h) - f(x)) / h;
    printf("Derivative = %.2lf", d);  
}