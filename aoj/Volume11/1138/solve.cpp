#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

#define INF (1<<29)
 
using namespace std;
 
int main(void){
  
  int n,m,p,a,b,x,y,z,in;
  double dp[(1<<8)][31],graph[31][31];
  vector<int>t;
  
  while(cin >> n >> m >> p >> a >> b){
    if(!(n|m|p|a|b))break;
    
    t.clear();
    
    fill(graph[0],graph[31],-1);
    fill(dp[0],dp[(1<<8)],INF);

    for(int i=0;i<n;i++){
      cin >> in;
      t.push_back(in);
    }
    
    for(int i=0;i<p;i++){
      cin >> x >> y >> z;
      graph[x][y]=graph[y][x]=z;
    }
    
    dp[0][a]=0;
    double res=INF;
    for(int S=0;S<(1<<n);S++){
      res=min(res,dp[S][b]);
      for(int v=1;v<=m;v++){
	for(int i=0;i<n;i++){
	  if(!(S>>i & 1)){
	    for(int u=1;u<=m;u++){
	      if(graph[v][u]<0)continue;
		dp[S|(1<<i)][u]=min(dp[S|(1<<i)][u],dp[S][v]+graph[v][u]/t[i]);
	    }
	  }
	}
      }
    }
    if(res==INF)printf("Impossible\n");
    else printf("%.3f\n",res);
  }
  
  return 0;
}
