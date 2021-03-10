#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[2][1<<20];

int main(void){

	int n;
	cin >> n;
	for(int tc=1;tc<=n;tc++){
		int h,w;
		cin >> w >> h;

		int r[20][20];
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)cin >> r[i][j];

		fill(dp[0],dp[2],0);
		for(int i=0;i<h*w;i++){
			for (int j=0;j<(1<<w);j++)dp[(i+1)&1][j]=0;
			for(int S=0;S<(1<<w);S++){
				int x=i%w,y=i/w,nx=(S<<1)&((1<<w)-1);
				if((x==0 && (S>>(w-1)&1)) || (y==0 && (S&1)) || (x!=0 && y!=0 && ((S&1) || (S>>(w-1)&1)))){
					dp[(i+1)&1][nx]=max(dp[(i+1)&1][nx],dp[i&1][S]);
				}
				else {	
					dp[(i+1)&1][nx]=max(dp[(i+1)&1][nx],dp[i&1][S]);					
					dp[(i+1)&1][nx|1]=max(dp[(i+1)&1][nx|1],dp[i&1][S]+r[y][x]);
				}
			}
		}
		int ans=0;
		for(int i=0;i<(1<<w);i++)ans=max(ans,dp[(h*w)&1][i]);
		cout << "Case " << tc << ": " << ans << endl;
	}
	return 0;
}
