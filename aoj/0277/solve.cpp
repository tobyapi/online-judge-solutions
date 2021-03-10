#include<iostream>
#include<algorithm>

using namespace std;

int a[4]={6000,4000,3000,2000};

int main(void){

  int t,n;
  while(cin >> t >> n){
    cout << a[t-1]*n << endl;
  }
  return 0;
}
