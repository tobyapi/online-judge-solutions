#include<iostream>

using namespace std;

int main(void){
  int n,m,h[201],r[201];

  while(cin >> n,n){
    for(int i=0;i<n;i++)cin >> h[i] >> r[i];
    cin >>m;
    for(int i=n;i<n+m;i++)cin >> h[i] >> r[i];

      for(int i=0;i<n+m;i++){
	  for(int j=i;j<n+m;j++){
	    int t;
	      if(h[i]>h[j]){
		  t=h[i];
		  h[i]=h[j];
		  h[j]=t;
		  t=r[i];
		  r [i]=r[j];
		  r[j]=t;
		}
	      if(h[i]==h[j] && r[i]>r[j]){
		  t=h[i];
		  h[i]=h[j];
		  h[j]=t;
		  t=r[i];
		  r [i]=r[j];
		  r[j]=t;
		}
	    }
	}

    int dp[201]={0};
    dp[0]=1;
    for(int i=0;i<n+m;i++){
      for(int j=i+1;j<n+m;j++){
	if(h[i]<h[j] && r[i]<r[j] && dp[i]>=dp[j])dp[j]=dp[i]+1;
      }
    }
    int res=0;
    for(int i=0;i<n+m;i++)res=max(res,dp[i]);
    cout << res << endl;
  }

  return 0;
}
