#include<iostream>
#define rep(i,n) for((i)=0;(i)<(n);i++)

using namespace std;

int v[3],n,c;
string s;

int f(){
  n++;
  int r;
  if(s[n-1]=='(')r=f(),n++,r=s[n-1]=='+'?max(r,f()):min(r,f()),n++;
  else if(s[n-1]=='-')r=2-f();
  else if(s[n-1]-'P'>=0)r=v[s[n-1]-'P'];
  else r=s[n-1]-'0';
  return r;
}

int main(){ 
  cin >> s;
  if(s!="."){
    c=0;
    rep(v[0],3)rep(v[1],3)rep(v[2],3)n=0,c+=f()/2;
    cout << c << endl;
    main();
  }
}
