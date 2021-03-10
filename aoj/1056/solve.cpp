#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(void){
  int n;
  double dp[100001]={0},p,w;
  
  dp[1]=1;

  for(int i=2;i<100001;i++){
    p=1;
    w=0.5;
    for(int j=1; j<i && 0.00000000001<p; j++){
      dp[i]+=p*(1-w)*(j+dp[i-j-1]);
      p*=w;
      w/=2;
    }
    dp[i]+=i*p;
  }

  while(cin >> n,n)
    printf("%.8f\n",dp[n]);

  return 0;
}
