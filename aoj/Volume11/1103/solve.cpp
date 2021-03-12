#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int dx[4],dy[4];
bool used[4][4];

int rec(int d){

  if(d>=8)return 1;  

  int tmpx=-1,tmpy=-1;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if(!used[i][j]){
	tmpx=j,tmpy=i;
	goto end;
      }
    }
  }
 end:;

  if(tmpx<0 || tmpy<0)return 0;
  used[tmpy][tmpx]=true;

  int res=0;
  for(int i=0;i<4;i++){
    int nx=tmpx+dx[i],ny=tmpy+dy[i];
    if(nx<0 || ny<0 || 3<nx || 3<ny || used[ny][nx])continue;
    used[ny][nx]=true;
    res+=rec(d+1);
    used[ny][nx]=false;
  }
  used[tmpy][tmpx]=false;
  return res;
}

int main(void){
  
  while(true){
    for(int i=0;i<4;i++){
      cin >> dx[i];
      if(dx[i]>4)return 0;
      cin >> dy[i];
    }
    fill(used[0],used[4],false);
    cout << rec(0) << endl;
  }
  
  return 0;
}
