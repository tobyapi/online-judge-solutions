#include<iostream>

using namespace std;

int h,w,grid[102][102],vis[102][102];
int dx1[6]={0,1,-1,1,0,1};
int dx2[6]={-1,0,-1,1,-1,0};
int dy[6]={-1,-1,0,0,1,1};

int rec(int x,int y){
  vis[y][x]=1;
  int res=0;

  for(int i=0;i<6;i++){
    int nx=x+(y%2?dx1[i]:dx2[i]),ny=y+dy[i];
    if(nx<0 || ny<0 || w+1<nx || h+1<ny)continue;
    if(grid[ny][nx])res++;
    if(!vis[ny][nx])res+=rec(nx,ny);
  }

  return res;
}

int main(void){

  cin >> w >> h;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin >> grid[i][j];
      vis[i][j]=grid[i][j];
    }
  }
  cout << rec(0,0) << endl;

  return 0;
}
