#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){

  int n,W;
  cin >> n >> W;

  vector<int>v(n),w(n);
  for(int i=0;i<n;i++)cin >> v[i] >> w[i];

  int dp[W+1];
  fill(dp,dp+W+1,0);

  for(int i=0;i<n;i++)
    for(int j=W;j>=0;j--)
      if(w[i]+j<=W)dp[w[i]+j]=max(dp[w[i]+j],dp[j]+v[i]);

  cout << dp[W] << endl;

  return 0;
}
