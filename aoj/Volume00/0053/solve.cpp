#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;

bool isprime[10000001];

void sieve(ll N){
  
  fill(isprime,isprime+10000001,true);
  isprime[0]=isprime[1]=false;
  
  for(ll i=2;i*i<=N;i++){
    if(isprime[i]){
      for(ll j=i*2;j<=N;j+=i){
	isprime[j]=false;
      }
    }
  }
}

vector<int> getPrime(const int n) {
    const int ub = (n - 1) / 2;
    const int sqrtub = (sqrt(n) - 1) / 2;
    vector<int> res;
    if (n <= 1) return res;
    res.push_back(2);

    bool *isNotPrime = new bool[ub + 1];
    for (int i = 0; i <= ub; i++)isNotPrime[i] = (i % 3 == 1);
    isNotPrime[1] = false;
    
    for (int i = 2; i <= sqrtub; i++) {
        if (!isNotPrime[i]) {
            int d = i * 2 + 1;
            for (int j = 3 * i + 1; j <= ub; j += d) {
                isNotPrime[j] = true;
            }
        }
    }
    for (int i = 1; i <= ub; i++) {
        if (!isNotPrime[i]) {
            res.push_back(i * 2 + 1);
        }
    }
    delete[] isNotPrime;
    return res;
}

int main(void){

  /*
  //sieve(10000000);

  //int res[10001];
  fill(res,res+10001,0);
  res[1]=2;
  for(int i=2,j=0;j<10001;i++)
    if(isprime[i])res[j+1]=res[j++]+i;
  */
  vector<int>res=getPrime(10000000);
  for(int i=0;i+1<res.size();i++)res[i+1]+=res[i];
  int a;
  while(cin >> a,a){
    cout << res[a-1] << endl;
  }

  return 0;
}
