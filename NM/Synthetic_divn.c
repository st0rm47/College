#include <stdio.h>
#include <stdlib.h>

// Function to perform synthetic division
void syntheticDivision(int coeff[], int degree, int divisor) {
    int *result = (int *)malloc((degree + 1) * sizeof(int));
    if (result == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    result[0] = coeff[0]; // The leading coefficient remains the same
    
    for (int i = 1; i <= degree; i++) {
        result[i] = coeff[i] + divisor * result[i - 1];
    }
    
    // Print the quotient
    printf("Quotient: ");
    for (int i = 0; i < degree; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    // Print the remainder
    printf("Remainder: %d\n", result[degree]);
    
    // Free the allocated memory
    free(result);
}

int main() {
    int degree;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    
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
    
    int divisor;
    printf("Enter the value of the divisor (x - c) where c is: ");
    scanf("%d", &divisor);
    
    syntheticDivision(coeff, degree, divisor);
    
    // Free the allocated memory
    free(coeff);
    
    return 0;
}
