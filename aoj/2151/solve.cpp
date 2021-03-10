#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include<set>
#include <vector>

#define F first
#define S second
#define MAX_V 110
#define INF (1<<29)

using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> P3;

struct edge{int to,d,e;};

vector<edge>g[MAX_V];
int d[MAX_V][101],n,m,l;

void dijkstra(int s){
  priority_queue<P3,vector<P3>,greater<P3> >que;

  fill(d[0],d[MAX_V],INF);
  d[s][l]=0;
  que.push(P3(0,P(l,s)));

  while(!que.empty()){
    P3 p=que.top();que.pop();
    int v=p.S.S;
    if(d[v][p.S.F]<p.F)continue;
    if(v==n){
      cout << p.F << endl;
      return;
    }

    for(int i=0;i<g[v].size();i++){
      edge e=g[v][i];
      if(d[e.to][p.S.F]>d[v][p.S.F]+e.e){
        d[e.to][p.S.F]=d[v][p.S.F]+e.e;
        que.push(P3(d[e.to][p.S.F],P(p.S.F,e.to)));
      }

      if(p.S.F-e.d>=0 && d[e.to][p.S.F-e.d]>d[v][p.S.F]){
        d[e.to][p.S.F-e.d]=d[v][p.S.F];
        que.push(P3(d[e.to][p.S.F-e.d],P(p.S.F-e.d,e.to)));
      }
    }
  }
}

int main(void){

  while(cin >> n >> m >> l,n|m|l){
    for(int i=0;i<MAX_V;i++)g[i].clear();
    int a,b,d1,e;
    for(int i=0;i<m;i++){
      cin >> a >> b >> d1 >> e;
      edge e1,e2;
      e1.to=b,e1.d=d1,e1.e=e;
      e2.to=a,e2.d=d1,e2.e=e;
      g[a].push_back(e1);
      g[b].push_back(e2);
    }

    dijkstra(1);
  }

  return 0;
}
