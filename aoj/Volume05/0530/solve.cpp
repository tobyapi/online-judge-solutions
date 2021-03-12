#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>

#define f first
#define s second
#define MAX_N 155
#define INF 1000000000

using namespace std;

typedef pair<int,int> P;

int main(void){

  int n,m,k,a,b;

  while(cin >> n >> m,n|m){
    vector<P>v[MAX_N];
    
    for(int i=1;i<=n;i++){
      cin >> k;
      for(int j=0;j<k;j++){
	cin >> a >> b;
	v[i].push_back(make_pair(a,b));
      }
    }

    int dp[MAX_N][11][80];

    for(int i=0;i<MAX_N;i++)
      for(int j=0;j<11;j++)
	for(int k=0;k<80;k++)
	  dp[i][j][k]=INF;

    for(int i=0;i<11;i++)
      for(int j=0;j<80;j++)
	dp[0][i][j]=dp[1][i][j]=0;

    for(int i=2;i<=n;i++){
      for(int j=0;j<v[i].size();j++){
	for(int l=m;l>=0;l--){
	  for(int k=0;k<v[i-1].size();k++){
	    dp[i][j][l]=min(dp[i][j][l],dp[i-1][k][l]+(v[i][j].s+v[i-1][k].s)*abs(v[i][j].f-v[i-1][k].f));
	  }
	  if(l<m){
	    if(i==2)dp[i][j][l]=0;
	    for(int p=0;p<v[i-2].size();p++)
	      dp[i][j][l]=min(dp[i][j][l],dp[i-2][p][l+1]+(v[i][j].s+v[i-2][p].s)*abs(v[i][j].f-v[i-2][p].f));
	  }
	}
      }
    }
    
    int ans=INF;
    for(int i=0;i<v[n].size();i++)ans=min(ans,dp[n][i][0]);
    if(m>=1)for(int i=0;i<v[n-1].size();i++)ans=min(ans,dp[n-1][i][1]);

    cout << ans << endl;
  }

  return 0;
}
