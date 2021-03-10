#include <iostream>
  
using namespace std;
 
long long n,s,dp[11][1001];
int main(void){
   
  dp[0][0] = 1;
   
  for(int i=0;i<101;i++)
    for(int j=9;j>=0;j--)
      for(int k=0;i+k<1001;k++)
        dp[j+1][k+i]+=dp[j][k];

  while(cin >> n >> s, n|s)
    cout << dp[n][s] << endl;

  return 0;
}
