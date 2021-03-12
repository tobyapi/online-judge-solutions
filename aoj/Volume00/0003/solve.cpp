#include<iostream>

using namespace std;

int main(void){
  int n,a,b,c;

  cin >> n;
  while(n--){
    cin >> a >> b >> c;
    if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
