#include<stdio.h>

int main(void){
  int n,i,j,cnt;

  while(scanf("%d",&n),n){
    for(i=1,cnt=0;i<=n;i++){
      for(j=i+1;j<=n;j++){
	if((j*(j+1)-i*(i-1))/2==n)cnt++;
      }
    }
    printf("%d\n",cnt);
  }
  return 0;
}
