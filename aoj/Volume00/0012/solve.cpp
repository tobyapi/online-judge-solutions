#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include<cfloat>
#define curr(P, i) P[(i) % P.size()]
#define next(P, i) P[(i+1) % P.size()]
#define prev(P, i) P[(i+P.size()-1) % P.size()]

using namespace std;

typedef double Real;

Real EPS = 1e-8;
const Real PI = acos(-1);

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
  Point operator - (Point p){return Point(add(x,-p.x), add(y,-p.y));}
};

Real dot(Point a, Point b) {return (a.x*b.x+a.y*b.y);}
Real cross(Point a, Point b) {return (a.x*b.y-a.y*b.x);}

struct Polygon{
  vector<Point>v;

  Polygon(){}
  Polygon(int n){v.resize(n);}

  int contain(Point p){
    bool in=false;
    for(int i=0;i<v.size();i++){
      Point a=curr(v,i)-p,b=next(v,i)-p;
      if(a.y>b.y)swap(a,b);
      if(a.y<=0 && 0<b.y && cross(a,b)<0)in=!in;
      if(cross(a,b)==0 && dot(a,b)<=0)return 2;
    }
    return in?1:0;
  }
};

int main(void){

  Polygon pol(3);
  Point p;
  while(cin >> pol.v[0].x >> pol.v[0].y){
    for(int i=1;i<3;i++)cin >> pol.v[i].x >> pol.v[i].y;
    cin >> p.x >> p.y;
    
    if(pol.contain(p))cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
