#include<iostream>
#include<cstdio>
#include<algorithm>

#define INF (1<<29)

using namespace std;

int g[21][21];
int V;

int main(void){

  fill(g[0],g[21],INF);

  int n;
  cin >> V >> n;

  int a,b,c,d;
  for(int i=0;i<n;i++){
    scanf("%d,%d,%d,%d",&a,&b,&c,&d);
    g[a][b]=c,g[b][a]=d;
  }
  int x1,x2,y1,y2;
  scanf("%d,%d,%d,%d",&x1,&x2,&y1,&y2);
  for(int k=0;k<=V;k++){
    for(int i=0;i<=V;i++){
      for(int j=0;j<=V;j++){
        g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
      }
    }
  }

  cout << y1-g[x1][x2]-g[x2][x1]-y2 << endl;

  return 0;
}
