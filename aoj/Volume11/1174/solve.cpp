#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int h,w,c,grid[8][8];
bool vis[8][8];


int Count(int x,int y, int col){
	int cnt=1;
	vis[y][x]=true;
	
	rep(i,4){
		int nx=x+dx[i],ny=y+dy[i];
		if(0<=nx && 0<=ny && nx<w && ny<h &&
			grid[ny][nx]==col && !vis[ny][nx])cnt+=Count(nx,ny,col);
	}
	return cnt;
}


void rec(int x,int y, int col){
	int tmp=grid[y][x],cnt=1;
	grid[y][x]=col;
	
	rep(i,4){
		int nx=x+dx[i],ny=y+dy[i];
		if(0<=nx && 0<=ny && nx<w && ny<h && grid[ny][nx]==tmp)rec(nx,ny,col);
	}
}

int solve(int n){
	int ans=0;
	if(n==5){
		if(grid[0][0]!=c)rec(0,0,c);
		fill(vis[0],vis[8],false);
		return Count(0,0,c);
	}
	
	int tmp[8][8];
	rep(i,8)rep(j,8)tmp[i][j]=grid[i][j];
	for(int i=1;i<7;i++){
		if(grid[0][0]!=i)rec(0,0,i);
		ans=max(ans,solve(n+1));
		
		rep(j,8)rep(k,8)grid[j][k]=tmp[j][k];
	}
	return ans;
}

int main(void){
	
	while(cin >> h >> w >> c,h|w|c){
		fill(grid[0],grid[8],0);
		rep(i,h)rep(j,w)cin >> grid[i][j];
		
		cout << solve(1) << endl;
	}
	
	return 0;
}
