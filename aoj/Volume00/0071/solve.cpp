#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string grid[8];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

void func(int y,int x){
  grid[y][x]='0';
  for(int i=0;i<4;i++)
    for(int j=1;j<4;j++)
      if(x+dx[i]*j<8 && y+dy[i]*j<8 && 
	 x+dx[i]*j>=0 && y+dy[i]*j>=0 && 
	 grid[y+dy[i]*j][x+dx[i]*j]=='1'){
	func(y+dy[i]*j,x+dx[i]*j);
	grid[y+dy[i]*j][x+dx[i]*j]='0';
      }
}

int main(void){
  int n,sx,sy;

  cin >> n;

  for(int t=1;t<=n;t++){
    for(int i=0;i<8;i++)cin >> grid[i];
    cin >> sx >> sy;
    func(--sy,--sx);
    cout << "Data " << t <<':'<<endl;
    for(int i=0;i<8;i++)cout << grid[i] << endl;
  }
  return 0;
}
