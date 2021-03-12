#include<stdio.h>

int main(void){
  int prime[1000001],i,j,n,sum,count;
  
  for(i=0;i<1000000;i++)
    prime[i]=0;  

  prime[0]=1;
  prime[1]=1;

  for(i=2;i*i<1000000;i++){
    if(prime[i]==0){
      for(j=2*i;j<1000000;j+=i){
	prime[j]=1;
      }
    }
  }
  while(1){
    sum=0;
    count=0;
    scanf("%d",&n);
    if(n==0)break;
    
    for(i=2;count<n;i++){
      if(prime[i]==0){
	sum+=i;
	count++;
      }
    }
    printf("%d\n",sum);
  }
  
  return 0;
}
