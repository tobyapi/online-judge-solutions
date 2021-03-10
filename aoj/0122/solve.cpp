#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<pair<int,int> >sp;

int dx[12]={-1,0,1,2,2,2,1,0,-1,-2,-2,-2};
int dy[12]={-2,-2,-2,-1,0,1,2,2,2,1,0,-1};

int n;

bool dfs(int x,int y,int t){

	if(t>=0 && (abs(x-sp[t].first)>1 || abs(y-sp[t].second)>1))return false;
	if(t==n-1)return true;

	for(int i=0;i<12;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0 || ny<0 || 9<nx || 9<ny)continue;
		if(dfs(nx,ny,t+1))return true;
	}
	return false;
}

int main(void){

	int x,y;
	while(cin >> x >> y,x|y){
		cin >> n;
		sp.resize(n);
		for(int i=0;i<n;i++)cin >> sp[i].first >> sp[i].second;
		if(dfs(x,y,-1))cout << "OK" << endl;
		else cout << "NA" << endl;
	}

	return 0;
}
