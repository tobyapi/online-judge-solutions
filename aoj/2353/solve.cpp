#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
 
using namespace std;
 
typedef long long ll;
 
ll mod(ll x,ll m){
  return (m+x%m)%m;
}
 
void extgcd(ll a,ll b,ll &x,ll &y){
  x=1,y=0;
  if(b!=0)extgcd(b,a% b,y,x),y-=(a/b)*x; 
}
 
ll mod_inv(ll a,ll m){
  ll x,y;
  extgcd(a,m,x,y);
  return mod(x,m);
}
 
ll m1=999979,m2=999983;
 
ll solve(ll x,int o,ll y){
  ll a=0,b=0,p,q;
 
  if(o==1)a=x+y,b=x+y;
  if(o==2)a=x-y,b=x-y;
  if(o==3)a=x*y,b=x*y;
  if(o==4)a=x*mod_inv(y,m1),b=x*mod_inv(y,m2);
  a=mod(a,m1),b=mod(b,m2);
  extgcd(m1,m2,p,q);
   
  return (b*m1*p+a*m2*q)%(m1*m2);
}
 
int main(void){
  ll n,o,x=0,y;
 
  cin >> n;
 
  while(n--){
    cin >> o >> y;
    x=solve(x,o,y);
  }
  cout << x << endl;
  return 0;
}
