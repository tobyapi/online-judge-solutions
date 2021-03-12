#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

#define MAX_N 20001
#define MAX_R 50001

using namespace std;

int par[MAX_N],rank[MAX_N];

void init_union_find(int n){
	for(int i=0;i<n;i++)
		par[i]=i,rank[i]=0;
}

int find(int x){
	if(par[x]==x)return x;
	else return par[x]=find(par[x]);
}

void unite(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	if(rank[x]<rank[y])par[x]=y;
	else{
		par[y]=x;
		if(rank[x]==rank[y])rank[x]++;
	}
}

bool same(int x,int y){
	return find(x)==find(y);
}

struct edge{int u,v,cost;};

bool comp(const edge& e1,const edge& e2){
	return e1.cost<e2.cost;
}

edge es[MAX_R];
int V,E;

int kruskal(){
	sort(es,es+E,comp);
	init_union_find(V);
	int res=0;
	for(int i=0;i<E;i++){
		edge e=es[i];
		if(!same(e.u,e.v)){
			unite(e.u,e.v);
			res+=e.cost;
		}
	}
	return res;
}

int main(void){

	int t,n,m,r;
	int x[MAX_R],y[MAX_R],d[MAX_R];
	
	cin >> t;
	
	while(t--){
		scanf("%d %d %d",&n,&m,&r);
		
		for(int i=0;i<r;i++){
			scanf("%d %d %d",&x[i],&y[i],&d[i]);
		}
		
		V=n+m;
		E=r;
		for(int i=0;i<r;i++){
			edge tmp;
			tmp.u=x[i];
			tmp.v=n+y[i];
			tmp.cost=-d[i];
			es[i]=tmp;
		}
		cout << 10000*(n+m)+kruskal() << endl;
	}

  return 0;
}