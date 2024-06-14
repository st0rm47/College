#include <stdio.h>

// Function to calculate f(x)
double f(double x) {
    return x * x;
}

// Function to calculate the integral of f(x) using the composite Simpson's 3/8 rule
double compositeSimpsons38(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b); // Initialize sum with f(a) + f(b)

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += i % 3 == 0 ? 2 * f(x) : 3 * f(x); // Add 2*f(x) if i is a multiple of 3, else add 3*f(x)
    }

    return (3 * h / 8) * sum;
}

int main() {
    double a, b;
    int n;

    printf("Enter the lower limit of integration (a): ");
    scanf("%lf", &a);
    printf("Enter the upper limit of integration (b): ");
    scanf("%lf", &b);
    printf("Enter the number of subintervals (n, must be multiple of 3): ");
    scanf("%d", &n);

    if (n % 3 != 0) {
        printf("Error: Number of subintervals must be a multiple of 3 for Simpson's 3/8 rule.\n");
        return 1;
    }

    double integral = compositeSimpsons38(f, a, b, n);

    printf("The approximate value of the integral is: %.6f\n", integral);

    return 0;
}
