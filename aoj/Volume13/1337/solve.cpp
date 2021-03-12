#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>

#define F first
#define S second
#define X first
#define Y second
#define all(c) (c).begin(),(c).end()

using namespace std;

typedef pair<int,int>P;
typedef pair<P,P> P2;

int g[110][110];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(int x,int y,int c){
  g[y][x]=-1;
  for(int i=0;i<4;i++){
    int nx=x+dx[i],ny=y+dy[i];
    if(nx<0 || ny<0 || 110<=nx || 110<=y)continue;
    if(g[ny][nx]!=c)continue;
    dfs(nx,ny,c);
  }
}

int main(void){

  int n;
  while(cin >> n,n){
    vector<P2>v(n);
    vector<int>x,y;
    
    for(int i=0;i<n;i++){
      cin >> v[i].F.X >> v[i].F.Y >> v[i].S.X >> v[i].S.Y;
      x.push_back(v[i].F.X);
      x.push_back(v[i].S.X);
      y.push_back(v[i].F.Y);
      y.push_back(v[i].S.Y);
    }
    
    sort(all(x));
    sort(all(y));
    
    x.erase(unique(all(x)),x.end());
    y.erase(unique(all(y)),y.end());
    
    map<int,int>mpx,mpy;
    
    for(int i=0;i<x.size();i++)mpx[x[i]]=i+1;
    for(int i=0;i<y.size();i++)mpy[y[i]]=i+1;
    
    fill(g[0],g[110],0);
    
    for(int i=0;i<v.size();i++){
      for(int j=mpx[v[i].F.X];j<mpx[v[i].S.X];j++){
	for(int k=mpy[v[i].S.Y];k<mpy[v[i].F.Y];k++){
	  g[k][j]+=(i+1);
	}
      }
    }

    int cnt=0;
    for(int i=0;i<110;i++){
      for(int j=0;j<110;j++){
	if(g[i][j]>=0)dfs(j,i,g[i][j]),cnt++;
      }
    }
    
    cout << cnt << endl;
  }
  return 0;
}
