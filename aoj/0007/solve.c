#include<stdio.h>
int main(void)
{
  int n,i,a=100000;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      a=a*5/100+a;
      
      if(a%1000!=0)
	{
	  a=a/1000;
	  a=a*1000+1000;
	}
      
    }
  
  printf("%d\n",a);
  
  return 0;
}
