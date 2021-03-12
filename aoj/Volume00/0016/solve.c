#include<stdio.h>
#include<math.h>

# define PI 3.141592653589793

int main(void){
  double x=0,y=0;
  double a,rad=0,deg=0;

  while(1){
    scanf("%lf,%lf",&a,&deg);

    if(a==0 && deg==0)break;

    x+=a*sin(rad);
    y+=a*cos(rad);

    rad+=deg*PI/180;

  }

  printf("%d\n%d\n",(int)x,(int)y);

  return 0;
}
