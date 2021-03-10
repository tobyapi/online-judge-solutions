#include<stdio.h>
#define INF 10000000

int time[101][101],cost[101][101],m;

void warshall_floyd_cost(void);
void warshall_floyd_time(void);
int min(int,int);
void init(void);

int main(void){
  int i,j,n,k,a,b,cos,tim,p,q,r;

  while(scanf("%d %d",&n,&m),n,m){

    init();

    for(i=0;i<n;i++){
      scanf("%d %d %d %d",&a,&b,&cos,&tim);
      cost[a][b]=cost[b][a]=cos;
      time[a][b]=time[b][a]=tim;
    }

    warshall_floyd_cost();
    warshall_floyd_time();

    scanf("%d",&k);
    for(i=0;i<k;i++){
      scanf("%d %d %d",&p,&q,&r);
      printf("%d\n",r?time[p][q]:cost[p][q]);
    }
  }
  
  return 0;
}

void init(void){
  int i,j;
  for(i=0;i<101;i++){
    for(j=0;j<101;j++){
      time[i][j]=cost[i][j]=INF;     
    }
    time[i][i]=cost[i][i]=0;
  }
}

void warshall_floyd_cost(void){
  int i,j,k;
  for(k=0;k<=m;k++)
    for(i=0;i<=m;i++)
      for(j=0;j<=m;j++)
	cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
}

void warshall_floyd_time(void){
  int i,j,k;
  for(k=0;k<=m;k++)
    for(i=0;i<=m;i++)
      for(j=0;j<=m;j++)
	time[i][j]=min(time[i][j],time[i][k]+time[k][j]);
}

int min(int x,int y){
  return x<y?x:y;
}
