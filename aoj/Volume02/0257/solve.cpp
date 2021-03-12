#include<iostream>
#include<string>
using namespace std;
main(){
  string s;
  getline(cin,s);
  if(s=="1 1 0"||s=="0 0 1")cout << "Open\n";
  else cout << "Close\n";
}
