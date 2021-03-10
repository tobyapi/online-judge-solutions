#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(void){
  int in=0,l=0;
  string s;
  vector<int>v[101];

  while(getline(cin,s)){
    for(int i=0;i<=s.size();i++){
      if(s[i]==',' || i==s.size())v[l].push_back(in),in=0;
      else if(s[i]!=',')in*=10,in+=s[i]-'0'; 
    }
    l++;
  }

  int dp[101][101];

  fill(dp[0],dp[101],0);
   dp[0][0]=v[0][0];

  for(int i=1;i<l;i++){
    for(int j=0;j<v[i].size();j++){
      dp[i][j]=dp[i-1][j]+v[i][j];
      if(i<=l/2 && j)dp[i][j]=max(dp[i][j],dp[i-1][j-1]+v[i][j]);
      if(i>l/2)dp[i][j]=max(dp[i][j],dp[i-1][j+1]+v[i][j]);
    }
  }
  cout << dp[l-1][0] << endl;

  return 0;
}
