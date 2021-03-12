#include<iostream>

using namespace std;

int main(void){
  int d;

  while(cin >> d){
    int sum=0;
    for(int i=1;i<600/d;i++)
      sum+=i*i*d*d*d;
    
    cout << sum << endl;
  }

  return 0;
}
