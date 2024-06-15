#include <stdio.h>
#include <math.h>

// Function representing the ODE dy/dx = f(x, y)
double f(double x, double y) {
    return x + y; // Example: dy/dx = x + y
}

// Fourth-order Runge-Kutta method to approximate y(x)
double runge_kutta(double x0, double y0, double h) {
    double k1, k2, k3, k4;
    k1 = h * f(x0, y0);
    k2 = h * f(x0 + h/2, y0 + k1/2);
    k3 = h * f(x0 + h/2, y0 + k2/2);
    k4 = h * f(x0 + h, y0 + k3);
    return y0 + (k1 + 2*k2 + 2*k3 + k4) / 6;
}

int main() {
    double x0, y0, h, xmax;

    // Taking user inputs for initial values, step size, and maximum x value
    printf("Enter initial value of x (x0): ");
    scanf("%lf", &x0);
    printf("Enter initial value of y (y0): ");
    scanf("%lf", &y0);
    printf("Enter step size (h): ");
    scanf("%lf", &h);
    printf("Enter maximum value of x (xmax): ");
    scanf("%lf", &xmax);

    printf("x\t\ty (approx)\n");
    printf("%lf\t%lf\n", x0, y0);

    while (x0 < xmax) {
        y0 = runge_kutta(x0, y0, h);
        x0 += h;
        printf("%lf\t%lf\n", x0, y0);
    }

    return 0;
}
