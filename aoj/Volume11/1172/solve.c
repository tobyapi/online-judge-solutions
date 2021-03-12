#include<stdio.h>

int prime[1234568];

int main(void){
  int n,i,j,count;

  prime[0]=1;
  prime[1]=0;
  for(i=2;i<1234568;i++)
    prime[i]=0;

  for(i=2;i*i<1234568;i++){
    if(prime[i]==0){
      for(j=i*2;j<1234568;j+=i)
	prime[j]=1;
    }
  }

  while(1){
    count=0;
    scanf("%d",&n);
    if(n==0)break;
    for(i=n+1;i<=2*n;i++)
      if(prime[i]==0)count++;

    if(n==1)count=1;
    printf("%d\n",count);
}
  return 0;
}
