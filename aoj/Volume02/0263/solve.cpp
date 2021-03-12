#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int a[30],b[30],dp[31][1<<16];

int count(int bits){
  bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
  bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
  bits =(((bits >> 4) + bits) & 0x0f0f0f0f);
  bits += bits >> 8;
  return (bits + (bits >> 16)) & 0xff;
}

int main(void){
  
  int n,c,in;
  
  while(cin >> n >> c,n|c){
    
    fill(a,a+n,0);
    fill(b,b+c,0);

    for(int i=0;i<n;i++){
      for(int j=0;j<16;j++){
	cin >> in;
	a[i] |= in<<(15-j);
      }
    }

    for(int i=0;i<c;i++){
      for(int j=0;j<16;j++){
	cin >> in;
	b[i] |= in<<15-j;
      }
    }

    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;

    for(int i=0;i<n;i++){
      for(int j=0;j<(1<<16);j++){
	if(dp[i][j]<0)continue;

	int now=a[i]|j;
	for(int k=0;k<c;k++){
	  int next=now & ~b[k];
	  dp[i+1][next]=max(dp[i+1][next],dp[i][j]+count(now & b[k]));
	}
      }
    }

    int ans=0;
    for(int i=0;i<(1<<16);i++){
      ans=max(ans,dp[n][i]);
    }
    cout << ans << endl;
  }

  return 0;
}
