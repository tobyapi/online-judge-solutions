#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

#define curr(P, i) P[(i) % P.size()]
#define next(P, i) P[(i+1) % P.size()]
#define prev(P, i) P[(i+P.size()-1) % P.size()]
#define Next(a,i) ((i)+1)%(a).size()
#define Curr(a,i) (i)%(a).size()
#define Prev(a, i) (i+a.size()-1) % a.size()

using namespace std;

int main(void){

  int n,m,x,dp[101][101];
  vector<int>a;

  cin >> n;

  while(n--){
    a.clear();

    for(int i=0;i<101;i++)
      for(int j=0;j<101;j++)dp[i][j]=0;

    cin >> m;
    for(int i=0;i<m;i++){
      cin >> x;
      a.push_back(x);
    }
    
    for(int i=0;i<m;i++){
      for(int j=0;j<m;j++){
	for(int k=0;k<i;k++){
	  dp[Curr(a,j)][Curr(a,i)]=max(dp[j][i],dp[Curr(a,j)][Curr(a,k)]+dp[Next(a,j+k)][Prev(a,i-k)]+abs(curr(a,j)-next(a,j+k))); 
	}
      }
    }
    int ans=0;
    for(int i=0;i<m;i++)
      for(int j=0;j<m;j++)
      ans=max(ans,dp[i][j]);
    
    cout << ans << endl;
    
  }

  return 0;
}
