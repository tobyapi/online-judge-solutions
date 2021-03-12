#include<iostream>
#include<vector>
#include<algorithm>

#define MAX_V 1001

using namespace std;

int V,match[MAX_V];
vector<int>g[MAX_V];
bool used[MAX_V];

void add_edge(int u,int v){
  g[u].push_back(v);
  g[v].push_back(u);
}

bool dfs(int v){
  used[v]=true;
  for(int i=0;i<g[v].size();i++){
    int u=g[v][i],w=match[u];
    if(w<0 || !used[w] && dfs(w)){
      match[v]=u;
      match[u]=v;
      return true;
    }
  }
  return false;
}

int bipartite_matching(){
  int res=0;
  fill(match,match+MAX_V,-1);
  for(int v=0;v<V;v++){
    if(match[v]<0){
      fill(used,used+MAX_V,false);
      if(dfs(v))res++;
    }
  }
  return res;
}

int main(void){

  int n,m;

  cin >> n >> m;

  int u,v;
  for(int i=0;i<m;i++){
    cin >> u >> v;
    add_edge(u-1,v+n-1);
  }

  V=2*n;

  cout << bipartite_matching() << endl;

  return 0;
}