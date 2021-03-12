#include<stdio.h>

int main(void){
  int a,b,c,d,n;

  while(scanf("%d %d",&a,&b),a|b){
    n=b-a,c=n%1000,d=n%500;
    printf("%d %d %d\n",d/100,c/500,n/1000);
  }
  return 0;
}
