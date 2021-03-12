#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){

  int N,K,S;
  while(cin >> N >> K >> S,N|K|S){

  int dp[11][21][200];
  fill(*dp[0],*dp[11],0);
  dp[0][0][0]=1;

  for(int l=0;l<K;l++){
    for(int i=0;i<N;i++){
      for(int j=0;j<200;j++){
	for(int k=i+1;k<=N;k++){
	  if(j+k<200) dp[l+1][k][j+k]+=dp[l][i][j];
	}
      }
    }
  }

  int ans=0;
  for(int i=0;i<=N;i++)ans+=dp[K][i][S];

  cout << ans << endl;
  }
  return 0;
}
