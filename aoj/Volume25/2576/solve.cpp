#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define all(c) (c).begin(),(c).end()

using namespace std;

typedef pair<int,int> pii;

int main(void){

  int D;
  cin >> D;

  vector<pii>v;

  int n;
  cin >> n;

  string a;
  int p;

  for(int i=0;i<n;i++){
    cin >> a >> p;
    if(a=="D")v.push_back(pii(1,p));
  }


  cin >> n;

  for(int i=0;i<n;i++){
    cin >> a >> p;
    if(a=="DD")v.push_back(pii(2,p));
  }

  int dp[15];
  fill(dp,dp+15,0);


  for(int j=0;j<(int)v.size();j++){
      for(int i=D;i>=0;i--){
      dp[i+v[j].first]=max(dp[i+v[j].first],dp[i]+v[j].second);
    }
  }

  int ans=0;
  for(int i=0;i<=D;i++)ans=max(ans,dp[i]);

  cout << ans << endl;

  return 0;
}
