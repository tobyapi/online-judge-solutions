#include<iostream>
#include<algorithm>

using namespace std;

int n,a[101][101],sum[101][101];

int main(void){
	
	cin >> n;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)cin >> a[i][j];

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];

	int ans=-10000000;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=i;k++)
				for(int l=1;l<=j;l++)
					ans=max(ans,sum[i][j]-sum[k-1][j]-sum[i][l-1]+sum[k-1][l-1]);

	cout << ans << endl;

	return 0;
}
