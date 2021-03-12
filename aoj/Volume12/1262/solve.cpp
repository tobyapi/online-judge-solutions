#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<cstdio>
#define INF 1<<29
#define all(c) (c).begin(),(c).end()

using namespace std;

int main(void){

  int n;
  while(cin >> n,n){
    vector<int>a(n+1);
    a[0]=0;
    for(int i=1;i<=n;i++)cin >> a[i];
    double b,r,v,e,f;
    cin >> b >> r >> v >> e >> f;

    double time[10001];
    time[0]=0;
    for(int i=0;i<10001;i++){
      if(i>=r)time[i+1]=1/(v-e*(i-r))+time[i];
      else time[i+1]=1/(v-f*(r-i))+time[i];
    }
    double dp[101];
    fill(dp,dp+101,INF);
    dp[0]=0;
    for(int i=0;i<n;i++)
      for(int j=i+1;j<=n;j++)
	dp[j]=min(dp[j],dp[i]+time[a[j]-a[i]]+(i>0)*b);

    printf("%.4f",dp[n]);
    cout << endl;
  }
  return 0;
}
