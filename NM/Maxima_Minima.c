#include <stdio.h>
void findMaximaMinima(int n, double x[], double y[]) {
    printf("\nLocal maxima and minima:\n");
    for (int i = 1; i < n - 1; i++) {
        if (y[i] > y[i - 1] && y[i] > y[i + 1]) {
            printf("Local maximum at x = %.2f, y = %.2f\n", x[i], y[i]);
        }
        if (y[i] < y[i - 1] && y[i] < y[i + 1]) {
            printf("Local minimum at x = %.2f, y = %.2f\n", x[i], y[i]);
        }
    }
}
int main() {
    int n;
    double x[n], y[n];
    printf("Maxima and Minima\n\n");
    printf("Enter the number of data points: ");
    scanf("%d", &n) ;

    printf("Enter the x and y values:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d], y[%d]: ", i, i);
        scanf("%lf %lf", &x[i], &y[i]);
    }
    findMaximaMinima(n, x, y);
}
