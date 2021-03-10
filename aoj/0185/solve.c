#include<stdio.h>

int main(void){
  int prime[1000001],i,j,n;

  for(i=0;i<1000001;i++)
    prime[i]=0;
  
  prime[0]=prime[1]=1;

  for(i=2;i*i<1000001;i++){
    if(prime[i]==0){
      for(j=2*i;j<1000001;j+=i){
	prime[j]=1;
      }
    }
  }
  
  while(scanf("%d",&n),n){
    int count=0;
    for(i=2;i<=n/2;i++)
      if(prime[i]==0 && prime[n-i]==0)count++;

    printf("%d\n",count);
}

  return 0;
}
