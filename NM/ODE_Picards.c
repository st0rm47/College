#include <stdio.h>
#include <math.h>

// Function representing the ODE dy/dx = f(x, y)
double f(double x, double y) {
    return x + y; // Example: dy/dx = x + y
}

// Picard's iteration method to approximate y(x)
double picard(double x0, double y0, double h, int iterations) {
    double y = y0;
    for (int i = 0; i < iterations; i++) {
        y = y0 + h * f(x0, y);
        y0 = y; // Update the previous approximation
    }
    return y;
}

int main() {
    double x0, y0, h, xmax;
    int iterations;

    // Taking user inputs for initial values, step size, maximum x value, and number of iterations
    printf("Enter initial value of x (x0): ");
    scanf("%lf", &x0);
    printf("Enter initial value of y (y0): ");
    scanf("%lf", &y0);
    printf("Enter step size (h): ");
    scanf("%lf", &h);
    printf("Enter maximum value of x (xmax): ");
    scanf("%lf", &xmax);
    printf("Enter number of iterations: ");
    scanf("%d", &iterations);

    printf("x\t\ty (approx)\n");
    printf("%lf\t%lf\n", x0, y0);

    while (x0 < xmax) {
        y0 = picard(x0, y0, h, iterations);
        x0 += h;
        printf("%lf\t%lf\n", x0, y0);
    }

    return 0;
}
