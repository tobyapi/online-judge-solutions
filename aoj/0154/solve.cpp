#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(void){

	int m,g,n,a[8],b[8],dp[9][1001];
	
	while(cin >> m,m){
		
		fill(a,a+8,0);
		fill(b,b+8,0);
		
		for(int i=1;i<=m;i++){
			cin >> a[i] >> b[i];
		}
		
		fill(dp[0],dp[9],0);
		
		dp[0][0]=1;
		for(int i=0;i<=m;i++){
			for(int j=0;j<1001;j++){
				for(int k=0;k<=b[i];k++){
					if(j-k*a[i]>=0)dp[i+1][j]+=dp[i][j-k*a[i]];
				}
			}
		}

		cin >> g;
		while(g--){
			cin >> n;
			cout << dp[m+1][n] << endl;
		}
			
	}
	
return 0;
}
