#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include <sstream>
 
using namespace std;
 
bool is_prime(int n){
 
  for(int i=2; i*i<=n; i++)
    if(n%i==0)return false;
  return true;
}
 
string toString(int a){
  ostringstream oss;
  oss << a;
  return oss.str();
}
 
int toInt(string s){
  istringstream iss(s);
  int a;
  iss >> a;
  return a;
}
 
int main(void){
  int n,c;
  string str="",C="";
 
  cin >> n >> c;
 
  for(int i=0;i<n;i++)str+="9";
   
  C=c+'0';
 
  if(c<0 && n>1){
    cout << str << str << endl;
    return 0;
  }

  while(true){
    string rstr=str;
    reverse(rstr.begin(),rstr.end());
     
    string res=str+C+rstr;
    int ans=toInt(res);
 
    if(is_prime(ans)){
      cout << ans << endl;
      return 0;
    }
    int tmp=toInt(str);
    tmp--;
    str=toString(tmp);
  }
  return 0;
}
