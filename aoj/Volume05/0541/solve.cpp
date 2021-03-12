#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
	
	static int h,w,n,grid[1002][1002],dp[1002][1002];

	while(cin >> h >> w >> n,h|w|n){
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++)
				cin >> grid[i][j];
		
		fill(dp[0],dp[1002],0);
		dp[1][1]=n-1;
		
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				dp[i][j+1]+=(dp[i][j]+grid[i][j])>>1;
				dp[i+1][j]+=(dp[i][j]+!grid[i][j])>>1;
			}
		}
		
		for(int i=1;i<=h;i++){
			for(int j=0;j<=w;j++){
				if(dp[i][j]%2)grid[i][j]^=dp[i][j]&1;
			}
		}
		
		int x=1,y=1;
		while(true){
			if(y>h || x>w)break;
			if(grid[y][x])x++;
			else y++;
		}
		
		cout << y << " " << x << endl;
		
	}
	
	return 0;
}
