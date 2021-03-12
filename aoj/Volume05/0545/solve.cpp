#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int G[501][501],n,used[501];

int dfs(int v,int d){
	if(d>2)return 0;
	used[v]=1;
	int res=1;
	for(int i=0;i<=n;i++)if(G[v][i])res+=dfs(i,d+1);
	
	return res;
}

int main(void){
	
	int m;
	
	while(cin >> n >> m,n|m){
		fill(G[0],G[501],0);
		fill(used,used+501,0);
		
		for(int i=0;i<m;i++){
			int a,b;
			cin >> a >> b;
			G[a][b]=G[b][a]=1;
		}
		dfs(1,0);
		int sum=0;
		for(int i=0;i<501;i++)sum+=used[i];
		cout << sum-1 << endl;
	}
	return 0;
}
