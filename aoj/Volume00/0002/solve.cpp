#include<iostream>

using namespace std;

int main(void){
  int a,b;

  while(cin >> a >> b){
    int sum=a+b,ans=1;
    for(; sum>=10 ; sum/=10,ans++);
    
    cout << ans << endl;;
  }
  return 0;
}
