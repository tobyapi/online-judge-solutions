#include<stdio.h>

int judge(int,int);

int memo[1000001];

int main(void){
  int n,m,i,count;

  for(i=0;i<1000001;i++)
    memo[i]=-1;
  
  memo[0]=1;
  memo[1]=0;

  while(1){
    scanf("%d",&n);

    if(n==0)break;

      scanf("%d",&m);

    count=0;
    for(i=n;i<=m;i++){
      if(judge(i,1)==0){
	memo[i]=0;
	count++;
      }
    }

    printf("%d\n",count);
}

  return 0;
}

int judge(int x,int fg){

  if(x%2==0)judge(x/2,2);
  else if(x%3==0)judge(x/3,3);
  else if(x%5==0)judge(x/5,5);

  if(memo[x]==0){
    memo[x*fg]=0;
    return 0;
  }
  return memo[x]=1;
}
