#include<iostream>
#include<vector>
#include<algorithm>

#define v first
#define w second

using namespace std;

typedef pair<int,int>pii;

int main(void){

  int n,m;
  cin >> n >> m;
  vector<pii>a(n);

  for(int i=0;i<n;i++)cin >> a[i].v >> a[i].w;

  int dp[10001];
  fill(dp,dp+10001,0);

  for(int i=0;i<n;i++){
    for(int j=0;j+a[i].w<10001;j++){
      dp[j+a[i].w]=max(dp[j+a[i].w],dp[j]+a[i].v);
    }
  }

  cout << dp[m] << endl;

  return 0;
}
