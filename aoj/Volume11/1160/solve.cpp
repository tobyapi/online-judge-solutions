#include<iostream>

using namespace std;

int w,h,grid[50][50];

void rec(int x,int y){
  grid[y][x]=false;
  for(int i=-1;i<2;i++){
    for(int j=-1;j<2;j++){
      int ny=y+i,nx=x+j;
      if(0<=nx && nx<w && 0<=ny && ny<h && grid[ny][nx])
	rec(nx,ny);
    }
  }
}

int main(void){

  while(cin >> w >> h,w|h){
    for(int i=0;i<h;i++)
      for(int j=0;j<w;j++)cin >> grid[i][j];
    
    int ans=0;
    for(int i=0;i<h;i++)
      for(int j=0;j<w;j++)
	if(grid[i][j])rec(j,i),ans++;
  
    cout << ans << endl;
  }
  return 0;
}
