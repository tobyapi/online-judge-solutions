#include<iostream>
#include<cmath>
#include<iostream>
#include<cstdio>

using namespace std;

int main(void){

  double q;

  while(cin >> q,q!=-1){
    double x=q/2;
    while(abs(x*x*x-q)>0.00001*q)
    x=x-(x*x*x-q)/(3*x*x);

    printf("%.6lf",x);
    cout << endl;
  }

  return 0;
}
