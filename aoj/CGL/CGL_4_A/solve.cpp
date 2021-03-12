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
  //bool operator < (Point p)const{return (p.x!=x)?x<p.x:y<p.y;}
bool operator < (Point p)const{return (p.y!=y)?y<p.y:x<p.x;}
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

  //射影
  Point project(Point p){
    Point base=b-a;
    Real t=(p-a).dot(base)/base.dot(base);
    return a+base*t;
  }
};


struct Polygon{
  //頂点。反時計回りに順番で与えられていること。
  vector<Point>v;
  
  Polygon(){}
  Polygon(int n){v.resize(n);}

  vector<Point>convexHull(){
    sort(all(v));
    int k=0;
    vector<Point> qs(v.size()*2);
    
    for(int i=0;i<v.size();i++){
      while(k>1 && (qs[k-1]-qs[k-2]).cross(v[i]-qs[k-1])<0)k--;
      qs[k++]=v[i];
    }
    
    for(int i=v.size()-2,t=k;i>=0;i--){
      while(k>t && (qs[k-1]-qs[k-2]).cross(v[i]-qs[k-1])<0)k--;
      qs[k++]=v[i];
    }
    qs.resize(k-1);
    return qs;
  }
};

int main(void){

  int n;
  cin >> n;
  Polygon p(n);

  for(int i=0;i<n;i++)
    cin >> p.v[i].x >> p.v[i].y;
  
  vector<Point>res=p.convexHull();

  cout << res.size() << endl;
  for(int i=0;i<res.size();i++)
    cout << res[i].x << " " << res[i].y << endl;

  return 0;
}
