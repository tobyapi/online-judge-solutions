#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include<cstdio>
#include<cfloat>

using namespace std;

double EPS = 1e-10;

struct point{
  double x, y;
};

double dot(point a, point b) {
  return (a.x * b.x + a.y * b.y);
}

double norm(point a){
  return sqrt(a.x*a.x+a.y*a.y);
}

int main(void){
  double D;
  point p,v;
 
  while(cin >> D,D){
  
    cin >> p.x >> p.y >> v.x >> v.y;
     
    double d=D+1;
    double a=dot(p,v)/norm(p)/norm(v);

    if(abs(1.0 + a) < EPS )d=norm(p);
    else if(abs(1.0 - a) < EPS)d=2.0-norm(p);

    if(d<D || abs(d-D)<EPS)printf("%.8f\n",d);
    else cout << "impossible" << endl;
  }
 
  return 0;
}
