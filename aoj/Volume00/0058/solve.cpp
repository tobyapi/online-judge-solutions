#include<iostream>
#include<cmath>
#include<complex>

#define EPS (1e-10)
#define EQ(a,b) (abs((a)-(b)) < EPS)

using namespace std;

typedef complex<double> P;

double dot(P,P);
int is_orthogonal(P,P,P,P);
 
int main(void){

  P a,b,c,d;

  while(~scanf("%lf %lf %lf %lf %lf %lf %lf %lf"
	       ,&a.real(),&a.imag(),&b.real(),&b.imag()
	       ,&c.real(),&c.imag(),&d.real(),&d.imag())){

    if(is_orthogonal(a,b,c,d))cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}

double dot(P a,P b) {
  return (a.real() * b.real() + a.imag() * b.imag());
}

int is_orthogonal(P a1,P a2,P b1,P b2) {
  return EQ( dot(a1-a2, b1-b2), 0.0 );
}
