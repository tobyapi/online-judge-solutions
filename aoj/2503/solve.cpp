#include<iostream>
#include<algorithm>
#include<vector>

#define INF 100000000

using namespace std;

int graph[400][400],n,dp[400];
bool visit[400];
vector<int>L;

void Tsort(int v){
  visit[v]=true;
  for(int i=0;i<n;i++)
    if(graph[v][i]>0 && !visit[i])Tsort(i);
  L.push_back(v);
}

int main(void){

  int m,a,b,c;

  cin >> n >> m;

  for(int i=0;i<m;i++){
    cin >> a >> b >> c;
    graph[a][b]=c;
  }
  
  Tsort(0);
  reverse(L.begin(),L.end());

  for(int i=1;i<L.size();i++)
    for(int j=0;j<L.size();j++)
      if(graph[L[j]][L[i]]>0)
	dp[L[i]]=max(dp[L[i]],dp[L[j]]+graph[L[j]][L[i]]);
  
  cout << dp[n-1] << endl;
  
  return 0;
}
