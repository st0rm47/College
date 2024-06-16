#include<stdio.h>
#include<math.h>
#define f(x) 1/(1+x)
int main(){
    float x0,xn,h,sum,v;
    int i,k;
    printf("Composite Simpson's 1/3 Rule\n\n");
    printf("Enter the lower limit and upper limit: ");
    scanf("%f%f",&x0,&xn);
    printf("Enter the number of segments: ");
    scanf("%d",&k);
    h = (xn - x0) / k;
    sum = f(x0) + f(xn);
    for(i = 1; i < k; i++){
        if(i % 2 == 0){
            sum += 2 * f(x0 + i * h);
        }
        else{
            sum += 4 * f(x0 + i * h);
        }
    }
    v = (h / 3) * sum;
    printf("\nThe value obtained after integration is %.2f",v);
    return 0;
}