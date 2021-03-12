#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>G[5001],vs;
bool used[5001];
int cmp[5001];

void dfs(int v){
  used[v]=true;
  for(int i=0;i<G[v].size();i++){
    if(!used[G[v][i]])dfs(G[v][i]);
  }
  vs.push_back(v);
}

bool dfs2(int v,int g){
  if(v==g)return true;
  used[v]=true;
  bool fg=false;
  for(int i=0;i<G[v].size();i++){
    if(!used[G[v][i]])fg|=dfs2(G[v][i],g);
  }
  return fg;
}

int main(void){

  int n,m;

  cin >> n >> m;

  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    G[a].push_back(b);
  }
  bool fg=true;
  fill(used,used+5001,false);
  for(int i=1;i<=n;i++)if(!used[i])dfs(i);
  reverse(vs.begin(),vs.end());

  for(int i=0;i<n-1;i++){
    fill(used,used+5001,false);
    fg&=dfs2(vs[i],vs[i+1]);
  }

  for(int i=0;i<n;i++)cout << vs[i] << endl;
  cout << !fg << endl;
  return 0;
}
