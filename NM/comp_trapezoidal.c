#include <stdio.h>

// Function to calculate f(x)
double f(double x) {
    return x * x;
}

// Function to calculate the integral of f(x) using the composite trapezoidal rule
double compositeTrapezoidal(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b)); // Initialize sum with 0.5 * (f(a) + f(b))

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    return h * sum;
}

int main() {
    double a, b;
    int n;

    printf("Enter the lower limit of integration (a): ");
    scanf("%lf", &a);
    printf("Enter the upper limit of integration (b): ");
    scanf("%lf", &b);
    printf("Enter the number of subintervals (n): ");
    scanf("%d", &n);

    double integral = compositeTrapezoidal(f, a, b, n);

    printf("The approximate value of the integral is: %.6f\n", integral);

    return 0;
}
