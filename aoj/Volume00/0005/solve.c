#include<stdio.h>
int main(void)
{
long long a,b,m,n,k,gcd,lcm;
  
  while(scanf("%lld %lld",&a,&b)!=EOF)
    {
      k=1;
      m=a;
      n=b;
      while(k!=0)
	{
	  k=m%n;
	  m=n;
	  n=k;
	}
      gcd=m;
      
      lcm=a*b/gcd;
      
      printf("%lld %lld\n",gcd,lcm);
      
    }
  return 0;
}
