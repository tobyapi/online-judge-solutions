#include<stdio.h>

int main(void){
  int a,b,n,sum;
  double x;

  while(~scanf("%d %d %d",&a,&b,&n)){

    a=a%b;
    for(sum=0;n;n--){
      sum+=(a*10)/b;
      a=(a*10)%b;
    }
    printf("%d\n",sum);
  }

  return 0;
}
