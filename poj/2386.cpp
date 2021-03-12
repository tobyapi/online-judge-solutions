#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n,m;
string g[101];

void dfs(int x,int y){

	g[y][x]='.';
	
	for(int i=-1;i<2;i++){
		for(int j=-1;j<2;j++){
			int nx=x+i,ny=y+j;
			if(nx<0 || ny<0 || m<=nx || n<=ny)continue;
			if(g[ny][nx]=='W')dfs(nx,ny);
		}
	}
}

int main(void){
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++)cin >> g[i];
	
	int cnt=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(g[i][j]=='W')cnt++,dfs(j,i);

	cout << cnt << endl;
	
  return 0;
}