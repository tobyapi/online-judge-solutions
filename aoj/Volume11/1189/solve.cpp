#include <iostream>
#include <map>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
 
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
 
const int MAX = 1000001;
bool pri[MAX];
vector<int>v;
map<int,pair<int,int> >pos;
int field[1201][1201];
int N,M;
 
void make(){
  int cnt = 2;
  int c = 1;
  int x = 500,y=500;
  int cc = 0;
  field[500][500] = 1;
  pos[1] = make_pair(500,500);
 
  while(cnt < 1000000){
    for(int i=0; i<4; i++){
      if(cc == 2){cc = 0; c++;}
      int nx = x, ny = y;
      for(int j=0; j<c; j++){
    nx += dx[i];
    ny += dy[i];
    pos[cnt] = make_pair(ny,nx);
    field[ny][nx] = cnt++;
      }
 
      x = nx, y = ny;
      cc++;
    }
  }
}
 
void createPrime(){
  fill(pri,pri+MAX,1);
  pri[0] = pri[1] = 0;
  for(int i=2; i*i<MAX; i++){
    for(int j=2*i; j<MAX; j+=i){
      pri[j] = false;
    }
  }
 
  for(int i=2; i<MAX; i++) if(pri[i]) v.push_back(i);
}
 
bool compare(pair<int,int>p, pair<int,int>p2){
  if(p.first == p2.first){
    return p.second > p2.second;
  }
  return p.first > p2.first;
}
 
int main(){
  make();
  createPrime();
 
  while(cin >> M >> N,M|N){
    pair<int,int> p = pos[N];
    int sx = p.second, sy = p.first;
    bool F = false;
 
    static bool used[1200][1200];
    static pair<int,int> dp[1200][1200];
    memset(used,0,sizeof(used));
    memset(dp,0,sizeof(dp));
 
    if(binary_search(v.begin(),v.end(),field[sy][sx])){
      dp[sy][sx].first = 1;
      dp[sy][sx].second = field[sy][sx];
    }
    used[sy][sx] = true;
 
    for(int i=sy; i<=1000; i++){
      for(int j=0; j<=1000; j++){
    for(int k=-1; k<=1; k++){
      if(!used[i][j])continue;
      int nx = j + k;
      if(nx < 0 || nx > 1000)continue;
      if(field[i+1][nx] > M)continue;
 
      used[i+1][nx] = true;
      int value = binary_search(v.begin(),v.end(),field[i+1][nx]);
       
      if(value){
        if(dp[i+1][nx].first < dp[i][j].first + 1){
          dp[i+1][nx].first = dp[i][j].first + 1;
          dp[i+1][nx].second = field[i+1][nx];
        }
      } else {
        dp[i+1][nx] = max(dp[i+1][nx],dp[i][j]);
      }
    }
      }
    }
 
    vector<pair<int,int> >ans;
 
    for(int i=0; i<=1000; i++){
      for(int j=0; j<=1000; j++){
    if(field[i][j] > M)continue;
    if(dp[i][j].first == 0)continue;
    ans.push_back(dp[i][j]);
      }
    }
 
 
    if(ans.size() == 0){cout << "0 0" << endl;}
    else{
      sort(ans.begin(),ans.end(),compare);
      cout << ans[0].first << " " << ans[0].second << endl;
    }
 
  }
 
  return 0;
}
