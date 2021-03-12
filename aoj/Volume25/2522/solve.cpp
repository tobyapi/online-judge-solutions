#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>
#include<cstring>

using namespace std;

int main(void){

  string s;
  cin >> s;

  if(s.size()<6){
    cout << "INVALID" << endl;
    return 0;
  }

  bool num=false,low=false,up=false;
  for(int i=0;i<s.size();i++){
    num|=isdigit(s[i]);
    low|=islower(s[i]);
    up|=isupper(s[i]);
  }

  if(!num || !low || !up){
    cout << "INVALID" << endl;
    return 0;
  }

  cout << "VALID" << endl;

  return 0;
}
