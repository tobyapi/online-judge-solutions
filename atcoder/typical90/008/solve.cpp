#include<iostream>
#include<string>
#include<algorithm>

#define all(c) (c).begin(),(c).end()

using namespace std;

typedef long long ll;

const string atcoder = "atcoder";
const ll mod = 1000000007;

ll dp[100001][8];

int main(void){
  int N;
  string S;
  cin >> N >> S;

  dp[0][0]=1;
  for(int i=0;i<N;i++){
    for(int j=0;j<=atcoder.size();j++){
      if(j < atcoder.size() && S[i] == atcoder[j]){
        (dp[i+1][j+1] += dp[i][j] % mod) %= mod;
      }
      (dp[i+1][j] += dp[i][j] % mod) %= mod;
    }
  }
  cout << dp[N][atcoder.size()] << endl;
}