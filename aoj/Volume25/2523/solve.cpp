#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;

string s;
int now,n,t;

ll pow(ll x){
  ll res=1;
  while(x--){
    res*=n;
    if(res>(ll)(1e9))return (ll)(1e9+1);
  }
  return res;
}

ll num(){return s[now++]-'0';}
ll mono(){now+=2; return pow(num());}
ll poly(){
  if(s.size()<=now)return 0;
  ll res=mono();
  now++;
  return min(res+poly(),(ll)(1e9+1));
}

int main(void){
  cin >> n >> t >> s;
  ll res=poly();

  if(res*t<=1e9)cout << res*t << endl;
  else cout << "TLE" << endl;
  return 0;
}
