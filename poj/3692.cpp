#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int V,match[401];
bool used[401];
vector<int>G[401];

void add_edge(int u,int v){
  G[u].push_back(v);
  G[v].push_back(u);
}

bool dfs(int v){
  used[v]=true;
  for(int i=0;i<G[v].size();i++){
    int u=G[v][i],w=match[u];
    if(w<0 || !used[w] && dfs(w)){
      match[v]=u;
      match[u]=v;
      return true;
    }
  }
  return false;
}

int bitpartite_matching(){
  int res=0;
  fill(match,match+401,-1);
  for(int v=0;v<V;v++){
    if(match[v]<0){
      fill(used,used+401,false);
      if(dfs(v))res++;
    }
  }
  return res;
}

int main(void){
  
  int g,b,m,t=1,graph[201][201];
  while(cin >> g >> b >> m,g|b|m){
    fill(graph[0],graph[201],0);
    for(int i=0;i<401;i++)G[i].clear();
    for(int i=0;i<m;i++){
      int l,r;
      cin >> l >> r;
      graph[l-1][r-1]=1;
    }

    for(int i=0;i<g;i++)
      for(int j=0;j<b;j++)
      	if(graph[i][j]==0)add_edge(i,j+g);
	  
    V=g+b;
    cout << "Case " << t++ << ": " << g+b-bitpartite_matching() << endl;
  }
  
  return 0;
}