#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int main(void){
  int graph[101][101],cpy[101][101],n,m,a,b,c;

  while(cin >> n >> m,n|m){

    for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++){
	graph[i][j]=cpy[i][j]=10000000;
      }
      graph[i][i]=0;
    }

    for(int i=0;i<m;i++){
      cin >> a >> b >> c;
      graph[a][b]=graph[b][a]=cpy[a][b]=cpy[b][a]=c;
    }

    for(int k=0;k<=n;k++)
      for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
	  graph[i][j]=graph[j][i]=min(graph[i][j],graph[i][k]+graph[k][j]);
    
    int ans=INT_MAX;
    for(int k=0;k<=n;k++)
      for(int i=0;i<=n;i++)
	if(cpy[i][k]<10000000)
	  for(int j=0;j<=n;j++)
	    if(cpy[k][j]<10000000)
	      ans=min(ans,graph[1][i]+graph[j][n]);

    cout << ans << endl;
  }
}
