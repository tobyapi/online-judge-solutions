#include<iostream>
#include<vector>
#include<algorithm>

#define all(c) (c).begin(),(c).end()

using namespace std;

vector<int>w;

bool fg[2000000];

void sieve(void){
  w.clear();
  w.push_back(-1);

  fill(fg,fg+2000000,false);
  for(int i=2;i*i<2000000;i++){
    if(!fg[i]){
      w.push_back(i);
      for(int j=i*2;j<2000000;j+=i){
        fg[j]=true;
      }
    }
  }
}

int dp[20][300][1130];

int main(void){

  sieve();

  fill(*dp[0],*dp[20],0);
  dp[0][0][0]=1;

  int sz=(int)(upper_bound(all(w),1120)-w.begin());
  for(int i=0;i<15;i++){
    for(int j=0;j<sz;j++){
      for(int k=0;k<=1120;k++){
        for(int l=j+1;l<sz;l++){
          if(k+w[l]<=1120){
            dp[i+1][l][k+w[l]]+=dp[i][j][k];
          }
        }
      }
    }
  }

  int n,K;
  while(cin >> n >> K,n|K){

    int ans=0;
    for(int i=0;i<sz;i++)ans+=dp[K][i][n];

    cout << ans << endl;
  }

  return 0;
}
