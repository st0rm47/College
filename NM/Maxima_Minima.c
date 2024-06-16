#include<stdio.h>
#include<math.h>
int main(){
    int n, i, j, k;
    float a = 0, b=0,r,x[10],y[10],xsum=0,ysum=0,xysum=0,x2sum=0;
    printf("Maxima and Minima\n\n");
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the data points:\n");
    for (i=0; i<n; i++){
        scanf("%f %f", &x[i], &y[i]);
    }
    for (i=0; i<n; i++){
        xsum += x[i];
        ysum += y[i];
        xysum += x[i]*y[i];
        x2sum += x[i]*x[i];
    }
    b = (n*xysum - xsum*ysum)/(n*x2sum - xsum*xsum);
    a = (ysum - b*xsum)/n;
    r = (n*xysum - xsum*ysum)/sqrt((n*x2sum - xsum*xsum)*(n*ysum - ysum*ysum));
    printf("Maxima and Minima\n\n");
    printf("Maxima exists at x = %.2f\n", -b/(2*a));
    printf("Maxima value is %.2f\n", a - b*b/(4*a));
    printf("Minima exists at x = %.2f\n", -b/(2*a));
    printf("Minima value is %.2f\n", a - b*b/(4*a));
    return 0;
}