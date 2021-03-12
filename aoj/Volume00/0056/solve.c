#include<stdio.h>

int main(void){
  long long i,j;
  int n,prime[50001];

  prime[0]=1;
  prime[1]=1;

  for(i=2;i<50001;i++)
    prime[i]=0;

  for(i=2;i*i<50001;i++){
    if(prime[i]==0){
      for(j=i*i;j<50001;j+=i)
	prime[j]=1;
    }
  }

  while(1){
    int count=0;
    scanf("%d",&n);
    if(n==0)break;    

    for(i=0;i<n/2+1;i++)
      if(prime[i]==0 && prime[n-i]==0)count++;
    
    printf("%d\n",count);
  }
  return 0;
}
