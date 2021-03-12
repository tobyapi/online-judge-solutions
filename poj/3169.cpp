#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_V 1001
#define MAX_E 30000
#define INF (1<<29)

using namespace std;

struct edge{int from,to,cost;};

vector<edge> es;

int d[MAX_V],n;

void shortest_path(int s){
	for(int i=0;i<n;i++)d[i]=INF;
	d[s]=0;
	for(int k=0;k<n;k++){
		bool update=false;
		for(int i=0;i<es.size();i++){
			edge e=es[i];
			if(d[e.from]!=INF && d[e.to]>d[e.from]+e.cost){
				d[e.to]=d[e.from]+e.cost;
				update=true;
			}
		}
		if(!update)break;
	}
}

int main(void){

	int ml,md;
	cin >> n >> ml >> md;

	for(int i=0;i<n-1;i++){
		es.push_back((edge){i+1,i,0});
	}

	for(int i=0;i<ml;i++){
		int a,b,d;
		cin >> a >> b >> d;
		es.push_back((edge){a-1,b-1,d});
	}

	for(int i=0;i<md;i++){
		int a,b,d;
		cin >> a >> b >> d;
		es.push_back((edge){b-1,a-1,-d});
	}

	shortest_path(0);

	if(d[n-1]==INF)cout << -2 << endl;
	else if(d[0]<0)cout << -1 << endl;
	else cout << d[n-1] << endl;

	return 0;
}