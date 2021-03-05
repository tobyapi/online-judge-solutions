#include<iostream>
#include<string>

using namespace std;

int main(void){
  int a, b;
  while(cin >> a >> b){
    cout << to_string(a+b).size() << endl;
  }
  return 0;
}