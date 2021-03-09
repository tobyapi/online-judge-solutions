#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
  int n, a[3];
  cin >> n;
  while(n--) {
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    if(a[0]*a[0] + a[1]*a[1] == a[2]*a[2]){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}