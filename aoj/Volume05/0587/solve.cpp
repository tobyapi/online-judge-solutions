#include<iostream>
#include<algorithm>

using namespace std;

int main(void){

  int n,cnt,in,out,mx;

  cin >> n >> cnt;
  mx=cnt;
  while(n--){
    cin >> in >> out;
    cnt+=in-out;
    mx=max(mx,cnt);

    if(cnt<0){
      cout << 0 << endl;
      return 0;
    }
  }
  cout << mx << endl;

  return 0;
}
