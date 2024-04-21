#include <stdio.h>
int main() {
    float sx = 0, sy = 0, sxy = 0, sx2 = 0, a, b, xp = 0;
    int n, i;
    float x[n], y[n];
    printf("Linear Regression\n\n");
    printf("Enter number of points: ");
    scanf("%d", &n);
    printf("Enter the value of x to estimate: ");
    scanf("%f", &xp);
    printf("Enter values ofx and fx: ");
    for (i = 0; i < n; i++)
        scanf("%f%f", &x[i], &y[i]);
    for (i = 0; i < n; i++) {
        sx += x[i];
        sy += y[i];
        sxy += x[i] * y[i];
        sx2 += x[i] * x[i];
    }
    b = ((n * sxy) - (sx * sy)) / ((n * sx2) - (sx * sx));
    a = (sy / n) - (b * sx / n);
    printf("\nRegression equation: y = %.2f + %.2fx", a, b);
    printf("\nf(%.1f) = %.2f", xp, (a + b * xp));
    return 0;
}