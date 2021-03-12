#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

#define max_v 100010

using namespace std;

int dfnum[max_v];
int vertex[max_v];
int parent[max_v];
int ancestor[max_v];
int idom[max_v];
int semi[max_v];
int samedom[max_v];
int best[max_v];
vector<int>bucket[max_v];

vector<int>G[max_v],rG[max_v];

void dfs(int p, int n,int &k){
  if(dfnum[n]==0 && !(n==0 && p>0)){
    dfnum[n]=k;
    vertex[k++]=n;
    parent[n]=p;
    for(int i=0;i<G[n].size();i++){
      dfs(n,G[n][i],k);
    }
  }
}

int ancestorWithLowestSemi(int v){
  int a=ancestor[v];
  if(ancestor[a]>0){
    int b=ancestorWithLowestSemi(a);
    ancestor[v]=ancestor[a];
    if(dfnum[semi[b]] < dfnum[semi[best[v]]])best[v]=b;
  }
  return best[v];
}

void link(int p,int n){
  ancestor[n]=p;
  best[n]=n;
}

void dominator(int sz,int root){
  for(int i=0;i<sz;i++){
    bucket[i].clear();
    dfnum[i]=semi[i]=ancestor[i]=idom[i]=samedom[i]=0;
  }

  int N=0;
  dfs(0,root,N);
  
  for(int i=N-1;i>0;i--){
    int n=vertex[i],p=parent[n],s=p;
    for(int j=0;j<rG[n].size();j++){
      int v=rG[n][j],s1;
      if(dfnum[v]<=dfnum[n])s1=v;
      else s1=semi[ancestorWithLowestSemi(v)];
      
      if(dfnum[s1]<dfnum[s])s=s1;
    }
    semi[n]=s;
    bucket[s].push_back(n);
    link(p,n);
    for(int j=0;j<bucket[p].size();j++){
      int v=bucket[p][j],y=ancestorWithLowestSemi(v);
      if(semi[y]==semi[v])idom[v]=p;
      else samedom[v]=y;
    }
    bucket[p].clear();
  }

  for(int i=1;i<N;i++){
    int n=vertex[i];
    if(samedom[n]>0){
      idom[n]=idom[samedom[n]];
    }
  }

  for(int i=1;i<N;i++){
    for(int j=0;j<rG[i].size();j++){
      if(rG[i][j]==root)idom[i]=0;
    }
  }
}

int main(void){

  int n,m;
  cin >> n >> m;

  for(int i=0;i<m;i++){
    int s,t;
    cin >> s >> t;
    s--,t--;
    G[s].push_back(t);
    rG[t].push_back(s);
  }

  dominator(n,0);

  int q,r;
  cin >> q;
  while(q--){
    cin >> r;
    r--;
    if(idom[r]==0)cout << r+1 << endl;
    else cout << idom[r]+1 << endl;
  }

  return 0;
}
