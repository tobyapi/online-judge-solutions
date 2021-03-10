#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){

  int d,n,t,a,b,c,dp[202][202];
  vector<int>T,A,B,C;

  cin >> d >> n;
  
  for(int i=0;i<d;i++){
    cin >> t;
    T.push_back(t);
  }
  
  for(int i=0;i<n;i++){
    cin >> a >> b >> c;
    A.push_back(a);
    B.push_back(b);
    C.push_back(c);
  }
  
  for(int i=0;i<202;i++)
    for(int j=0;j<202;j++)
      dp[i][j]=-1;
  
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(A[i]<=T[0] && T[0]<=B[i] && A[j]<=T[1] && T[1]<=B[j])
	dp[0][j]=max(dp[0][j],abs(C[i]-C[j]));
  
  for(int i=1;i<=d;i++)
    for(int j=0;j<n;j++)
      for(int k=0;k<n;k++)
	if(A[k]<=T[i+1] && T[i+1]<=B[k] && dp[i-1][j]>=0)
	  dp[i][k]=max(dp[i][k],dp[i-1][j]+abs(C[j]-C[k]));
  
  int ans=0;
  for(int i=0;i<n;i++)
    ans=max(ans,dp[d-2][i]);
  
  cout << ans << endl;
  
  return 0;
}
