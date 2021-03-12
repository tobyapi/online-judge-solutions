#include<iostream>

using namespace std;

int main(void){
  int coin[18],dp[301]={0},n;

  for(int i=0;i<18;i++)coin[i]=i*i;

  dp[0]=1;

    for(int i=1;i<18;i++)
      for(int j=1;j<301;j++)
	if(j>=coin[i])dp[j]+=dp[j-coin[i]];

  while(cin >> n,n){
    cout << dp[n] << endl;
  }
  return 0;
}
