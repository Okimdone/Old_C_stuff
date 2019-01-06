#include<stdio.h>
#include<math.h>

int main(){
    double a=1,b=3000.001,c=3;
    printf("%lf %lf %lf \n",a,b,c);

    double delta= b*b - 4*a*c;

    double r1=(-b + sqrt(delta))/2*a;
    double r2=(-b - sqrt(delta))/2*a;

    printf("R1 = %lf\nR2 = %lf\n",r1,r2);

}