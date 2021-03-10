#include<iostream>
#include<algorithm>

using namespace std;

int a[10][10],b[10][10],ans[10][10];
int dx[]={1,0,-1,0,0},dy[]={0,1,0,-1,0};

void init(void){
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      b[i][j]=a[i][j];
      ans[i][j]=0;
    }
  }
}

void rev(int x, int y){
  for(int k=0;k<5;k++){

    int ny=y+dy[k],nx=x+dx[k];

    if( 0<=ny && 0<=nx && ny<10 && nx<10)
      b[ny][nx]=!b[ny][nx];
  }
}

int ok(void){
  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      if(b[i][j])return 0;
  return 1;
}

void solve(int p[]){
  init();

  for(int i=0;i<10;i++){
    if(p[i])rev(i,0);
    ans[0][i]=p[i];
  }
  for(int i=1;i<10;i++){
    for(int j=0;j<10;j++){
      if(b[i-1][j]){
	rev(j,i);
	ans[i][j]=1;
      }
    }
  }

  if(ok()){
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
	cout << ans[i][j];
	if(j<9)cout << " ";
      }
      cout << endl;
    }
  }
}

void func(int p[], int cnt){
  if(9<cnt)solve(p);
  else {
    p[cnt]=0;
    func(p,cnt+1);
    p[cnt]=1;
    func(p,cnt+1);
  }
}

int main(void){
  int n;

  cin >> n;

  while(n--){

    for(int i=0;i<10;i++)
      for(int j=0;j<10;j++)
	cin >> a[i][j];

    int p[10]={0};
    func(p,0);
  }

  return 0;
}
