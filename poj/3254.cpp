#include<iostream>
#include<algorithm>

#define mod 100000000

using namespace std;

int dp[145][1<<12];

int main(void){

  int n,m,g[12][12],in;

  cin >> n >> m;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)cin >> g[i][j];

  dp[0][0]=1;

  for(int i=0;i<n*m;i++){
    int x=i%m,y=i/m;
    for(int S=0;S<(1<<m);S++){
      int nx=(S<<1)&~(1<<m);
      dp[i+1][nx]+=dp[i][S];
      dp[i+1][nx]%=mod;

      if(g[y][x] && !((S&1)*x) && !((S>>(m-1))&1)){
        dp[i+1][nx|1]+=dp[i][S];
        dp[i+1][nx|1]%=mod;
      }
    }
  }

  int ans=0;
  for(int i=0;i<(1<<m);i++)ans+=dp[n*m][i];

  cout << ans%mod << endl;

  return 0;
}