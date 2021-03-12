#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include<cfloat>
#include<cstdio>
#include<cassert>
#define all(c) (c).begin(),(c).end()
#define curr(P,i) P[(i)%P.size()]
#define next(P,i) P[(i+1)%P.size()]
#define prev(P,i) P[(i+P.size()-1)%P.size()]


using namespace std;

typedef double Real;

Real EPS = 1e-7;
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
};

//a -> b -> c

int ccw(Point a, Point b, Point c) {
  b = b-a; c = c-a;
  
  if (b.cross(c) > 0)   return +1;       // counter clockwise
  if (b.cross(c) < 0)   return -1;       // clockwise
  if (b.dot(c) < 0)     return +2;       // c--a--b on line
  if (b.dot(b) < c.dot(c)) return -2;    // a--b--c on line
  /*
  if(sgn(b.cross(c))>0)return +1;
  if(sgn(b.cross(c))<0)return -1;
  if(sgn(b.dot(c))<0)return +2;
  if(sgn(b.norm(),c.norm())<0)return -2;
  */
  return 0;                              // a--c--b on line
}

struct Line{
  Point a,b;

  Line(){}
  Line(Point a,Point b):a(a),b(b){}

  bool on(Point c){return abs(ccw(a,b,c))!=1;}
  Real dist(Point c){return abs((b-a).cross(c-a))/(b-a).norm();}

  Point intersectionPoint(Line l){
    return a+(b-a)*((l.b-l.a).cross(l.a-a)/(l.b-l.a).cross(b-a));
  }
};

struct Segment: public Line{
  
  Segment(){}
  Segment(Point a,Point b):Line(a,b){}

  bool on(Point c){return ccw(a,b,c)==0;}
  bool on(Line l){return l.on(a)&&l.on(b);}

  bool isParallel(Segment s){return (a-b).cross(s.a-s.b)==0.0;}

  Real dist(Point c){
    if((b-a).dot(c-a)<EPS)return c.dist(a);
    if((a-b).dot(c-b)<EPS)return c.dist(b);
    return abs((b-a).cross(c-a))/b.dist(a);    
  }

  bool isIntersection(Line l){
    return (ccw(l.a,l.b,a)*ccw(l.a,l.b,b)<0);
  }
};

struct Polygon{
  //頂点。反時計回りに順番で与えられていること。
  vector<Point>v;
  
  Polygon(){}
  Polygon(int n){v.resize(n);}
  Polygon(vector<Point>v):v(v){}
  /*
    Verified. AOJ CGL_3/A
    多角形の面積計算。
    多角形の頂点が時計回りまたは反時計回り
  */
  Real area(){
    Real area=0;
    for(int i=0;i<v.size();i++)
      area+=(curr(v,i).x-next(v,i).x)*(curr(v,i).y+next(v,i).y);
    return abs(area)/2.0;
  }
  
  /*
    凸多角形の切断
    凸多角形psを直線abで切断し、
    左側の多角形を返す。
  */
  Polygon convexCut(Line l){
    vector<Point>res;
    for(int i=0;i<v.size();i++){
      Point a=curr(v,i),b=next(v,i),p=l.b-l.a;
      if(ccw(l.a,l.b,a)!=-1)res.push_back(a);
      if(sgn(p.cross(a-l.a)*p.cross(b-l.a))<0)
	res.push_back(Segment(a,b).intersectionPoint(l));
    }
    return res;
  }
  
};

int main(void){

  int n;
  cin >> n;
  Polygon p(n);

  for(int i=0;i<n;i++)
    cin >> p.v[i].x >> p.v[i].y;
  
  //assert(sgn(p.area())>0);

  int q;
  cin >> q;
  while(q--){
    Line l;
    cin >> l.a.x >> l.a.y >> l.b.x >> l.b.y;

    //bool fg=false;
    //for(int i=0;i<n;i++){
      //assert(!l.on(p.v[i]));
      //assert(!Segment(p.v[i],p.v[(i+1)%n]).on(l));
      //fg|=Segment(p.v[i],p.v[(i+1)%n]).isIntersection(l);
    //}
    //assert(fg);
    //assert(sgn(p.convexCut(l).area(),p.area())<1);
    //assert(sgn(p.convexCut(l).area())>0);
    printf("%.8f",p.convexCut(l).area());
    cout << endl;
  }
  return 0;
}
