#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

typedef long long ll;

ll dp[202][202];
ll MOD=1000000007;

int main(void){

  int n;
  cin >> n;

  char c[202];

  for(int i=0;i<n;i++)cin >> c[i];

  dp[0][0]=1;

  for(int k=0;k<n;k++){
    for(int i=0;i<=k;i++){
      if(c[k]=='-')dp[k+1][i]=dp[k][i];
      else if(c[k]=='D'){
        if(i>0){
          dp[k+1][i-1]+=dp[k][i]*i*i;
          dp[k+1][i-1]%=MOD;
        }
        dp[k+1][i]+=dp[k][i]*i;
      }
      else if(c[k]=='U'){
        dp[k+1][i]+=dp[k][i]*i;
        dp[k+1][i+1]+=dp[k][i];
        dp[k+1][i+1]%=MOD;
      }
      dp[k+1][i]%=MOD;
    }
  }
  cout << dp[n][0] << endl;

  return 0;
}
