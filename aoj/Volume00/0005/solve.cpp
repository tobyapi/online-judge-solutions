#include<iostream>

using namespace std;

int GCD(int a, int b){
  return !b ? a : GCD(b, a%b);
}

int main(void){
  long long a,b,gcd,lcm;

  while(cin >> a >> b){
    gcd=GCD(a,b);
    lcm=a*b/gcd;
    cout << gcd << " " << lcm << endl;
  }
  return 0;
}
