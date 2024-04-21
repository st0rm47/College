#include <stdio.h>
int fac(int n){
    if (n == 1 || n == 0)
        return 1;
    else
        return n * fac(n - 1);
}
int main() {
    int n, i, j, k;
    float x[n], fx[n], dd[n], xp, h, s;
    printf("Forward Difference Interpolation\n\n");
    printf("Enter the number of data pairs: ");
    scanf("%d", &n);
    printf("Enter data pairs x(i) and values f(i): ");
    for (i = 0; i < n; i++)
        scanf("%f%f", &x[i], &fx[i]);
    printf("\nEnter the value at which interpolation is required: ");
    scanf("%f", &xp);
    h = x[1] - x[0];
    s = (xp - x[0]) / h;
    for (i = 0; i < n; i++) {
        dd[i] = fx[i];
    }
    for (i = 0; i <= n - 1; i++) {
        for (j = n - 1; j >= i + 1; j--) {
            dd[j] = dd[j] - dd[j - 1];
        }
    }
    float v, p;
    v = dd[0];
    for (i = 1; i <= n - 1; i++) {
        p = 1;
        for (k = 1; k <= i; k++) {
            p = p * (s - k + 1);
        }
        v = v + ((dd[i] * p) / fac(i));
    }
    printf("The interpolated value of a=%.4f is %.4f", xp, v);
    return 0;
}
