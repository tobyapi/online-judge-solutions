#include<stdio.h>
#define INF 10000000
int min(int,int);
void warshall_floyd(void);

int graph[21][21];
int V;

int main(void){
int i,j,road,a,b,c,d;
int x1,x2,y1,y2;
for(i=0;i<21;i++)
for(j=0;j<21;j++)
graph[i][j]=INF;

scanf("%d",&V);
scanf("%d",&road);
for(i=0;i<road;i++){
scanf("%d,%d,%d,%d",&a,&b,&c,&d);
graph[a][b]=c;
graph[b][a]=d;
}
scanf("%d,%d,%d,%d",&x1,&x2,&y1,&y2);
warshall_floyd();

printf("%d\n",y1-graph[x1][x2]-graph[x2][x1]-y2);

return 0;
}

int min(int x,int y){
return (x>y)?y:x;
}

void warshall_floyd(){
int i,j,k;
for(k=0;k<=V;k++)
for(i=0;i<=V;i++)
for(j=0;j<=V;j++)
graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
}
