#include<stdio.h>

int main(void){
  double x,sum;
  int i;
  while(scanf("%lf",&x)!=EOF){
    sum=x;
    for(i=0;i<9;i++){
      if(i%2==0)x*=2;
      else if(i%2==1)x/=3;
      sum+=x;
    }
    printf("%.8f\n",sum);
  }
  return 0;
}
