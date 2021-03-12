#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
 
#define INF (1LL<<62)
 
using namespace std;
 
typedef long long ll;
 
ll g[101][101],n,m;
 
ll rec(set<int> S,int mx){
   
  if(mx<0)return 0;
 
  ll res=0;
  set<int>::iterator it=S.begin();
  for(;it!=S.end();it++){
    set<int>::iterator j=S.begin();
    ll t=INF;
    for(;j!=S.end();j++){
      if(it==j)continue;
      t=min(t,g[*it][*j]);
    }
    res+=t;
  }
   
  if(mx>=n-1)return res;
 
  int id=-1;
  ll cost=0;
  for(int v=mx+1;v<n;v++){
    if(S.count(v))continue;
 
    bool fg=true;
    set<int>::iterator it=S.begin();
    for(;it!=S.end();it++){
      fg&=(g[v][*it]<INF);
    }
    if(!fg)continue;
    
    set<int>T=S;
    T.insert(v);
    cost=max(cost,rec(T,v));
  }
   
  return max(res,cost);
}
 
int main(void){
 
  fill(g[0],g[101],INF);
  for(int i=0;i<101;i++)g[i][i]=0;
 
  cin >> n >> m;
 
  for(int i=0;i<m;i++){
    ll a,b,f;
    cin >> a >> b >>f;
    g[a-1][b-1]=g[b-1][a-1]=f;
  }
   
  ll ans=0;
 
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(g[i][j]<INF){
    set<int>S;
    S.insert(i);
    S.insert(j);
    ans=max(ans,rec(S,max(i,j)));
      }
    }
  }
 
  cout << ans << endl;
   
  return 0;
}
