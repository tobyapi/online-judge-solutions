#include<stdio.h>
int main(void){

  int a[4],b[4],i,j,Hit,Blow;

  while(1)
    {
      Hit=0;
      Blow=0;
      if(scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3])==EOF)break;
      scanf("%d %d %d %d",&b[0],&b[1],&b[2],&b[3]);

      for(i=0;i<4;i++)
	{
	  if(a[i]==b[i])Hit++;
	}
      
      for(i=0;i<4;i++)
	{
	  for(j=0;j<4;j++)      
	    {
	      if(a[i]==b[j])
		{
		  Blow++;
		}
	    }
	}
      printf("%d %d\n",Hit,Blow-Hit);
    }
  
  return 0;
}
