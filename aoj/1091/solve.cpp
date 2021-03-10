#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

double heron(double a,double b,double c){
  double s=(a+b+c)/2;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main(void){

  double a,l,x;
  while(cin >> a >> l >> x){
    double ans=0.0;
    ans+=heron(l,l,a);
    ans+=heron((l+x)/2,(l+x)/2,l)*2;
    printf("%.10f",ans);
    cout << endl;
  }
  return 0;
}
