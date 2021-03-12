#include<iostream>
#include<algorithm>
#include<cstdio>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char grid[12][12];

void rec(int x,int y){
	grid[y][x]='0';
	
	rep(i,4){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0 || ny<0 || 12<=nx || 12<=ny || grid[ny][nx]=='0')continue;
		rec(nx,ny);
	}
}

int main(void){
	
	while(true){
		rep(i,12)rep(j,12)if(scanf(" %c",&grid[i][j])==EOF)return 0;
		
		int ans=0;
		rep(i,12)rep(j,12)
			if(grid[i][j]=='1')rec(j,i),ans++;
		
		cout << ans << endl;
	}
	
	return 0;
}
