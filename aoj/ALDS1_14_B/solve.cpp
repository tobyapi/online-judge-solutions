#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define REP(i, n) for (int i=0;i<int(n);++i)
#define FOR(i, a, b) for (int i=int(a);i<int(b);++i)
#define ALL(A) (A).begin(),(A).end()
#define SZ(A) int(A.size())
#define PB push_back

#pragma comment(linker, "/STACK:36777216")
#pragma GCC optimize ("O2")

using namespace std;

typedef unsigned long long ull;

struct RollingHash{
  static const ull p=100000007;
  string s;
  int n;
  vector<ull> pow, phash;

  RollingHash(string s) : s(s), n(SZ(s)), pow(n+1), phash(n+1){
    pow[0]=1,phash[0]=0;
    REP(i, n) {
      phash[i+1] = s[i] + phash[i] * p;
      pow[i+1] = pow[i] * p;
    }
  }

  static ull hash(const string &t) {
    ull h=0;
    REP(i,SZ(t))h=t[i]+h*p;
    return h;
  }

  inline ull hash(int b, int e){
    return phash[e]-phash[b]*pow[e-b];
  }

  inline int find(string t) {
    int w=t.size(),count=0;
    if(w > SZ(s))return 0;
    ull h=hash(t);
    REP(i,n-w+1)if(hash(i,i+w)==h){count++,cout << i << "\n";}
    return count;
  }
};


int main(void){
  ios::sync_with_stdio(false);
  string s,t;
  cin >> s >> t;
  RollingHash rh = RollingHash(s);
  rh.find(t);

  return 0;
}
