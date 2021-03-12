#include<stdio.h>
#include<string.h>

int n,vis[101][101];

struct point{int x,y;};
struct point grid[101][101];

int dfs(int x,int y,int fg){
  
  vis[y][x]=fg;
  struct point nx=grid[y][x];
  int res=vis[nx.y][nx.x];
  
  if(vis[nx.y][nx.x]==0)res=dfs(nx.x,nx.y,fg);
  
  return vis[y][x]=res;
}

int main(void){
  
  struct point p;
  int i,j,cnt;  

  while(scanf("%d",&n),n){
    memset(vis,0,sizeof(vis));
    
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	scanf("%d %d",&p.x,&p.y);
	grid[i][j]=p;
      }
    }
    
    for(i=0,cnt=1;i<n;i++)
      for(j=0;j<n;j++)
	if(!vis[i][j] && dfs(j,i,cnt)==cnt)cnt++;  

    printf("%d\n",cnt-1);
  }
  
  return 0;
}
