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

struct Circle{
  Point p;
  Real r;
  Circle(){}
  Circle(Point p, Real r) : p(p) , r(r){}
  
  /*
    Verified. AOJ 1132
    2円の交点を求める
  */
  vector<Point> intersectionPoints(Circle b){
    vector<Point> res;
    Point tmp=p-b.p;
    if(tmp.norm()>pow(r+b.r,2))return res;

    Real L=p.dist(b.p);
    Real C=atan2(b.p.y-p.y,b.p.x-p.x);
    Real a=acos((L*L+r*r-b.r*b.r)/(2*L*r));

    res.push_back(Point(p.x+r*cos(C+a), p.y+r*sin(C+a)));
    res.push_back(Point(p.x+r*cos(C-a), p.y+r*sin(C-a)));
    return res;
  }
};

int main(void){

  Circle a,b;

  cin >> a.p.x >> a.p.y >> a.r;
  cin >> b.p.x >> b.p.y >> b.r;

  vector<Point> res=a.intersectionPoints(b);
  sort(all(res));
  printf("%.8f %.8f %.8f %.8f",res[0].x,res[0].y,res[1].x,res[1].y);
  cout << endl;

  return 0;
}
