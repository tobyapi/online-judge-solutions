#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include<cfloat>
#include<cstdio>
#define all(c) (c).begin(),(c).end()
#define curr(P,i) P[(i)%P.size()]
#define next(P,i) P[(i+1)%P.size()]
#define prev(P,i) P[(i+P.size()-1)%P.size()]


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

  Point operator + (Point p){return Point(add(x,p.x), add(y,p.y));}
  Point operator - (Point p){return Point(add(x,-p.x), add(y,-p.y));}
  Point operator * (Real d){return Point(x*d,y*d);}
  Point operator / (Real d){return Point(x/d,y/d);}
  bool operator == (Point p){return !sgn(dist(p));}
  bool operator < (Point p)const{return (p.x!=x)?x<p.x:y<p.y;}
  Real norm(){return sqr(x*x+y*y);}
  Real dist(Point a){return (*this-a).norm();}
  Real dot(Point a){return x*a.x+y*a.y;}
  Real cross(Point a){return x*a.y-y*a.x;}
  //点pを中心に角度r(radius)だけ半時計回りに回転する
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

//a -> b -> c
int ccw(Point a, Point b, Point c) {
  b = b-a; c = c-a;

  if (b.cross(c) > 0)   return +1;       // counter clockwise
  if (b.cross(c) < 0)   return -1;       // clockwise
  if (b.dot(c) < 0)     return +2;       // c--a--b on line
  if (b.norm() < c.norm()) return -2;    // a--b--c on line
  return 0;                              // a--c--b on line
}

struct Line{
  Point a,b;

  Line(){}
  Line(Point a,Point b):a(a),b(b){}

  bool on(Point c){return abs(ccw(a,b,c))!=1;}
  Real dist(Point c){return abs((b-a).cross(c-a))/(b-a).norm();}
};

struct Circle{
  Point p;
  Real r;
  Circle(){}
  Circle(Point p, Real r) : p(p) , r(r){}
  
  vector<Point> intersectionPoints(Line l){
    Real a=l.b.y-l.a.y,b=l.a.x-l.b.x;
    Real c=-(a*l.a.x+b*l.a.y);

    Real L=l.a.dist(l.b);
    Point e=(l.b-l.a)/L;
    Point v(-e.y,e.x);
    Real k=-(a*p.x+b*p.y+c)/(a*v.x+b*v.y);

    if(r<k)vector<Point>();
    Point q=p+v*k;
    Real S=sqr(r*r-k*k);
    vector<Point>res;
    res.push_back(q+e*S);
    res.push_back(q-e*S);
    return res;
  }
  
};

int main(void){

  Circle c;
  cin >> c.p.x >> c.p.y >> c.r;
  int q;
  cin >> q;
  while(q--){
    Line l;
    cin >> l.a.x >> l.a.y >> l.b.x >> l.b.y;
    vector<Point>res=c.intersectionPoints(l);
    sort(all(res));
    printf("%.8f %.8f ",res[0].x,res[0].y);
    printf("%.8f %.8f ",res[1].x,res[1].y);
    cout << endl;
  }

  return 0;
}
