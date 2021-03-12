#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define INF 1<<29

using namespace std;

int main(void){

  int n,dp[45][4],a,b;
  vector<int>p,t;

  while(cin >> n,n){
    p.clear();
    t.clear();
    
    fill(dp[0],dp[42],INF);
    
    for(int i=0;i<n;i++){
      cin >> a >> b;
      p.push_back(a);
      t.push_back(b);
    }

    dp[0][0]=p[0];
    if(p[0]>t[0]){
      cout << "NG " << 1 <<endl;
      continue;
    }
    int cnt=1;
    for(int i=1;i<n;i++){
      for(int j=1;j<4;j++){
	if(dp[i-1][j-1]==INF)continue;
	cnt=i;
	if(j<3 && abs(p[i]-p[i-1])*(j+1)<=t[i]-t[i-1])
	  dp[i][j]=min(dp[i][j],dp[i-1][j-1]+abs(p[i]-p[i-1]));
	if(p[i]+(p[i-1]*(j+1))<=t[i]-t[i-1])
	  dp[i][0]=min(dp[i][0],dp[i-1][j-1]+p[i]+p[i-1]);
      }
    }
    
    int ans=INF;
    for(int i=0;i<4;i++){
      ans=min(ans,dp[n-1][i]);
    }
    if(ans==INF)cout << "NG " << cnt+1 <<endl;
    else cout << "OK " << ans+p[p.size()-1] << endl;
  }

  return 0;
}
