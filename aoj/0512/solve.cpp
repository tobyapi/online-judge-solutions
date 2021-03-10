#include<iostream>
#include<string>

using namespace std;

int main(void){
  string s;

  while(cin >> s){
    string ans="";
    for(int i=0;i<s.size();i++){
      if(s[i]=='A')ans+='X';
      else if(s[i]=='B')ans+='Y';
      else if(s[i]=='C')ans+='Z';
      else ans+=s[i]-3;
    }
    cout << ans << endl;
  }

  return 0;
}
