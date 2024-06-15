#include <stdio.h>
#include <stdlib.h>

// Function to evaluate a polynomial using Horner's method
int horner(int coeff[], int degree, int x) {
    int result = coeff[0]; // Initialize result with the coefficient of highest degree term
    
    for (int i = 1; i <= degree; i++) {
        result = result * x + coeff[i];
    }
    
    return result;
}

int main() {
    int degree;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    
    // Dynamically allocate memory for coefficients
    int *coeff = (int *)malloc((degree + 1) * sizeof(int));
    if (coeff == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter the coefficients of the polynomial:\n");
    for (int i = 0; i <= degree; i++) {
        printf("Coefficient of x^%d: ", degree - i);
        scanf("%d", &coeff[i]);
    }
    
    int x;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    
    int result = horner(coeff, degree, x);
    
    printf("The result of the polynomial at x = %d is: %d\n", x, result);
    
    // Free dynamically allocated memory
    free(coeff);
    
    return 0;
}
