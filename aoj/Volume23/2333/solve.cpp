#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>

#define MOD 1000000007

using namespace std;

typedef long long ll;

ll dp[201][10001];

int main(void){

  int n,m;
  cin >> n >> m;

  vector<int>a(n);
  for(int i=0;i<n;i++)cin >> a[i];

  sort(a.begin(),a.end(),greater<int>());

  fill(dp[0],dp[201],0);
  dp[0][0]=1;

  for(int i=0;i<n;i++){
    memcpy(dp[i + 1], dp[i], sizeof(dp[i]));
    for(int j=m-a[i];j>=0;j--){
      dp[i+1][j+a[i]]+=dp[i][j];
    }
  }

  reverse(a.begin(),a.end());

  ll ans=0,sum=0;
  for(int i=0;i<n;i++){
    for(int j=max(0LL,m-sum-a[i]+1);j<=m-sum-(i?a[i-1]:0);j++){
      ans+=dp[n-i][j];
      ans%=MOD;
    }
    sum+=a[i];
  }
  cout << ans << endl;

  return 0;
}
