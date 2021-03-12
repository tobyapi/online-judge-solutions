#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define MAX_V 1000000
#define f first
#define s second
using namespace std;

typedef pair<int,int> P;

P par[MAX_V];
int rank[MAX_V];

void init(int n){
  for(int i=0;i<n;i++)
    par[i].f=i,par[i].s=0,rank[i]=0;
}

P find(int x){

  if(par[x].f==x)return par[x];
  P p=find(par[x].f);
  par[x].s+=p.s,par[x].f=p.f;
  return par[x];
}

void unite(int x,int y,int w){
  P px=find(x);
  P py=find(y);
  par[px.f].f=py.f;
  par[px.f].s+=par[y].s-w-par[x].s;
}

bool same(int x,int y){return find(x).f==find(y).f;}

int main(void){

  int n,m;
  while(cin >> n >> m,n|m){
    init(n+1);
    int a,b,w;
    char c;
    for(int i=0;i<m;i++){
      cin >> c >> a >> b;
      if(c=='!'){
        cin >> w;
        unite(a,b,w);
      }
      else {
        if(!same(a,b))cout << "UNKNOWN" << endl;
        else cout << par[b].s-par[a].s << endl;
      }
    }
  }
  return 0;
}
