#include<stdio.h>

int max(int,int);

int main(void){
  int dp[1001][1001],W,i,j,n,w[1001],v[1001],t=1,ansv,answ;

  while(scanf("%d",&W),W){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d,%d",&v[i],&w[i]);

    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
	dp[i][j]=0;

    for(i=0;i<=n;i++){
      for(j=0;j<=W;j++){
	if(j>=w[i])dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
	else dp[i+1][j]=dp[i][j];
      }
    }
    ansv=0;
    for(i=0;i<=W;i++){
	if(ansv<dp[n][i]){
	  ansv=dp[n][i];
	  answ=i;
	}
    }

    printf("Case %d:\n%d\n%d\n",t++,ansv,answ);
  }
  return 0;
}

int max(int x,int y){
  return x>y?x:y;
}
