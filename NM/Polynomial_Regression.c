#include <stdio.h>
#include <math.h>

int main(){
    int i, j, k, n, degree;
    float x[n], y[n], X[degree + 1][degree + 2], sum;
    printf("Polynomial Regression\n\n");
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    printf("Enter the data points:\n");
    for (i = 0; i < n; i++)
        scanf("%f %f", &x[i], &y[i]);

    for (i = 0; i <= degree; i++){
        for (j = 0; j <= degree; j++){
            sum = 0;
            for (k = 0; k < n; k++)
                sum += pow(x[k], i + j);
            X[i][j] = sum;
        }
        sum = 0;
        for (k = 0; k < n; k++)
            sum += y[k] * pow(x[k], i);
        X[i][degree + 1] = sum;
    }

    for (i = 0; i <= degree; i++){
        for (j = i + 1; j <= degree; j++){
            float a = X[j][i] / X[i][i];
            for (k = 0; k <= degree + 1; k++)
                X[j][k] -= a * X[i][k];
        }
    }

    for (i = degree; i >= 0; i--){
        sum = 0;
        for (j = i + 1; j <= degree; j++)
            sum += X[i][j] * X[j][degree + 1];
        X[i][degree + 1] = (X[i][degree + 1] - sum) / X[i][i];
    }
    
    printf("The coefficients are:\n");
    for (i = 0; i <= degree; i++)
        printf("a%d = %.2f\n", i, X[i][degree + 1]);
    return 0;
}
