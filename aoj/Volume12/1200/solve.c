#include<stdio.h>
#define N 100000

int main(void){
  int prime[N],i,j,n;

  for(i=2;i<N;i++)
    prime[i]=0;

  prime[0]=1;
  prime[1]=1;

  for(i=2;i*i<=N;i++){
    if(prime[i]==0){
      for(j=2*i;j<N;j+=i){
	prime[j]=1;
      }
    }
  }

  while(scanf("%d",&n),n){
    int count=0;
    for(i=2;i<=n/2;i++){
      if(prime[i]==0 && prime[n-i]==0)count++;
    }
    printf("%d\n",count);
  }
  return 0;
}
