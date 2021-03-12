#include<stdio.h>

int main(void){
  int i,j,prime[10001],n;

  for(i=0;i<10001;i++)prime[i]=0;

  prime[0]=prime[1]=1;
  
  for(i=2;i*i<10001;i++){
    if(prime[i]==0){
      for(j=2*i;j<10001;j+=i){
	prime[j]=1;
      }
    }
  }
  
  while(scanf("%d",&n),n){
    for(i=n;i>1;i--){
      if(prime[i]==0 && prime[i-2]==0){
	printf("%d %d\n",i-2,i);
	break;
      }
    }
  }
  return 0;
}
