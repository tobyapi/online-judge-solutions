#include<stdio.h>
#define INF 1000000
int edge[101][101],mincost[101],used[101],V;

int prim(void);
int min(int,int);

int main(void){
  int e,i,j,a,b,cost;

  while(scanf("%d %d",&V,&e),V,e){
    for(i=0;i<V;i++){
      for(j=0;j<V;j++){
	edge[i][j]=edge[j][i]=INF;
      }
    }
    
    for(i=0;i<e;i++){
      scanf("%d %d %d",&a,&b,&cost);
      edge[a][b]=edge[b][a]=cost;
    }
    printf("%d\n",prim());
}
  return 0;
}

int prim(void){
  int i,u,v;
  for(i=0;i<V;i++){
    mincost[i]=INF;
    used[i]=0;
  }
  
  mincost[0]=0;
  int res=0;
  
  while(1){
    v=-1;
    
    for(u=0;u<V;u++)
      if(!used[u] && (v==-1 || mincost[v]>mincost[u]))v=u;
    
    if(v==-1)break;
    used[v]=1;
    res+=mincost[v];
    
    for(u=0;u<V;u++)
      mincost[u]=min(mincost[u],edge[v][u]);
  }
  
  return res;
}

int min(int x,int y){
  return x<y?x:y;
}
