#include <stdio.h>
#include <math.h>
#define MAX 15

int main(){
    float x[MAX], fx[MAX], fd[MAX], xp, s, h, v, p;
    int n, i, j;
    char q;
    printf("Lagrange Interpolation\n\n");
    printf("\nEnter the number of data pairs: ");
    scanf("%d", &n);
    printf("\nEnter data pairs x(i) and values f(i) (one set in each line): ");
    for (i = 1; i <= n; i++)
        scanf("%f%f", &x[i], &fx[i]);
    printf("\nEnter the value at which interpolation is required: ");
    scanf("%f", &xp);
    h = x[2] - x[1];
    s = (xp - x[1]) / h;
    p = 1;
    v = fx[1];
    for (i = 1; i <= n; i++)
        fd[i] = fx[i];
    for (i = 1; i <= n - 1; i++){
        for (j = 1; j <= n - i; j++){
            fd[j] = fd[j + 1] - fd[j];
        }
        p = p * (s - i + 1) / i;
        v = v + p * fd[1];
    }
    printf("\nInterpolated function value at x=%f is %f.", xp, v);
    return 0;
}
