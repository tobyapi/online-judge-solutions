#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

#define INF 100000000
#define x first
#define y second
#define f first
#define s second

using namespace std;

typedef pair<int,int>P;
typedef pair<P,int>P3;

string grid[20];
int g[11][11],cost[21][21],h,w;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
vector<P>v;

void bfs(P st,int id){
	
	queue<P3>que;
	que.push(P3(st,0));
	while(!que.empty()){
		P3 now=que.front();
		que.pop();
		if(cost[now.f.y][now.f.x]<=now.s)continue;
		
		cost[now.f.y][now.f.x]=now.s;
	
		if(grid[now.f.y][now.f.x]=='*')
			for(int i=0;i<v.size();i++)
				if(v[i]==now.f)g[id][i]=now.s;
		
		for(int i=0;i<4;i++){
			int nx=now.f.x+dx[i],ny=now.f.y+dy[i];
			if(nx<0 || ny<0 || w<=nx || h<=ny || grid[ny][nx]=='x')continue;
			que.push(P3(P(nx,ny),now.s+1));
		}
	}
}

int main(void){
	
	while(cin >> w >> h,h|w){
		
		for(int i=0;i<h;i++)cin >> grid[i];
		fill(g[0],g[11],INF);
		v.clear();
		P st;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(grid[i][j]=='o')st.x=j,st.y=i,v.push_back(st);
				if(grid[i][j]=='*')v.push_back(P(j,i));
			}
		}
		
		for(int i=0;i<v.size();i++){
			fill(cost[0],cost[21],INF);
			bfs(v[i],i);
		}
		
		vector<P3>tmp;
		int stid;
		for(int i=0;i<v.size();i++){
			if(v[i]!=st)tmp.push_back(P3(v[i],i));
			else if(v[i]==st)stid=i;
		}
		
		sort(tmp.begin(),tmp.end());
		int ans=INF;
		do{
			int cnt=0;
			for(int i=0;i<tmp.size()-1;i++)cnt+=g[tmp[i].s][tmp[i+1].s];
			ans=min(ans,g[stid][tmp[0].s]+cnt);
		}while(next_permutation(tmp.begin(),tmp.end()));
		if(ans>=INF)cout << -1 << endl;
		else cout << ans << endl;
	}
	
	
	return 0;
}
