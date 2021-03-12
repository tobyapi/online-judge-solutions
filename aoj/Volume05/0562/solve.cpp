#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#define INF 100000001

using namespace std;

struct edge{
  int to;
  double cost;
};

typedef pair<double,double>P;
int N;
double d[3001];
vector<edge>G[3001];
vector<int>S;

void dijkstra(void){
  priority_queue<P,vector<P>,greater<P> >que;
  fill(d,d+N+1,INF);
  for(int i=0;i<S.size();i++){
    d[S[i]]=0;
    que.push(P(0,S[i]));
  }

  while(!que.empty()){
    P p=que.top();
    que.pop();
    int v=p.second;
    if(d[v]<p.first)continue;

    for(int i=0;i<G[v].size();i++){
      edge e=G[v][i];
      if(d[e.to]>d[v]+e.cost){
	d[e.to]=d[v]+e.cost;
	que.push(P(d[e.to],e.to));
      }
    }
  }
}

int main(void){
  int M,K,a,b,l,s;

  cin >> N >> M >> K;

  edge e;
  for(int i=0;i<M;i++){
    cin >> a >> b >> e.cost;
    e.to=b;
    G[a].push_back(e);
    e.to=a;
    G[b].push_back(e);
  }
  for(int i=0;i<K;i++){
    cin >> s;
    S.push_back(s);
  }
   
  dijkstra();

  double ans=0;
  for(int i=1;i<=N;i++)
    for(int j=0;j<G[i].size();j++)
      ans=max(ans,round((d[i]+d[G[i][j].to]+G[i][j].cost)/2.0));
  cout << ans << endl;

  return 0;
}
