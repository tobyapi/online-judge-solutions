#include<iostream>
#include<algorithm>
#include<vector>
#define A first
#define B second

using namespace std;

typedef pair<int,int> P;
int dp[102][4][3];

int main(void){
	
	int n,k;
	
	cin >> n >> k;
	
	vector<P>v(k);
	
	for(int i=0;i<k;i++)cin >> v[i].A >> v[i].B;
	sort(v.begin(),v.end());
	
	for(int i=1;i<4;i++)dp[1][i][1]=1;
	
	int p=0;
	for(int i=1;i<=n;i++){
		for(int k=1;k<4;k++){
			for(int l=1;l<3;l++){
				if(i==v[p].A){
					if(v[p].B==k && l<2)dp[i+1][k][l+1]+=dp[i][v[p].B][l]%10000;
					else if(v[p].B!=k)dp[i+1][k][1]+=dp[i][v[p].B][l]%10000;
					continue;
				}
				
				for(int j=1;j<4;j++){
					if(j==k && l<2)dp[i+1][k][l+1]+=dp[i][j][l]%10000;
					else if(j!=k)dp[i+1][k][1]+=dp[i][j][l]%10000;
				}
			}
		}
		if(v[p].A==i)p++;
	}
	
	int ans=0;
	if(n==v[p-1].A){
		for(int j=1;j<3;j++){
			ans+=dp[n][v[p-1].B][j];
			ans%=10000;
		}
	}
	else {
		for(int i=1;i<4;i++){
			for(int j=1;j<3;j++){
				ans+=dp[n][i][j];
				ans%=10000;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
