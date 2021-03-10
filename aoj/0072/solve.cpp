#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>

#define MAX_V 101
#define INF 10000000

using namespace std;


struct edge{int to, cost; };
typedef pair<int, int> P;

int V,mincost[MAX_V];
vector<edge>G[MAX_V];

int Prim(int s){
  priority_queue<P, vector<P>, greater<P> >que;
  fill(mincost, mincost+V, INF);

  vector<bool> visited(V);
  fill(visited.begin(),visited.end(),false);

  mincost[s]=0;
  que.push(P(0,s));
  int res=0;

  while(!que.empty()){
    P p = que.top();
    que.pop();
    
    int v = p.second;
    if(visited[v])continue;
    visited[v]=true;
    res+=mincost[v];

    for(int i=0; i < G[v].size(); i++){
      edge e = G[v][i];
      if(mincost[e.to] > e.cost && !visited[e.to]){
	mincost[e.to] = e.cost;
	que.push(P(mincost[e.to], e.to));
      }
    }
  }
 
  return res;
}


int main(void){
  int m,a,b,c;
  char ch1,ch2;
  edge e;

  while(cin >> V,V){
    for(int i=0;i<V;i++)G[i].clear();
    cin >> m;
    for(int i=0;i<m;i++){
      cin >> a >> ch1 >> b >> ch2 >> c;
      e.to=b,e.cost=c/100-1;
      G[a].push_back(e);
      e.to=a;
      G[b].push_back(e);
    }
      cout << Prim(0) << endl;
  }

  return 0;
}
