#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<map>

#define foreach(it, c) for(__typeof__((c).begin()) it=(c).begin();it!=(c).end();it++)

using namespace std;

typedef unsigned int uint;
typedef pair<int, uint> P;

uint encode(vector<int> vec){
    uint res=0;
    for (int i=0;i<vec.size();i++)
        res=(res<<4)+vec[i];
 
    return res;
}
 
vector<int> decode(uint a){
    vector<int> res;
    for (;a>0;a>>=4)res.push_back(a & 15);
	reverse(res.begin(),res.end());
	
    return res;
}
 
struct edge{uint to, cost; };
 
int V;
int c[10][10],ans;
map<uint,int>d;
 
void dijkstra(uint s){
  priority_queue<P, vector<P>, greater<P> >que;
  d[s] = 0;
  que.push(P(0, s));
 
  while(!que.empty()){
 
    P p = que.top();
    que.pop();
    uint v = p.second;
    if(d[v] < p.first)continue;

    vector<int>tmp=decode(v);
  
    for(int i=0;i<V;i++){
      for(int j=i+1;j<V;j++){
			edge e;
			e.cost=c[tmp[i]][tmp[j]];
			swap(tmp[i],tmp[j]);
			e.to=encode(tmp);
 
      	if(!d.count(e.to) || d[e.to] > d[v]+e.cost){
      		d[e.to] = d[v]+e.cost;
      		que.push(P(d[e.to], e.to));
    	}
    	swap(tmp[i],tmp[j]);
      }
    }
  }
}
 
 
int main(void){
 
  cin >> V;
 
  for(int i=1;i<=V;i++){
    for(int j=1;j<=V;j++){
      cin >> c[i][j];
    } 
  }
	
  vector<int>v;
  for(int i=1;i<=V;i++)v.push_back(i);
 
  uint s=encode(v);
 
  dijkstra(s);
 
  ans=0;
  foreach(i,d)ans=max(ans,i->second);
  cout << ans << endl;
 
  return 0;
}
