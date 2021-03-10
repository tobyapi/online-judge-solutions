#include<stdio.h>

#define Num 1000000

int main(void)
{
  int a[Num+1];
  int n,i,j,count=0;
  
  for(i=0;i<Num;i++)
    {
      a[i]=1;
    }

  //printf("1\n");
  /*for(i=2;i<=n/2;i++)*/
  for(i=2;i*i<=Num;i++)
    {	  
      //printf("2\n");
      for(j=2*i;j<=Num;j+=i)
	{
	  //printf("3\n");
	  if(j%i==0)a[j]=0;
	}
    }
  
  
  
  while(scanf("%d",&n)!=EOF)
    {
    

      for(i=2;i<=n;i++)
	{
	  //printf("4\n");
	  if(a[i]==1)
	    {count++;
	      //printf("5\n");
	      
	    }
	}
      printf("%d\n",count);
      count=0;
    }
  //printf("end\n");
  return 0;
}
