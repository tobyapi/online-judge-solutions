#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>

using namespace std;

string max(string a, string b){
    if(a.size()>b.size()) return a;
    if(a.size()<b.size()) return b;
    for(int i=0;i<a.size();i++){
        if(a[i] > b[i]) return a;
        if(a[i] < b[i]) return b;
    }
    return a;
}

int main(void){
  int w,h;
  string grid[71],dp[71][71];

  while(cin >> w >> h,w|h){
    for(int i=0;i<71;i++)
      for(int j=0;j<71;j++)dp[i][j].clear();

    for(int i=0;i<h;i++)cin >> grid[i];

    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	if(!isupper(grid[i][j])){
	  dp[i][j]=grid[i][j];
	  string a="",b="";
	  if(i>0)a=dp[i-1][j]+grid[i][j];
	  if(j>0)b=dp[i][j-1]+grid[i][j];
	  
	  while(a[0]=='0')a.erase(a.begin());
	  while(b[0]=='0')b.erase(b.begin());

	  dp[i][j]=max(dp[i][j],max(a,b));
	}
      }
    }

    string s="";
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	s=max(s,dp[i][j]);
      }
    }
    cout << s << endl;
  }
  return 0;
}
