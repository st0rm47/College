#include <stdio.h>
#define MAX 15

int main(){
    float x[MAX], fx[MAX], fd[MAX], xp, s, h, v, p;
    int n, i, j;
    char q;
    printf("Lagrange Interpolation\n\n");
    printf("Enter the number of data pairs: ");
    scanf("%d", &n);
    printf("Enter data pairs x(i) and values f(i): ");
    for (i = 0; i < n; i++)
        scanf("%f%f", &x[i], &fx[i]);
    printf("\nEnter the value at which interpolation is required: ");
    scanf("%f", &xp);
    h = x[1] - x[0];
    s = (xp - x[0]) / h;
    v = 0;
    for (i = 0; i < n; i++) {
        fd[i] = fx[i];
        p = 1;
        for (j = 0; j < n; j++) {
            if (i != j) {
                p *= (s - j) / (i - j);
            }
        }
        v += p * fd[i];
    }
    printf("\nInterpolated function value at x=%.4f is %.4f", xp, v);
    return 0;
}
