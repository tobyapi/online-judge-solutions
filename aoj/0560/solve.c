#include<stdio.h>

  int Jgraph[1001][1001],Igraph[1001][1001],Ograph[1001][1001];

int main(void){
  char graph[1002][1002];
  int m,n,k,i,j,a,b,c,d,ansJ,ansI,ansO;

  scanf("%d %d %d\n",&m,&n,&k);

  for(i=0;i<m;i++)
    for(j=0;j<n;j++)
      scanf(" %c",&graph[i][j]);

  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      Jgraph[i+1][j+1]=graph[i][j]=='J'?1:0;
      Ograph[i+1][j+1]=graph[i][j]=='O'?1:0;
      Igraph[i+1][j+1]=graph[i][j]=='I'?1:0;
    }
  }

  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      Jgraph[i+1][j+1]+=Jgraph[i+1][j];
      Ograph[i+1][j+1]+=Ograph[i+1][j];
      Igraph[i+1][j+1]+=Igraph[i+1][j];
    }
  }
  
  for(i=0;i<=m;i++){
    for(j=0;j<=n;j++){
      Jgraph[i+1][j+1]+=Jgraph[i][j+1];
      Ograph[i+1][j+1]+=Ograph[i][j+1];
      Igraph[i+1][j+1]+=Igraph[i][j+1];
    }
  }

  for(i=0;i<k;i++){
    scanf("%d %d %d %d",&a,&b,&c,&d);
    ansJ=Jgraph[c][d]-Jgraph[c][b-1]-Jgraph[a-1][d]+Jgraph[a-1][b-1];
    ansO=Ograph[c][d]-Ograph[c][b-1]-Ograph[a-1][d]+Ograph[a-1][b-1];
    ansI=Igraph[c][d]-Igraph[c][b-1]-Igraph[a-1][d]+Igraph[a-1][b-1];
    printf("%d %d %d\n",ansJ,ansO,ansI);
  }

  return 0;
}
