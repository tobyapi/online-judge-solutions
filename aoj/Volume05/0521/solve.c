#include<stdio.h>

int main(void){
  int n,i,count,coin[6]={500,100,50,10,5,1};

  while(scanf("%d",&n),n){
    for(i=0,count=0,n=1000-n;i<6;i++)
      while(n-coin[i]>=0){
	n-=coin[i];
	count++;
      }
    printf("%d\n",count);
  }
  return 0;
}
