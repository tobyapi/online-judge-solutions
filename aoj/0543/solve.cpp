#include<stdio.h>

int main(void){
  int sum,sum9,i,a;

  while(scanf("%d",&sum),sum){
    for(i=sum9=0;i<9;i++){
      scanf("%d",&a);
      sum9+=a;
    }
    printf("%d\n",sum-sum9);
  }

  return 0;
}
