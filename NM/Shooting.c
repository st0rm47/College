#include <stdio.h>
#include <math.h>

// Define the differential equation y''(x) = f(x, y, y')
double f(double x, double y, double y_prime) {
    return 2 * x * y_prime - 2 * y;
}

// Implement the shooting method
double shooting_method(double a, double b, double alpha, double beta, double h, double tol) {
    double y_left, y_right, y_mid, y_prime_guess, y_prime_left, y_prime_right;
    double error = 1.0;

    // Initial guess for y' at a
    y_prime_guess = 0.0;

    while (error > tol) {
        y_left = alpha;
        y_prime_left = y_prime_guess;
        y_right = alpha + h * y_prime_guess;

        // Apply the Runge-Kutta method to find y(b) and y'(b)
        for (double x = a + h; x < b; x += h) {
            y_mid = y_right + h * f(x, y_right, y_prime_guess);
            y_prime_right = y_prime_guess + h * (f(x, y_right, y_prime_guess) + f(x + h, y_mid, y_prime_guess)) / 2;
            y_right = y_mid;
            y_prime_guess = y_prime_right;
        }

        error = fabs(y_right - beta);

        // Adjust the guess for y' at a using the secant method
        y_prime_guess = y_prime_left + (y_prime_guess - y_prime_left) * (beta - y_right) / (y_right - y_left);
    }

    return y_prime_guess;
}

int main() {
    double a, b, alpha, beta, h, tol;

    printf("Enter the start of the interval (a): ");
    scanf("%lf", &a);

    printf("Enter the end of the interval (b): ");
    scanf("%lf", &b);

    printf("Enter the boundary condition at a (alpha): ");
    scanf("%lf", &alpha);

    printf("Enter the boundary condition at b (beta): ");
    scanf("%lf", &beta);

    printf("Enter the step size (h): ");
    scanf("%lf", &h);

    printf("Enter the tolerance for the shooting method: ");
    scanf("%lf", &tol);

    double y_prime = shooting_method(a, b, alpha, beta, h, tol);

    printf("The initial value of y' at a that satisfies the boundary condition at b is: %lf\n", y_prime);

    return 0;
}
