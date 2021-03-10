#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,l,dp[100005],a[100005];

int func(int i){

  if(i>n)return 0;
  if(dp[i]>0)return dp[i];

  int res=0;
  if(a[i]<a[i-1])res=max(res,func(i-1));
  if(a[i]<a[i+1])res=max(res,func(i+1));

  return dp[i]=l-a[i]+res;
}

int main(void){
  
  while(cin >> n >> l){
    
    for(int i=0;i<n+2;i++)dp[i]=0;

    for(int i=1;i<n+1;i++)
      cin >> a[i];

    a[0]=a[n+1]=0;

    int res=0;
    for(int i=1;i<n+1;i++)
      res=max(res,func(i));

    cout << res << endl;
  }
  
  return 0;
}
