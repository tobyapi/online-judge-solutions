#include<iostream>
#include<string>
#include<vector>

using namespace std;

int toInt(string s){
  int res=0;
  for(int i=0;i<s.size();i++){
    res*=10;
    res+=s[i]-'0';
  }
  return res;
}

int main(void){

  string s;
  cin >> s;
  
  int cnt=0,n=toInt(s);
  for(int i=0;i<s.size();i++){
    if(s[i]=='0')continue;
    int a=toInt(s.substr(0,i));
    int b=toInt(s.substr(i,s.size()-i));
    if(a>b)break;
    if((a+b)%2==0 && (b-a)%2==0)cnt++;
  }

  cout << cnt << endl;
  
  return 0;
}
