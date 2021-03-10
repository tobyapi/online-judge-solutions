#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main(void){
  double x,h;
  while(cin >> x >> h,x&&h)
    printf("%.6f\n",x*x+sqrt((x*x)/4+h*h)*x*2);

  return 0;
}
