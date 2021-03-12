#include<iostream>
#include<cmath>

using namespace std;

int main(void){

  int n;
  while(cin >> n){
    if(n%2)cout << (int)(2*pow(3,n/2)-1) << endl;
    else cout << (int)((2*pow(3,(n-1)/2)-1)/2*3+1) << endl;
  }
  return 0;
}
