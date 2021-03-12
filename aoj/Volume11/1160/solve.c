#include<stdio.h>
int cell[51][51],w,h;
void visit(int i,int j)
{
  cell[i][j]=0;
  if(j+1<=w)
    {
      if(cell[i][j+1]==1)
	{
	  visit(i,j+1);
	}
    }
  if(j-1>=0)
    {
      if(cell[i][j-1]==1)
	{
	  visit(i,j-1);
	}
    }
  if(i-1>=0)
    {
      if(cell[i-1][j]==1)
	{
	  visit(i-1,j);
	}
    }
  if(i+1<=h)
    {
      if(cell[i+1][j]==1)
	{
	  visit(i+1,j);
	}
    }
  if(i-1>=0 && j-1>=0)
    {
      if(cell[i-1][j-1]==1)
	{
	  visit(i-1,j-1);	
	}
}
  if(i-1>=0 && j+1<=w)
    {
      if(cell[i-1][j+1]==1)
	{
	  visit(i-1,j+1);
	}
    }
  if(i+1<=h && j+1<=w)
    {
      if(cell[i+1][j+1]==1)
	{
	  visit(i+1,j+1);
	}
    }
  if(i+1<=h && j-1>=0)
    {
      if(cell[i+1][j-1]==1)
	{
	  visit(i+1,j-1);
	}
    }
}

int main(void)
{
  int i,j,count=0;
  while(1)
    {
      count=0;
      scanf("%d %d",&w,&h);
      
      if(w==0 && h==0)break;
      
      for(i=0;i<h;i++)
	{
	  for(j=0;j<w;j++)
	    {
	      scanf("%d",&cell[i][j]);
	    }
	}
      for(i=0;i<h;i++)
	{
	  for(j=0;j<w;j++)
	    {
		if(cell[i][j]==1)
		  {
		    count++;
		    visit(i,j);
		  }
	    }
	}
      printf("%d\n",count);
    }
  return 0;
}
