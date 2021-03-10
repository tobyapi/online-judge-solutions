#include<stdio.h>
int main(void)
{
  long long d,i,j=1,x,y,integral,ans;
  
  
  while(scanf("%lld",&d)!=EOF)
    {
      integral=0;
      j=0;
      for(i=1;i<=600;i+=d)
	{
	  y=0;
	  x=0;
	  ans=0;
	  y=j*d*j*d;
	  x=d;
	  ans=x*y;
	  integral+=ans;
	  j++;	
	}
      printf("%lld\n",integral);
    }
  return 0;
}
