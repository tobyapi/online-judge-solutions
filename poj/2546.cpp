#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include<cfloat>
#include<cstdio>
#define curr(P, i) P[(i) % P.size()]
#define next(P, i) P[(i+1) % P.size()]
#define prev(P, i) P[(i+P.size()-1) % P.size()]


using namespace std;

typedef double Real;

Real EPS = 1e-8;
const Real PI = acos(-1.0);

int sgn(Real a, Real b=0){return a<b-EPS?-1:a>b+EPS?1:0;}
Real sqr(Real a){return sqrt(max(a,(Real)0));}

struct Point{  
  Real add(Real a, Real b){
    if(abs(a+b) < EPS*(abs(a)+abs(b)))return 0;
    return a+b;
  }

  Real x, y;
  Point(){}
  Point(Real x,Real y) : x(x) , y(y){}

  Point operator + (Point p){return Point(add(x,p.x), add(y,p.y));}
  Point operator - (Point p){return Point(add(x,-p.x), add(y,-p.y));}
  Point operator * (Real d){return Point(x*d,y*d);}
  Point operator / (Real d){return Point(x/d,y/d);}
  bool operator == (Point p){return !sgn(dist(p));}
  //昇順
  bool operator < (Point p)const{return (p.x!=x)?x<p.x:y<p.y;}
  Real norm(){return sqr(x*x+y*y);}
  Real dist(Point a){return (*this-a).norm();}
  Real dot(Point a){return x*a.x+y*a.y;}
  Real cross(Point a){return x*a.y-y*a.x;}
  Point rotate(Real r,Point p = Point(0,0)){
    Real ta=cos(r)*(x-p.x)-sin(r)*(y-p.y)+p.x;
    Real tb=sin(r)*(x-p.x)+cos(r)*(y-p.y)+p.y;
    return Point(ta,tb);
  }
  Real arg(){
    if(sgn(x)>0)return atan(y/x);
    if(sgn(x)<0)return atan(y/x)+PI;
    if(sgn(y)>0)return PI/2;
    if(sgn(y)<0)return 3*PI/2;
    return 0;
  }
};

struct Circle{
  Point p;
  Real r;
  Circle(){}
  Circle(Point p, Real r) : p(p) , r(r){}
  
  Real intersectionArea(Circle c){
    Real r1=min(r,c.r),r2=max(r,c.r);
    Real d=(p-c.p).norm();
    if(sgn(d,r2-r1)<=0)return PI*r1*r1;
    if(sgn(d,r2+r1)>=0)return 0;
    
    Real rc=(d*d+r1*r1-r2*r2)/2/d;
    Real theta=acos(rc/r1);
    Real phi=acos((d-rc)/r2);
    return r1*r1*theta+r2*r2*phi-d*r1*sin(theta);
  }
};

int main(void){
  Circle a,b;
  cin >> a.p.x >> a.p.y >> a.r;
  cin >> b.p.x >> b.p.y >> b.r;

  printf("%.3f",a.intersectionArea(b));
  cout << endl;

  return 0;
}