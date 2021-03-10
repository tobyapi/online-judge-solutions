#include<iostream>
#include<cstdio>

using namespace std;

int main(void){
  int W,n,v[1000],w[1000],dp[1001][1001],t=1;

  while(cin >> W,W){
    cin >> n;

    for(int i=0;i<n;i++)
    scanf("%d,%d",&v[i],&w[i]);

    for(int i=0;i<1000;i++)
      for(int j=0;j<1000;j++)
	dp[i][j]=0;
    
    for(int i=0;i<n;i++)
      for(int j=0;j<=W;j++)
	if(j<w[i])dp[i+1][j]=dp[i][j];
	else dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);

    cout << "Case " << t << ":" << endl;
    
    for(int i=W;i>=0;i--){
      if(dp[n][i] != dp[n][W]){
	cout << dp[n][W] << endl << i+1 << endl;
	break;
      }
    }
      t++;
  }

  return 0;
}
