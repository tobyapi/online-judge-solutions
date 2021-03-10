#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int>pii;

int dp1[101][301],dp2[101][301];

int main(void){

	int s,d,m;
	while(cin >> s >> d >> m){
		vector<pii>a[s];
		for(int i=0;i<s;i++){
			int w,p,k;
			cin >> k;
			for(int j=0;j<k;j++){
				cin >> w >> p;
				a[i].push_back(pii(p,w));
			}
		}

		vector<int>f(d);
		for(int i=0;i<d;i++)cin >> f[i];

		fill(dp1[0],dp1[101],0);

		for(int i=0;i<s;i++){
			for(int j=0;j<a[i].size();j++){
				for(int k=300;k>=0;k--){
					if(k+a[i][j].first<=300){
						dp1[i][k+a[i][j].first]=
							max(dp1[i][k+a[i][j].first],dp1[i][k]+a[i][j].second);
					}
				}
			}
		}

		fill(dp2[0],dp2[101],0);
		for(int i=0;i<d;i++){
			for(int j=0;j<=m;j++){
				for(int k=0;k<=m;k++){
					if(j+k<=300)dp2[i+1][j+k]=max(dp2[i+1][j+k],dp2[i][j]+dp1[f[i]][k]);
				}
			}
		}

		int minp=(1<<29),maxw=-1;
		for(int j=0;j<=m;j++){
			for(int i=0;i<=d;i++){
				if(maxw<dp2[i][j]){
					maxw=dp2[i][j];
					minp=j;
				}
			}
		}
		
		cout << maxw << " " << minp << endl;
	}
	return 0;
}
