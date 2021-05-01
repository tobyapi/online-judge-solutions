#include<iostream>
#include<vector>
#include<algorithm>

#define all(c) (c).begin(),(c).end()

using namespace std;


vector<vector<int> > graph;
vector<bool> visited;

pair<int, int> dfs(int u, int cost){
  visited[u] = true;
  pair<int, int> res = pair<int,int>(cost,u);
  for(int i=0;i<graph[u].size();i++){
    int next = graph[u][i];
    if(visited[next])continue;
    pair<int, int> r = dfs(next, cost + 1);
    if(res.first < r.first)res = r;
  }
  return res;
}

int main(void) {
  int n;
  cin >> n;

  graph.resize(n);
  visited.resize(n);

  fill(all(graph), vector<int>());

  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    graph[a-1].push_back(b-1);
    graph[b-1].push_back(a-1);
  }

  fill(all(visited), false);
  pair<int,int> res = dfs(0, 0);
  fill(all(visited), false);
  pair<int,int> ans = dfs(res.second, 0);

  cout << ans.first + 1 << endl;

  return 0;
}