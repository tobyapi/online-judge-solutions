#include<iostream>

using namespace std;

int main(void){
  int n,x;

  while(cin >> n,n){
    int sum=0;
    for(int i=0;i<n/4;i++)cin >> x,sum+=x;
    cout << sum << endl;
  }
  return 0;
}
