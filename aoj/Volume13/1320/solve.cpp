#include<iostream>
#include<vector>
#include<algorithm>
#define all(c) (c).begin(),(c).end()
#define INF (1<<29)

using namespace std;

typedef unsigned long long ull;

ull B=100000007;

int overlap(string a,string b){
  int al=a.size(),bl=b.size(),ans=0;
  ull ah=0,bh=0,t=1;
  for(int i=1;i<=min(al,bl);i++){
    ah+=a[al-i]*t;
    bh=bh*B+b[i-1];
    if(ah==bh)ans=i;
    t*=B;
  }
  return ans;
}

bool contain(string a,string b){
  int al=a.size(),bl=b.size();
  ull ah=0,bh=0,t=1;

  for(int i=0;i<al;i++)t*=B;
  for(int i=0;i<al;i++)ah=ah*B+a[i];
  for(int i=0;i<al;i++)bh=bh*B+b[i];

  for(int i=0;i+al<=bl;i++){
    if(ah==bh)return true;
    if(i+al<bl)bh=bh*B+b[i+al]-b[i]*t;
  }
  return false;
}


int dp[16][(1<<16)];

int main(void){

  int n;
  while(cin >> n,n){
    vector<string>a(n);
    int cnt=0;
    for(int i=0;i<n;i++)cin >> a[i];

    vector<string>b;
    for(int i=0;i<n;i++){
      bool fg=true;
      for(int j=0;j<n;j++)
        if(a[i].size()<a[j].size())fg&=!contain(a[i],a[j]);
      if(fg)b.push_back(a[i]);
    }

    int bl=b.size();
    fill(dp[0],dp[16],INF);
    for(int i=0;i<bl;i++)dp[i][(1<<i)]=b[i].size();

    for(int S=0;S<(1<<bl);S++){
      for(int i=0;i<bl;i++){
        if(!((S>>i)&1))continue;
        for(int j=0;j<bl;j++){
          if((S>>j)&1)continue;
          dp[j][S|(1<<j)]=min(dp[j][S|(1<<j)],dp[i][S]+(int)b[j].size()-overlap(b[i],b[j]));
        }
      }
    }
    int ans=INF;
    for(int i=0;i<bl;i++)ans=min(ans,dp[i][(1<<bl)-1]);
    cout << ans << endl;
  }
  return 0;
}
