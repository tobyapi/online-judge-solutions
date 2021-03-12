#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int dp[2][1<<20],cow[21][21],p[21];

int main(void){

  int n,m;
  scanf("%d %d",&n,&m);

  for(int i=1;i<=n;i++){
    scanf("%d",&p[i]);
    for(int j=0;j<p[i];j++)scanf("%d",&cow[i][j]);
  }
  
  dp[0][0]=1;
  for(int i=1;i<=n;i++){
    for(int j=0;j<p[i];j++){
      for(int S=0;S<(1<<m);S++){
	if(S>>(cow[i][j]-1)&1)dp[i&1][S]+=dp[(i-1)&1][S&~(1<<(cow[i][j]-1))];
      }
    }
    for(int j=0;j<(1<<m);j++)dp[(i-1)&1][j]=0;
  }

  int ans=0;
  for(int i=0;i<(1<<m);i++)ans+=dp[n&1][i];
  cout << ans << endl;

  return 0;
}