#include<stdio.h>

int main(void)
{
  int n,i,time[101],a,b,j;

  while(scanf("%d",&n)!=EOF)
    {
      a=0;
      for(i=0;i<n;i++)
	{
	  scanf("%d",&time[i]);
	}

      for(i=0;i<n;i++)
	{
	  for(j=i+1;j<n;j++)
	    {
	      if(time[i]>time[j])
		{
		  b=time[i];
		  time[i]=time[j];
		  time[j]=b;
		}
	    }
	}
      for(i=1;i<n;i++)
	{
	  time[i]=time[i]+time[i-1]; 
	}
      for(i=0;i<n;i++)
	{
	  a+=time[i];
	}
      printf("%d\n",a);
    }
  return 0;
}
