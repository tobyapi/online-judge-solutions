#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
 
#define INF (1<<29)
#define D(x) cout << #x " is " << (x) << endl
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
 
using namespace std;
 
int dp[16][(1<<16)];
 
int main(void){
 
  int n;
  string s,t;
 
  while(cin >> n,n){
    cin >> s >> t;
 
    fill(dp[0],dp[n],INF);
    int tmp=0;
    for(int i=0;i<n;i++){
      if(s[i]==t[i])tmp|=(1<<i);
    }
    for(int i=0;i<n;i++)dp[i][tmp]=0;
     
    int ans=INF;
    for(int r=0;r<4;r++){
      for(int i=0;i<n;i++){
    if(!(tmp>>i&1)){
      for(int k=0;k<n;k++){
        for(int j=0;j<n;j++){
          if(s[j]!=s[k]){
        for(int S=0;S<(1<<n);S++){
          if(!(S>>j&1) && !(S>>k&1)){
            int next=S;
            next|=(1<<j)|(1<<k);
            if(dp[k][next]>dp[i][S]+abs(j-i)+abs(k-j))
              dp[k][next]=dp[i][S]+abs(j-i)+abs(k-j);
          }
        }
          }
        }
      }
    }
    ans=min(ans,dp[i][(1<<n)-1]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
