#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){

  int ans=0,a;

  for(int i=0;i<5;i++){
    cin >> a;
    ans+=max(40,a);
  }

  cout << ans/5 << endl;

  return 0;
}
