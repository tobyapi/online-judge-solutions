#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;

using namespace std;

ll gcd(ll a,ll b){
  if(b==0)return a;
  return gcd(b, a%b);
}

ll lcm(ll a,ll b){
  return a*b/gcd(a,b);
}

ll lcm_n(vector<ll> num){
  ll l=num[0];
  for(int i=0;i<num.size();i++)l=lcm(l,num[i]);
  return l;
}

ll func(ll a, ll m){
  ll cnt=1,x=a%m;
  while(x!=1)x=(a*x)%m,cnt++;
  return cnt;
}

int main(void){

  ll m[4],a[4];

  while(true){

    int b=0;
    for(int i=1;i<4;i++){
      cin >> a[i] >> m[i];
      b|=a[i]|m[i];
    }
    if(!b)break;
    
    ll cnt=0,x=1,y=1,z=1;
    vector<ll>num;

    for(int i=1;i<4;i++)
    num.push_back(func(a[i],m[i]));

    cout << lcm_n(num) << endl;
  }

  return 0;
}
