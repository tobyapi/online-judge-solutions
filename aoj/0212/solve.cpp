#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>

using namespace std;

typedef pair<int, int> P;
typedef pair<int, pair<int, int> > P3;

struct edge{
  int to,cost;
};

int minCost[101][11];
vector<edge> G[101];
static const int INF = INT_MAX;

int c,n,m,d;

int dijkstra(int s){
  priority_queue<P3, vector<P3>, greater<P3> >que;
  que.push(make_pair(0,make_pair(s,c)));

  for(int i=0;i<101;i++)
    for(int j=0;j<11;j++)
      minCost[i][j]=INF;

  while(!que.empty()){
    P3 p = que.top();
    que.pop();
    
    for(int i=0;i<G[p.second.first].size();i++){
      edge e = G[p.second.first][i];
      if(p.first+e.cost < minCost[e.to][p.second.second]){
	minCost[e.to][p.second.second] = p.first+e.cost;
	que.push(make_pair(p.first+e.cost,make_pair(e.to,p.second.second)));
      }
    }
    
    if(p.second.second==0)continue;
    
    for(int j=0;j<G[p.second.first].size();j++){
      edge e = G[p.second.first][j];
      if(p.first+e.cost/2 < minCost[e.to][p.second.second-1]){
	minCost[e.to][p.second.second-1] = p.first+e.cost/2;
	que.push(make_pair(p.first+e.cost/2,make_pair(e.to,p.second.second-1)));
      }
    }
  }
  int ans=INT_MAX;
  for(int i=0;i<11;i++)
    ans=min(minCost[d][i],ans);

  return ans;
}

int main(void){
  int a,b,f,s;

  while(cin >> c >> n >> m >> s >> d,c|n|m|s|d){

    for(int i=0;i<=n;i++)G[i].clear();

    for(int i=0;i<m;i++){
      cin >> a >> b >> f;
      edge e;
      e.to=b,e.cost=f;
      G[a].push_back(e);
      e.to=a;
      G[b].push_back(e);
    }

    cout << dijkstra(s) << endl;
  }

  return 0;
}
