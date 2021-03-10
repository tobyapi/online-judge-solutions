#include<iostream>
#include<cmath>

using namespace std;

int main(void){
  int x,y,z,n,r;

  while(cin >> x >> y >> z,x|y|z){

    double a,b,c;
    a=sqrt(x*x+y*y);
    b=sqrt(y*y+z*z);
    c=sqrt(z*z+x*x);
    
    cin >> n;
    while(n--){
      cin >> r;
      r*=2;
      if(r>a||r>b||r>c)cout << "OK" << endl;
      else cout << "NA" << endl;
    }
  }
  return 0;
}
