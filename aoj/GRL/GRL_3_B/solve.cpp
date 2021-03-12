#include<iostream>
#include<vector>
#include<algorithm>

#define MAX_V 100001
#define INF (1<<29)

using namespace std;

typedef pair<int,int> P;

vector<int>G[MAX_V];
vector<P> bridge;
int pnum[MAX_V],lowest[MAX_V],num;
bool used[MAX_V];

int dfs(int v,int prev){
  pnum[v]=num,lowest[v]=num;
  num++;
  used[v]=true;

  for(int i=0;i<G[v].size();i++){
    int nx=G[v][i];
    if(!used[nx]){
      dfs(nx,v);
      lowest[v]=min(lowest[v],lowest[nx]);
      if(pnum[v]<lowest[nx])
        bridge.push_back(make_pair(min(v,nx),max(v,nx)));
    }
    else if(nx!=prev){
      lowest[v]=min(lowest[v],pnum[nx]);
    }
  }
}

void Bridge(void){
  fill(used,used+MAX_V,false);
  fill(lowest,lowest+MAX_V,INF);
  fill(pnum,pnum+MAX_V,INF);
  num=0;
  bridge.clear();
  dfs(0,-1);
  sort(bridge.begin(),bridge.end());
}

int main(void){
  int n,m;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  Bridge();

  for(int i=0;i<bridge.size();i++)
    cout << bridge[i].first << " " << bridge[i].second << endl;

  return 0;
}
