#include<iostream>
#include<string>
#include<algorithm>
#include <sstream>

using namespace std;

string func(string);
string itos(int);

int main(void){
  int n;
  string in;

  while(cin >> n,n){
  cin.ignore();
  cin >> in;

  while(n--)
    in=func(in);

  cout << in << endl;
  }
  return 0;
}

string func(string s){
  int cnt=1,i;
  string ans;
  for(i=1;i<s.size();i++){
    if(s[i]==s[i-1])cnt++;
    else {
      ans+=itos(cnt);
      ans+=s[i-1];
      cnt=1;
    }
  }
  ans+=itos(cnt);
  ans+=s[i-1];

  return ans;
}

string itos( int i ) {
  ostringstream s ;
  s << i ;
  return s.str() ;
}
