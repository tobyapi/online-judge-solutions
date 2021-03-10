#include<iostream>
#include<vector>
#include<algorithm>

#define MAX_N 10001

using namespace std;

int par[MAX_N],rank[MAX_N];

void init(int n){
  for(int i=0;i<n;i++){
    par[i]=i;
    rank[i]=0;
  }
}

int find(int x){
  if(par[x]==x)return x;
  return par[x]=find(par[x]);
}

void unit(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y)return;

  if(rank[x]<rank[y])par[x]=y;
  else {
    par[y]=x;
    if(rank[x]==rank[y])rank[x]++;
  }
}

bool same(int x,int y){
  return find(x)==find(y);
}

int main(void){

  int n,q;
  cin >> n >> q;
  init(n);
  while(q--){
    int com,x,y;
    cin >> com >> x >> y;
    if(com)cout << same(x,y) << endl;
    else unit(x,y);
  }
  return 0;
}
