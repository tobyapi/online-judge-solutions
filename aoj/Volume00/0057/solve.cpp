#include<iostream>
#include<algorithm>

using namespace std;

int main(void){

  int n,m=2,ans[10001];

  fill(ans,ans+10001,0);
  ans[1]=2;

  for(int i=2;i<10001;i++)
    ans[i]=ans[i-1]+m++;
  
  while(cin >> n)cout << ans[n] << endl;

  return 0;
}
