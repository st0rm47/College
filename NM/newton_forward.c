#include <stdio.h>
int fac(int n){
    if (n == 1 || n == 0)
        return 1;
    else
        return n * fac(n - 1);
}
int main() {
    int n, i, j, k;
    float a[n], b[n], x[n], xp, h, s;
    printf("Forward Difference Interpolation\n\n");
    printf("Enter the number of data pairs: ");
    scanf("%d", &n);
    printf("Enter data pairs x(i) and values f(i): ");
    for (i = 0; i < n; i++)
        scanf("%f%f", &a[i], &b[i]);
    printf("Enter the value of a where you want to evaluate b: ");
    scanf("%f", &xp);
    h = a[1] - a[0];
    s = (xp - a[0]) / h;
    for (i = 0; i < n; i++) {
        x[i] = b[i];
    }
    for (i = 0; i <= n - 1; i++) {
        for (j = n - 1; j >= i + 1; j--) {
            x[j] = x[j] - x[j - 1];
        }
    }
    float v, p;
    v = x[0];
    for (i = 1; i <= n - 1; i++) {
        p = 1;
        for (k = 1; k <= i; k++) {
            p = p * (s - k + 1);
        }
        v = v + ((x[i] * p) / fac(i));
    }
    printf("The interpolated value of a=%.4f is %.4f", xp, v);
    return 0;
}
