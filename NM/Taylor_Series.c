#include <stdio.h>
#include <math.h>
int fact(int n) {
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}
float first_derivative(float x, float y) {
    return x * x + y * y;   // dy/dx = x^2 + y^2
}
float second_derivative(float x, float y) {
    return 2 * x + 2 * y * first_derivative(x, y);
}
float third_derivative(float x, float y) {
    return 2 + 2 * y * second_derivative(x, y) + 2 * first_derivative(x, y) * first_derivative(x, y);
}
int main() {
    float x, x0, y0, yx;
    printf("Taylor's Series Method\n\n");
    printf("Enter the value of x and y:");
    scanf("%f%f%f", &x0, &y0);
    printf("Enter the value of x at which function to be evaluated:");
    scanf("%f", &x);
    yx = y0;
    yx += first_derivative(x0, y0) * (x - x0) / fact(1);
    yx += second_derivative(x0, y0) * pow(x - x0, 2) / fact(2);
    yx += third_derivative(x0, y0) * pow(x - x0, 3) / fact(3);
    printf("\nThe value of y at x = %.2f is approximately %.4f\n", x, yx);
    return 0;
}

