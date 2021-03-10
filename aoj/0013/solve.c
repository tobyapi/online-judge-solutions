#include<stdio.h>

int S[11],top;

int isempty(int x)
{
  return (top==0);
}

void push(int x)
{
  S[++top]=x;
}

int pop(void)
{
  int x;
  x=S[top--];
  printf("%d\n",x);
  return x;
}

int main(void)
{
  int x;

  while(scanf("%d",&x)!=EOF)
    {
      if(x==0)pop();
      else push(x);
    }
  return 0;
}
