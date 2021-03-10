#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){

  int t;
  cin >> t;
  while(t--){
    int c,a,n;
    cin >> c >> a >> n;

    int ans=0;
    int tmp=min(min(c,a),n);
    ans+=tmp;
    c-=tmp,a-=tmp;

    ans+=min(c/2,a);
    c-=min(c/2,a)*2;
    ans+=c/3;
    cout << ans << endl;
  }

  return 0;
}
