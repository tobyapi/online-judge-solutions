#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


int main(void){

  int N,K;
  cin >> N >> K;

  vector<int>b[K];

  for(int i=0;i<K;i++){
    int m;
    cin >> m;
    b[i].resize(m);
    for(int j=0;j<m;j++)cin >> b[i][j];
  }

  int R;
  cin >> R;
  bool B[N+1];
  fill(B,B+N+1,false);
  int p,q;
  for(int i=0;i<R;i++){
    cin >> p >> q;
    for(int j=0;j<K;j++){
      bool fg1=false,fg2=false;
      for(int k=0;k<b[j].size();k++){
        if(b[j][k]==p)fg1=true;
        if(b[j][k]==q)fg2=true;
      }
      if(fg1 && fg2)B[p]=B[q]=true;
    }
  }

  int ans=0;
  for(int i=0;i<=N;i++)ans+=B[i];

  cout << ans << endl;


  return 0;
}
