#include<iostream>
#include<vector>
#include<algorithm>
  
const int INF=1000000000;
  
using namespace std;
  
int main(void){
  
  int n,m,c,s,g,x,y,d,C;
  int p[21],q[21][51],r[21][51];
  int graph[21][101][101],G[101][101],cost[21][20001];
    
  while(cin >> n >> m >> c >> s >> g,n|m|c|s|g){
    
    fill(graph[0][0],graph[21][101],INF);
    fill(G[0],G[101],INF);
 
    for(int i=0;i<21;i++)
      for(int j=0;j<101;j++)graph[i][j][j]=0;
    
    for(int i=0;i<m;i++){
      cin >> x >> y >> d >> C;
      graph[C][x][y]=graph[C][y][x]=min(graph[C][x][y],d);
    }
    
    for(int i=1;i<=c;i++)cin >> p[i];
    
    for(int i=1;i<=c;i++){
      for(int j=1;j<p[i];j++)cin >> q[i][j];
      for(int j=1;j<=p[i];j++)cin >> r[i][j];
    }
    
    for(int l=1;l<=c;l++)
      for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    graph[l][i][j]=min(graph[l][i][j],graph[l][i][k]+graph[l][k][j]);
    
    fill(cost[0],cost[21],0);
    
    for(int i=1;i<=c;i++){
      for(int j=1,k=0;j<20001;j++){
	if(k<p[i] && q[i][k]<j)k++;
	cost[i][j]=cost[i][j-1]+r[i][k];
      }
    }
    
    for(int l=1;l<=c;l++)
      for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	  if(graph[l][i][j]!=INF)
	    G[i][j]=min(G[i][j],cost[l][graph[l][i][j]]);

    for(int k=1;k<=n;k++)
      for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	  G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
    
    if(G[s][g]==INF)cout << -1 << endl;
    else cout << G[s][g] << endl;
  }
  
  return 0;
}
