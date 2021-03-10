#include<iostream>
using namespace std;

int min(int a,int b)
{
  if(a<b)return a;
  else return b;
}

int main(void)
{
  char dp[1001][1001];
  int n,i,j,max,M[1001][1001];
  
  
  while(1)
    {
      max=0;
      cin >> n;
      
      if(n==0)break;
      
      for(i=0;i<n;i++)
	{
	  for(j=0;j<n;j++)
	    {
	      M[i][j]=1;
	    }
	} 

      for(i=0;i<n;i++)
	{
	  for(j=0;j<n;j++)
	    {
	      cin >> dp[i][j];
	      if(i==0)
		{
		  if(dp[i][j]!='*')M[i][j]=1;
		  else M[i][j]=-1;
		}
	      else
		{
		  if(dp[i][j]!='*')
		    {
		  if(j==0)M[i][j]=1;
		  else
		    {
		      if(M[i-1][j]==-1 || M[i-1][j-1]==-1 || M[i][j-1]==-1)M[i][j]=1;
		      else M[i][j]=min(M[i-1][j],min(M[i-1][j-1],M[i][j-1]))+1;
			     }
		    }
		}
	      if(dp[i][j]=='*')M[i][j]=-1;
	      //cout << M[i][j];
	    }
	  //cout <<"\n";
	}

      for(i=0;i<n;i++)
	{
	  for(j=0;j<n;j++)
	    {
	      if(M[i][j]>=0 && max<M[i][j])max=M[i][j];
	    }
	}
      cout << max <<"\n";
    }
  return 0;
}
