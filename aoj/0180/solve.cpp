#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

struct edge{int u,v,cost;};

int par[101],rank[101];
edge es[200];
int V,E;

void init_union_find(int n){for(int i=0;i<n;i++)par[i]=i,rank[i]=0;}

int find(int x){
  if(par[x]==x)return x;
  else return par[x]=find(par[x]);
}

void unite(int x,int y){
  x=find(x),y=find(y);
  if(x==y)return;
  if(rank[x] < rank[y])par[x]=y;
  else par[y]=x,rank[x]+=(rank[x]==rank[y]);
}

bool same(int x,int y){return find(x)==find(y);}

bool comp(const edge& e1,const edge& e2){return e1.cost < e2.cost;}

int kruskal(){
  sort(es,es+E,comp);
  init_union_find(V);
  int res=0;
  for(int i=0;i<E;i++){
    edge e=es[i];
    if(!same(e.u,e.v))unite(e.u,e.v),res+=e.cost;
  }
  return res;
}

int main(void){
  int a,b,c;

  while(cin >> V >> E && V){
    for(int i=0;i<E;i++){
      cin >> a >> b >> c;
      es[i].u=a,es[i].v=b,es[i].cost=c;
    }
    cout << kruskal() << endl;
  }
  return 0;
}
