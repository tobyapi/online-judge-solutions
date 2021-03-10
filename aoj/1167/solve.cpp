#include<iostream>
#include<vector>
#include<algorithm>

#define INF 10000000

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(void){
	
	static int dp1[1000001],dp2[1000001],n,four[501];
	
	fill(four,four+501,0);
	fill(dp1,dp1+1000001,INF);
	fill(dp2,dp2+1000001,INF);
	
	rep(i,501)four[i]=i*(i+1)*(i+2)/6;
	
	dp1[0]=dp2[0]=0;
	
	for(int i=1;i<1000001;i++){
		for(int j=1;four[j]<=i;j++){
			dp1[i]=min(dp1[i],dp1[i-four[j]]+1);
			if(four[j]%2)dp2[i]=min(dp2[i],dp2[i-four[j]]+1);
		}
	}
	
	while(cin >> n,n)cout << dp1[n] << " " << dp2[n] << endl;
	
	
	return 0;
}
