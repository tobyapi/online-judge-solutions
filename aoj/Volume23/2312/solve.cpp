#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;

using namespace std;

ll N,M,L,K[2001],sum[100001],dp[2001][2001];

ll func(ll l,ll r){

  if(dp[l][r]>0)return dp[l][r];

  ll n=max(l,r)+1;
  if(n==N)return (sum[K[n]]-sum[K[l]-1])/L+(sum[K[n]]-sum[K[r]-1])/L;

  ll lf=func(n,r)+(sum[K[n]]-sum[K[l]-1])/L;
  ll rt=func(l,n)+(sum[K[n]]-sum[K[r]-1])/L;

  return dp[l][r]=min(lf,rt);
}

int main(void){

  cin >> N >> M >> L;

  for(int i=1;i<=N;i++)cin >> K[i];
  
  sort(K+1,K+N+1);

  for(int i=1;i<=M;i++){
    cin >> sum[i];
    sum[i]+=sum[i-1];
  }

  cout << func(1,1) << endl;

  return 0;
}
