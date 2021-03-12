#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#include<map>

#define MAX_V 5000
#define INF (1<<29)

using namespace std;

struct edge{int to,cap,rev;};

vector<edge>g[MAX_V];
bool used[MAX_V];

void add_edge(int from,int to,int cap){
  g[from].push_back((edge){to,cap,g[to].size()});
  g[to].push_back((edge){from,0,g[from].size()-1});
}

int dfs(int v,int t,int f){
  if(v==t)return f;
  used[v]=true;
  for(int i=0;i<g[v].size();i++){
    edge &e=g[v][i];
    if(!used[e.to] && e.cap>0){
      int d=dfs(e.to,t,min(f,e.cap));
      if(d>0){
        e.cap-=d;
        g[e.to][e.rev].cap+=d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s,int t){
  int flow=0;
  for(;;){
    fill(used,used+MAX_V,false);
    int f=dfs(s,t,INF);
    if(f==0)return flow;
    flow+=f;
  }
}

int main(void){

  int n;
  while(cin >> n,n){

    for(int i=0;i<MAX_V;i++)g[i].clear();

    vector<int>a;
    map<int,int>mp;
    int m,in,tmp;
    cin >> tmp;
    for(int i=0;i<tmp;i++){
      cin >> in;
      add_edge(n+tmp,i,1);
      a.push_back(in);
      mp[in]=i;
    }

    for(int i=0;i<n;i++){
      cin >> m;
      vector<int>b(m);
      for(int j=0;j<m;j++)cin >> b[j];
      for(int j=0;j<m;j++){
        if(mp.count(b[j])){
          add_edge(mp[b[j]],i+tmp,1);
        }
      }
    }

    for(int i=0;i<n;i++){
      add_edge(i+tmp,n+tmp+1,1);
    }
    cout << max_flow(n+tmp,n+tmp+1) << endl;
  }
  return 0;
}
