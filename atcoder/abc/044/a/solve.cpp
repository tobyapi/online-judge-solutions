#include<iostream>

using namespace std;

int main(void){
  int N, K, X, Y;
  cin >> N >> K >> X >> Y;
  cout << min(N, K) * X + max(N-K, 0) * Y << endl;
}