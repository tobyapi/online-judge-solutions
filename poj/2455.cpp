#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>

#define MAX_V 201
#define INF (1LL<<60)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

struct edge{ll to,cap,rev;};

vector<edge> G[MAX_V];

void add_edge(ll from,ll to,ll cap){
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}

ll level[MAX_V],iter[MAX_V];

ll bfs(ll s){
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

ll dfs(ll v,ll t,ll f){
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

ll max_flow(ll s,ll t){
	ll flow=0;
	for(;;){
		bfs(s);
		if(level[t]<0)return flow;
		memset(iter, 0, sizeof(iter));
		ll f;
		while((f=dfs(s,t,INF))>0)flow+=f;
	}
}

int main(void){

	ll n,p,t;
	cin >> n >> p >> t;

	ll from[p],to[p],cost[p],mx=0;

	for(int i=0;i<p;i++){
		scanf("%lld %lld %lld",&from[i],&to[i],&cost[i]);
		from[i]--,to[i]--;
		mx=max(mx,cost[i]);
	}

	ll l=0,r=mx+1;
	while(r-l>1){
		ll m=(l+r)/2;

		for(int i=0;i<n;i++)G[i].clear();

		for(int i=0;i<p;i++){
			if(cost[i]<=m){
				add_edge(from[i],to[i],1LL);
				add_edge(to[i],from[i],1LL);
			}
		}
		if(max_flow(0,n-1)>=t)r=m;
		else l=m;
	}

	cout << r << endl;

	return 0;
}