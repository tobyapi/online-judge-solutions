#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string solve(string a, string b){
  string res="";
  for(int i=0;i<a.size();i++){
    if(a[i]==b[i])res+='0';
    else res+='1';
  }
  return res;
}

int main(void){

  int n,x;
  string s[10]={
    "0111111",
    "0000110",
    "1011011",
    "1001111",
    "1100110",
    "1101101",
    "1111101",
    "0100111",
    "1111111",
    "1101111"
  };


  string a,b;
  while(cin >> n,~n){

    cin >> x;
    cout << s[x] << endl;
    a = s[x];
    n--; 

    while(n--){
      cin >> x;
      b=s[x];
      string ans=solve(a,b);
      cout << ans << endl;
      a=b;
    }
  }

  return 0;
}
