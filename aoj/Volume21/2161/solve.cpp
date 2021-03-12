#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>

#define MAX_V 210
#define INF (1<<29)

using namespace std;

const double EPS=1e-10;

struct edge{int to,cap,rev;};

vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from,int to,double cap){
  G[from].push_back((edge){to,cap,G[to].size()});
  G[to].push_back((edge){from,0,G[from].size()-1});
}

int dfs(int v,int t,int f){
  if(v==t)return f;
  used[v]=true;
  for(int i=0;i<G[v].size();i++){
    edge &e=G[v][i];
    if(!used[e.to] && e.cap>0){
      int d=dfs(e.to,t,min(f,e.cap));
      if(d>0){
        e.cap-=d;
        G[e.to][e.rev].cap+=d;
        return d;
      }
    }
  }
  return 0;
}

vector<double>cost[MAX_V];
int n,m;

int max_flow(double lim){

  for(int i=0;i<MAX_V;i++)G[i].clear();

  int s=n+m,t=n+m+1;
  for(int i=0;i<n;i++)add_edge(s,i,1);
  for(int i=0;i<m;i++)add_edge(i+n,t,1);

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(cost[i][j]<lim+EPS){
        add_edge(i,j+n,1);
      }
    }
  }

  int flow=0;
  for(;;){
    fill(used,used+MAX_V,false);
    int f=dfs(s,t,INF);
    if(f==0)return flow;
    flow+=f;
  }
}

double dist(double x1,double y1,double x2,double y2){
  return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

int main(void){

  while(cin >> n >> m,n|m){
    vector<double>nx(n),ny(n),nv(n),mx(m),my(m);

    for(int i=0;i<n;i++)
      cin >> nx[i] >> ny[i] >> nv[i];

    for(int i=0;i<m;i++)
      cin >> mx[i] >> my[i];

    for(int i=0;i<n;i++){
      cost[i].resize(m);
      for(int j=0;j<m;j++){
        cost[i][j]=dist(nx[i],ny[i],mx[j],my[j])/nv[i];
      }
    }

    double l=0,r=1e8;

    for(int i=0;i<100;i++){
      double mid=(l+r)/2;
      int res=max_flow(mid);
      if(res==m)r=mid;
      else l=mid;
    }

    printf("%.8f\n",r);
  }

  return 0;
}
