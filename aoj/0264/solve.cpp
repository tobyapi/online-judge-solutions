#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<cstdlib>

using namespace std;
 
typedef long long ll;
  
ll expression();
ll term();
ll factor();
ll number();
  
int now;
string s;
ll P;
bool fg;
 
ll extgcd(ll a, ll b, ll& x, ll& y){
  ll d = a;
  if(b!=0){
    d=extgcd(b, a%b ,y,x);
    y-=(a/b)*x;
  }
  else{
    x=1; y=0;
  }
  return d;
}
 
ll mod_inverse(ll a,ll m){
  ll x,y;
  extgcd(a,m,x,y);
  return (m+x%m)%m;
}
 
ll expression(){
  if(fg)return 0;
    ll res=term();
        while(true){
      if(s[now]=='+')now++,(res+=term())%=P;
      else if(s[now]=='-')now++,(res+=P-term())%=P;
      else break;
    }
    return res;
}
 
ll term(){
  ll res=factor();
  while(true){
    if(s[now]=='(')res+=factor();
    else if(s[now]=='*')now++,(res*=factor())%=P;
    else if(s[now]=='/'){
      now++;
      ll tmp=factor();
      if(tmp==0)fg=true;
      res=((res%P)*mod_inverse(tmp,P)%P)%P;
    }
    else break;
  }
  return res;
}
 
ll factor(){
    ll res=0;
    if(s[now]=='('){
        now++;
        res=expression()%P;
        now++;
    }
    else return number();
      
    return res%P;
}
  
ll number(){
    ll res=0;
    while('0'<=s[now] && s[now]<='9'){
        res*=10;
        res+=s[now++]-'0';
    }
    return res%P;
}

int main(){
  string tmp;
  while(getline(cin,tmp)){
    if(tmp[0] == '0')break;

    for(int i=0;i<tmp.size();i++){
      if(tmp[i]==':'){
	tmp[i]=' ';
	break;
      }
    }

    now = 0;
    s.clear();
    stringstream ss;
    ss << tmp;
    ss >> tmp;
    P = (atol)(tmp.c_str());
    while(!(ss >> tmp).fail()){
      s += tmp;
    }
 
    fg = false;
    ll ans = expression();
    if(fg) cout << "NG" << endl;
    else  cout << s << " = " << ans << " (mod " << P << ")" << endl;
 
  }
 
  return 0;
}
