#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  int L, A, B, C, D;
  
  cin >> L >> A >> B >> C >> D;
  
  int t;
  int a, b;
  a = A / C;
  if(A%C != 0) a++;
  b = B / D;
  if(B%D != 0) b++;
  t = max(a, b);
  cout << L-t << endl;
  return 0;
}
