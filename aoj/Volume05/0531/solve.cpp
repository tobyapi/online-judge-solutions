#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int N,H,W;
int X1[1000],X2[1000],Y1[1000],Y2[1000];
int fld[2002][2002],dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

int compress(int *x1,int *x2,int w){
  vector<int>xs;

  for(int i=0;i<N;i++){
      int tx1=x1[i],tx2=x2[i];
      if(1<=tx1 && tx1<w)xs.push_back(tx1);
      if(1<=tx2 && tx2<w)xs.push_back(tx2);
  }
  xs.push_back(0);
  xs.push_back(w);
  sort(xs.begin(),xs.end());
  xs.erase(unique(xs.begin(),xs.end()),xs.end());
  for(int i=0;i<N;i++){
    x1[i]=find(xs.begin(),xs.end(),x1[i])-xs.begin();
    x2[i]=find(xs.begin(),xs.end(),x2[i])-xs.begin();
  }
  return xs.size()-1;
}

int bfs(void){

  int ans=0;

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(fld[i][j])continue;
      ans++;
      queue<pair<int,int> >que;
      que.push(make_pair(j,i));
      while(!que.empty()){
	int nx=que.front().first,ny=que.front().second;
	que.pop();

	for(int i=0;i<4;i++){
	  int tx=nx+dx[i],ty=ny+dy[i];
	  if(tx<0 || W<tx || ty<0 || H<ty || fld[ty][tx]>0)continue;
	  que.push(make_pair(tx,ty));
	  fld[ty][tx]=1;
	}
      }
    }
  }
  return ans;
}

int main(void){

  while(cin >> W >> H,W|H){
    cin >> N;
    for(int i=0;i<N;i++)
      cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
    
    fill(fld[0],fld[2002],0);
    
    W=compress(X1,X2,W);
    H=compress(Y1,Y2,H);
    
    for(int i=0;i<N;i++){
      fld[Y1[i]][X1[i]]++;
      fld[Y1[i]][X2[i]]--;
      fld[Y2[i]][X1[i]]--;
      fld[Y2[i]][X2[i]]++;
    }
    
    for(int i=0;i<H;i++){
      for(int j=1;j<W;j++){
	fld[i][j]+=fld[i][j-1];      
      }
    }
    
    for(int i=1;i<H;i++){
      for(int j=0;j<W;j++){
	fld[i][j]+=fld[i-1][j];
      }
    }
    cout << bfs() << endl;
  }
  return 0;
}
