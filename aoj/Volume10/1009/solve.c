#include<stdio.h>
int main(void)
{
  int m,n,l,t;
  
  while(scanf("%d %d",&m,&n)!=EOF)
    {
      l=1;
      if(m<n)
	{
	  t=m;
	  m=n;
	  n=t;
}
      while(l!=0)
	{
	  l=m%n;
	  m=n;
	  n=l;
	}
      printf("%d\n",m);
    }
  return 0;
}
