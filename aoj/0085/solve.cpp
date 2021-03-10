#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
  int a[1001],n,m;

  while(cin >> n >> m,n|m){
    fill(a,a+n+1,0);
    int cnt=0,now=1,fg=0;
    while(true){
      for(int i=1;i<=n;i++){
	if(a[i])continue;
	if(cnt==n-1){
	  for(int j=1;j<=n;j++)
	    if(a[j]==0)cout << j << endl;
	  fg=1;
	  break;
	}
	if(now==m)a[i]=1,cnt++,now=0;
	now++;
      }
      if(fg)break;
    }
  }
  return 0;
}
