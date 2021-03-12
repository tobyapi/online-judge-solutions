#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<map>
#include<set>
#include<string>

#define pb push_back
#define all(a) (a).begin(),(a).end()

#define MAX_V 6000
#define INF (1<<29)

using namespace std;

struct edge{
  int to,cost;
  edge(int to,int cost):to(to),cost(cost){}
};

struct State{
  int d,c,id;
  State(int d,int c,int id):d(d),c(c),id(id){}
  bool operator < (const State &p)const{
    return d>p.d;
  }
};

vector<edge>G[MAX_V];
set<int>st;
int mincost[MAX_V][2001];

int dijkstra(int s,int g,int cap){

  priority_queue<State>que;
  que.push(State(0,cap*10,s));
  fill(mincost[0],mincost[MAX_V],INF);

  while(!que.empty()){
    State now=que.top();
    que.pop();

    if(now.id==g)return now.d;
    if(st.count(now.id))now.c=cap*10;
    if(mincost[now.id][now.c]<=now.d)continue;
    mincost[now.id][now.c]=now.d;

    for(int i=0;i<G[now.id].size();i++){
      int c=G[now.id][i].cost;
      int next=G[now.id][i].to;
      if(now.c<c)continue;
      int idx=(st.count(next)?cap*10:now.c-c);
      for(int j=0;j<=now.c-c;j++)
        mincost[next][j]=min(mincost[next][j],mincost[next][idx]);
      que.push(State(now.d+c,now.c-c,next));
    }
  }
  return -1;
}

vector<string>from,to;
vector<int>cost;
map<string,int>id;
set<string>v;

int main(void){

  int n,m,c;
  while(cin >> n >> m >> c,n|m|c){

    string s,dst,f,t;
    v.clear(),from.clear(),to.clear();
    cost.clear(),id.clear();
    int in;

    cin >> s >> dst;
    v.insert(s),v.insert(dst);

    for(int i=0;i<n;i++){
      cin >> f >> t >> in;
      from.pb(f),to.pb(t),cost.pb(in);
      v.insert(f),v.insert(t);
    }

    for(int i=0;i<MAX_V;i++)G[i].clear();

    set<string>::iterator it=v.begin();
    for(int j=0;it!=v.end();it++,j++)id[*it]=j;

    for(int i=0;i<n;i++){
      G[id[from[i]]].pb(edge(id[to[i]],cost[i]));
      G[id[to[i]]].pb(edge(id[from[i]],cost[i]));
    }

    string a;
    st.clear();
    for(int i=0;i<m;i++){
      cin >> a;
      if(id.count(a))st.insert(id[a]);
    }

    cout << dijkstra(id[s],id[dst],c) << endl;
  }

  return 0;
}
