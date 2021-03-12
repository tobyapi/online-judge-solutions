#include<iostream>

using namespace std;

int main(void){
  int n,a=100000;

  cin >> n;
  while(n--){
    a=a*5/100+a;
    if(a%1000){
      a/=1000;
      a=a*1000+1000;
    }
  }
  cout << a << endl;

  return 0;
}
