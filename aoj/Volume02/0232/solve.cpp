#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

struct M{int e,a;};

int main(void){
	
	int x,y,z,n;
	double dp[51][5001];
	M in;
	map<int,M>m;
	
	while(cin >> x >> y >> z,x|y|z){
		vector<int>v(x);
		m.clear();
		
		for(int i=0;i<x;i++)cin >> v[i];
		for(int i=0;i<z;i++){
			cin >> n >> in.e >> in.a;
			m[n]=in;
		}
		
		fill(dp[0],dp[51],0);
		dp[0][0]=1;
		
		for(int i=0;i<y;i++){
			for(int j=0;j<5001;j++){
				for(int k=0;k<x;k++){
					int nx=i+v[k];
					if(m[nx].e==1)dp[min(y,nx+m[nx].a)][j]+=dp[i][j]/x;
					else if(m[nx].e==2)dp[nx][j+m[nx].a]+=dp[i][j]/x;
					else if(m[nx].e==3)dp[nx][max(0,j-m[nx].a)]+=dp[i][j]/x;
					else dp[min(y,nx)][j]+=dp[i][j]/x;
				}
			}
		}
		double ans=0;
		for(int j=0;j<5001;j++)ans+=dp[y][j]*j;
		
		cout << (int)ans << endl;
	}
	
return 0;
}
