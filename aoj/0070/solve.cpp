#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

#define all(c) (c).begin(),(c).end()

using namespace std;

int count(int bits){
  bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
  bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
  bits =(((bits >> 4) + bits) & 0x0f0f0f0f);
  bits += bits >> 8;
  return (bits + (bits >> 16)) & 0xff;
}

int dp[(1<<10)][1002];

int main(void){

  dp[0][0]=1;
  for(int S=0;S<(1<<10);S++){
    for(int i=0;i<10;i++){
      if(!(S>>i&1)){
        for(int s=0;s<1000;s++){
          if((count(S)+1)*i+s<1000)
          dp[S|(1<<i)][(count(S)+1)*i+s]+=dp[S][s];
        }
      }
    }
  }

  int n,s;

  while(cin >> n >> s){

    if(s>=1000){
      cout << 0 << endl;
      continue;
    }

    int ans=0;
    for(int i=0;i<(1<<10);i++)
      if(count(i)==n)ans+=dp[i][s];

    cout << ans << endl;
  }


  return 0;
}
