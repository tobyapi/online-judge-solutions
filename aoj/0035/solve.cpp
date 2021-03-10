#include<iostream>
#include<cstdio>
#include <complex>
using namespace std;

typedef complex<double> P;

#define EPS (1e-10)
#define EQ(a,b) (abs((a)-(b)) < EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )

double cross(P ,P);
int func(P,P,P,P);

int main(void){
  double xa,ya,xb,yb,xc,yc,xd,yd;
  P a,b,c,d;

  while(~scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf"
	      ,&a.real(),&a.imag(),&b.real(),&b.imag()
	      ,&c.real(),&c.imag(),&d.real(),&d.imag())){
    if(func(a,b,c,d)||func(a,c,b,d))cout << "YES" << endl;
    else cout << "NO" << endl;
  }


  return 0;
}

double cross(P a,P b) {
  return (a.real() * b.imag() - a.imag() * b.real());
}

int func(P a1,P a2,P b1,P b2) {
  return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
         ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}
