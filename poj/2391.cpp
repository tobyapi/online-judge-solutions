#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>
#define MAX_V 405
#define INF (1LL<<60)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

struct edge{ll to,cap,rev;};

vector<edge>G[MAX_V];

inline void add_edge(ll from,ll to,ll cap){
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}

ll level[MAX_V],iter[MAX_V];

inline ll bfs(ll s){
	memset(level, -1, sizeof(level));
	queue<ll>que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		ll v=que.front();
		que.pop();
		int sz=G[v].size();
		for(int i=0;i<sz;i++){
			edge &e=G[v][i];
			if(e.cap>0 && level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}

inline ll dfs(ll v,ll t,ll f){
	if(v==t)return f;
	int sz=G[v].size();
	for(ll &i=iter[v];i<sz;i++){
		edge &e=G[v][i];
		if(e.cap>0 && level[v]<level[e.to]){
			ll d=dfs(e.to,t,min(e.cap,f));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

inline ll max_flow(ll s,ll t,ll lim){
	ll flow=0;
	for(;;){
		bfs(s);
		if(level[t]<0)return flow;
		memset(iter, 0, sizeof(iter));
		ll f;
		while((f=dfs(s,t,INF))>0)flow+=f;
	}
}

ll wf[MAX_V][MAX_V];

int main(void){

	ll n,m,sum=0;
	cin >> n >> m;

	vector<pll>v(n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&v[i].first,&v[i].second);
		sum+=v[i].first;
	}

	fill(wf[0],wf[MAX_V],INF);
	for(int i=0;i<MAX_V;i++)wf[i][i]=0;

	ll s=2*n,t=s+1;
	vector<pll>sp(m);
	vector<ll>p(m);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&sp[i].first,&sp[i].second,&p[i]);
		sp[i].first--,sp[i].second--;
		ll tmp=min(wf[sp[i].first][sp[i].second],p[i]);
		wf[sp[i].first][sp[i].second]=tmp;
		wf[sp[i].second][sp[i].first]=tmp;
	}

	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				wf[i][j]=min(wf[i][j],wf[i][k]+wf[k][j]);
			}
		}
	}

	ll l=0,r=INF;
	while(r-l>1){

		ll mid=(l+r)/2;

		for(int i=0;i<=t;i++)G[i].clear();

		for(int i=0;i<n;i++){
			add_edge(s,i,v[i].first);
			add_edge(i+n,t,v[i].second);

			for(int j=0;j<n;j++){
				if(mid>=wf[i][j])add_edge(i,j+n,sum);
			}
		}

		if(max_flow(s,t,mid)==sum)r=mid;
		else l=mid;
	}

	if(r==INF)cout << -1 << endl;
	else cout << r << endl;

	return 0;
}