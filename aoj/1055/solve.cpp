#include<iostream>
#include<vector>
#include<algorithm>

#define to first
#define cnt first
#define cost second
#define MAX_N 100001
#define MOD 10007

using namespace std;

typedef pair<int,int> P;

vector<P>G[MAX_N];
bool vis[MAX_N];

P dfs(int n,P x){
  vis[n]=true;

  for(int i=0;i<G[n].size();i++){
    P e=G[n][i];
    if(x.cost<e.cost)x.cost=e.cost,x.cnt=1;
    else if(x.cost==e.cost)x.cnt++;
    if(!vis[e.to])x=dfs(e.to,x);
  }

  return x;
}

int main(void){

  int n,b,fb;

  while(cin >> n,n){

    for(int i=0;i<MAX_N;i++)G[i].clear();

    for(int i=0;i<n;i++){
      for(int j=0;j<2;j++){
	cin >> b >> fb;
	G[i].push_back(make_pair(b,fb));
      }
    }

    fill(vis,vis+MAX_N,false);
    int ans=1;
    for(int i=0;i<n;i++){
      if(!vis[i]){
	P x(0,0);
	x=dfs(i,x);
	ans=ans%MOD*x.cnt/2%MOD;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
