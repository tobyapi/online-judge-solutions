#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<cctype>
#include<cassert>
#include<cmath>
#include<climits>

#define INF (1<<29)
#define all(c) (c).begin(),(c).end()
#define D(x) cout << #x " is " << (x) << endl
#define rep(i,n) for(int i = 0; i < n; i++)
#define x first
#define y second

using namespace std;

typedef pair<int,int>pii;
typedef long long ll;

ll dp[1002][1002],K[1002][1002];

int main(void){

  int n;
  cin >> n;

  vector<pii>v(n);
  rep(i,n)cin >> v[i].x >> v[i].y;


  fill(dp[0],dp[1001],INT_MAX);
  fill(K[0],K[1001],-1);
  rep(i,1001)dp[i][i]=0,K[i][i]=i;

  for(int w=1;w<n;w++){
    for(int i=0;i+w<=n;i++){
      for(int s=K[i][i+w-1];s<=K[i+1][i+w];s++){
        int cost=abs(v[i].x-v[s+1].x)+abs(v[s].y-v[i+w].y);
        if(dp[i][i+w]>dp[i][s]+dp[s+1][i+w]+cost){
          dp[i][i+w]=dp[i][s]+dp[s+1][i+w]+cost;
          K[i][i+w]=s;
        }
      }
    }
  }

  cout << dp[0][n-1] << endl;

  return 0;
}
