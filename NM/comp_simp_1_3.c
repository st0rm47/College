#include <stdio.h>

// Function to calculate f(x)
double f(double x) {
    return x * x;
}

// Function to calculate the integral of f(x) using the composite Simpson's 1/3 rule
double compositeSimpsons13(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b); // Initialize sum with f(a) + f(b)

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += i % 2 == 0 ? 2 * f(x) : 4 * f(x); // Add 2*f(x) if i is even, else add 4*f(x)
    }

    return (h / 3) * sum;
}

int main() {
    double a, b;
    int n;

    printf("Enter the lower limit of integration (a): ");
    scanf("%lf", &a);
    printf("Enter the upper limit of integration (b): ");
    scanf("%lf", &b);
    printf("Enter the number of subintervals (n, must be even): ");
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("Error: Number of subintervals must be even for Simpson's 1/3 rule.\n");
        return 1;
    }

    double integral = compositeSimpsons13(f, a, b, n);

    printf("The approximate value of the integral is: %.6f\n", integral);

    return 0;
}
