#include<iostream>
#include<algorithm>


using namespace std;

int n,vis[101][101];
struct point{int x,y;};
point grid[101][101];

int dfs(int x,int y,int fg){

	vis[y][x]=fg;
	point nx=grid[y][x];
	int res=vis[nx.y][nx.x];
	
	if(vis[nx.y][nx.x]==0)res=dfs(nx.x,nx.y,fg);
	vis[y][x]=res;
	
	return res;
}

int main(void){

	point p;
	
	while(cin >> n,n){
		fill(vis[0],vis[101],0);
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> p.x >> p.y;
				grid[i][j]=p;
			}
		}
		
		int cnt=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(!vis[i][j]){
					cnt++;
					int tmp=dfs(j,i,cnt);
					if(tmp!=cnt)cnt--;	
				}
			}
		}

		cout << cnt-1 << endl;
	}

return 0;
}
