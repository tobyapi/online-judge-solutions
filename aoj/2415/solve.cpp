#include<iostream>
#include<vector>
#include<algorithm>
#define INF (1LL<<61)

using namespace std;

typedef unsigned long long ull;

int main(void){
	
	int n;
	cin >> n;
	
	ull cost[4001];
	for(int i=0;i<n;i++){
		cin >> cost[i];
		if(i>0)cost[i]+=cost[i-1];
	}
	
	static ull dp[4001][4001],k[4001][4001];
	fill(dp[0],dp[4001],INF);
	
	for(int i=0;i<n;i++)dp[i][i]=0,k[i][i]=i;
	
	for(int w=1;w<=n;w++){
		for(int i=0,j=i+w;j<n;i++,j++){
			for(int r=k[i][j-1];r<=k[i+1][j];r++){
				ull c=dp[i][r]+dp[r+1][j]+cost[j]-((i>0)?cost[i-1]:0);
				if(dp[i][j]>c)dp[i][j]=c,k[i][j]=r;
			}
		}
	}
	cout << dp[0][n-1] << endl;
	
	return 0;
}
