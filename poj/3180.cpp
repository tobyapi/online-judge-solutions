#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,m;
vector<int>G[10001],rG[10001];
bool used[10001];
vector<int>vs;

void add_edge(int from,int to){
  G[from].push_back(to);
  rG[to].push_back(from);
}

void dfs(int v){
  used[v]=true;
  for(int i=0;i<G[v].size();i++){
    if(!used[G[v][i]])dfs(G[v][i]);
  }
  vs.push_back(v);
}

int rdfs(int v,int d){
  used[v]=true;
  int res=d;
  for(int i=0;i<rG[v].size();i++){
    if(!used[rG[v][i]])res=max(res,rdfs(rG[v][i],d+1));
  }
  return res;
}

int scc(){
  fill(used,used+10001,false);
  vs.clear();
  for(int i=1;i<=n;i++)if(!used[i])dfs(i);
  
  fill(used,used+10001,false);
  
  int cnt=0;
  for(int i=vs.size()-1;i>=0;i--)
    if(!used[vs[i]] && rdfs(vs[i],1)>1)cnt++;
  
  return cnt;
}

int main(void){
  
  cin >> n >> m;
  
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    add_edge(a,b);
  }
  
  cout << scc() << endl;
  
  return 0;
}