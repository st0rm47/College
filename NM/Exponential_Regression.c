#include<stdio.h>
#include<math.h>
int main(){
    int n, i, j, k;
    float a = 0, b=0,r,x[10],y[10],xsum=0,ysum=0,xysum=0,x2sum=0;
    printf("Exponential Regression\n\n");
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the data points:\n");
    for (i=0; i<n; i++){
        scanf("%f %f", &x[i], &y[i]);
    }
    for (i=0; i<n; i++){
        xsum += x[i];
        ysum += log(y[i]);
        xysum += x[i]*log(y[i]);
        x2sum += x[i]*x[i];
    }
    b = (n*xysum - xsum*ysum)/(n*x2sum - xsum*xsum);
    a = (ysum - b*xsum)/n;
    printf("\nThe equation of the curve is: y = %.2fe^%.2fx\n", exp(a), b);
    return 0;
}