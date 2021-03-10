#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

#define mp make_pair
#define f first
#define s second

using namespace std;

typedef pair<int,int> P;

const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int h,w;
string grid[1000];
int d[1000][1000];

void bfs(P S){

  queue<P>que;
  que.push(S);
  d[S.f][S.s]=0;

  while(!que.empty()){
    P now=que.front();
    
    que.pop();
    for(int i=0;i<4;i++){
      if(0<=now.f+dx[i] && 0<=now.s+dy[i] &&
	 now.f+dx[i]<h && now.s+dy[i]<w
	 && grid[now.f+dx[i]][now.s+dy[i]]!='X'){

	if(d[now.f][now.s]+1<d[now.f+dx[i]][now.s+dy[i]]){
	  d[now.f+dx[i]][now.s+dy[i]]=d[now.f][now.s]+1;
	  que.push(P(now.f+dx[i],now.s+dy[i]));
	}
      }
    }
  }
}

int main(void){
  int n;
  P v[1001];

  cin >> h >> w >> n;

  for(int i=0;i<h;i++)cin >> grid[i];

  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(grid[i][j]=='S')v[0]=mp(i,j);
      if(grid[i][j]!='X'&&grid[i][j]!='.')
	v[grid[i][j]-'0']=mp(i,j);
    }
  }

  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<h;j++)
      for(int k=0;k<w;k++)d[j][k]=100000000;
    bfs(v[i]);
    ans+=d[v[i+1].f][v[i+1].s];
  }

  cout << ans << endl;

  return 0;
}
