#include<stdio.h>

int s,memo[31];

int func(int);

int main(void)
{

  int n,S,i;

  for(i=0;i<31;i++)
    memo[i]=-1;

  while(1)
    {
      scanf("%d",&n);
      if(n==0)break;
      s=0;
      s=func(n);
      S=s/3650+1;
      printf("%d\n",S);
}

  return 0;
}

int func(int n)
{

  if(n==0 || n==1)return 1;
  if(n==2)return 2;
  if(n==3)return 4;
  if(n<0)return 0;
  if(memo[n]==-1)
    {
      int result=0;
      result+=func(n-3);
      result+=func(n-2);
      result+=func(n-1);
      memo[n]=result;
    }
  
  return memo[n];
}
