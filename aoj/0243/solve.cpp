#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int h,w,lim;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char g[11][11];
string s="RGB";

void rev(int x,int y,vector<int>&p,char ch){
  char tmp=g[y][x];
  g[y][x]=ch;
  p.push_back(y*w+x);

  for(int i=0;i<4;i++){
    int nx=x+dx[i],ny=y+dy[i];
    if(nx<0 || ny<0 || w<=nx || h<=ny || g[ny][nx]!=tmp)continue;
    rev(nx,ny,p,ch);
  }
}

bool dfs(int d){

  bool fg=true;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      fg&=(g[i][j]==g[0][0]);
    }
  }

  if(fg)return true;

  if(d>=lim)return false;

  for(int i=0;i<3;i++){
    if(g[0][0]==s[i])continue;
    char tmp=g[0][0];
    vector<int> p;
    rev(0,0,p,s[i]);
    if(dfs(d+1))return true;
    for(int j=0;j<p.size();j++){
      g[p[j]/w][p[j]%w]=tmp;
    }
  }
  return false;
}

int main(void){

  while(cin >> w >> h,w|h){

    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        cin >> g[i][j];
      }
    }

    for(lim=0;;lim++){
      if(dfs(0))break;
    }

    cout << lim << endl;

  }
  return 0;
}
