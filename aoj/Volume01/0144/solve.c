#include<stdio.h>
#define N 100000

int main(void)
{
  int n,p,r,k,t,a,count[101];
  int queue[1000000],head=0,tail=0;
  int router[101][101],visited[101],i,j,b;
  
  struct mail{
    int s;
    int d;
    int v;
  }packet[N];
  
  for(i=0;i<101;i++)
    {
      for(j=0;j<101;j++)
	{
	  router[i][j]=0;
	}
    }
  
  scanf("%d",&n);
  
  for(i=1;i<=n;i++)
    {
      scanf("%d%d",&r,&k);
      
      for(j=1;j<=k;j++)
	{
	  scanf("%d",&t);
	  router[r][t]=1;
	}
    }
  
  for(i=1;i<=n;i++)
    {
      router[i][i]=0;
    }

  scanf("%d",&p);
  
  for(i=1;i<=p;i++)
    {
      scanf("%d%d%d",&packet[i].s,&packet[i].d,&packet[i].v);
    }
  
  for(i=1;i<=p;i++)
    {
      for(b=0;b<101;b++)
	count[b]=0;

      count[packet[i].s]=1;
      queue[tail++]=packet[i].s;
      
      for(b=0;b<=n;b++)
	visited[b]=0;
	    

      visited[packet[i].s]=1;

      while(head!=tail)
	{
	  
	  a=queue[head++];

	  for(j=1;j<=n;j++)
	    {
	      if(router[a][j]==1 && visited[j]==0)
		{
		  queue[tail++]=j;
		  visited[j]=1;
		  count[j]=count[a]+1;	
		} 	      
	    }
	}
        if(count[packet[i].d]<=packet[i].v && count[packet[i].d]!=0)printf("%d\n",count[packet[i].d]);
	else printf("NA\n");
		  
    }
  return 0;
}
