#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){

  int t;
  cin >> t;

  while(t--){
    int p,q;
    cin >> p >> q;
    int tmp=p*p+q*q,cnt=0;

    for(int n=0;n*n<=tmp;n++){
      for(int m=0;m*m<=tmp;m++){
        if(m*m+n*n<1)continue;
        if((m*p+n*q)%(m*m+n*n)==0 && (m*q-n*p)%(m*m+n*n)==0)cnt++;
      }
    }

    if(cnt*2<=8)cout << "P" << endl;
    else cout << "C" << endl;
  }
  return 0;
}
