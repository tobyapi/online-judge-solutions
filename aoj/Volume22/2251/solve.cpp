#include<iostream>
#include<vector>
#include<algorithm>

#define INF 100000000

using namespace std;

int V,match[2001];
bool used[2001];
vector<int>G[2001];

void add_edge(int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}

bool dfs(int v){
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i],w=match[u];
		if(w<0 || !used[w] && dfs(w)){
			match[v]=u;
			match[u]=v;
			return true;
		}
	}
	return false;
}

int bitpartite_matching(){
	int res=0;
	fill(match,match+2001,-1);
	for(int v=0;v<V;v++){
		if(match[v]<0){
			fill(used,used+2001,false);
			if(dfs(v))res++;
		}
	}
	return res;
}

int main(void){
	
	int n,m,l,u,v,d,dist[101][101],p[1001],t[1001];
	
	while(cin >> n >> m >> l,n|m|l){
		for(int i=0;i<2001;i++)G[i].clear();
		
		fill(dist[0],dist[101],INF);
		
		for(int i=0;i<101;i++)dist[i][i]=0;
		for(int i=0;i<m;i++){
			cin >> u >> v >> d;
			dist[u][v]=dist[v][u]=d;
		}
		
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		
		for(int i=0;i<l;i++)cin >> p[i] >> t[i];
		
		for(int i=0;i<l;i++){
			for(int j=0;j<l;j++){
				if(i==j)continue;
				if(dist[p[i]][p[j]]+t[i]<=t[j])add_edge(i,j+l);
			}
		}
		V=2*l;
		cout << l-bitpartite_matching() << endl;
	}
	return 0;
}
