#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void){
  string str;
  cin >> str;
  reverse(str.begin(),str.end());
  cout << str << endl;
  return 0;
}
