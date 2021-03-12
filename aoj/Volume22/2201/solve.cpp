#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define all(c) (c).begin(),(c).end()

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
  bool operator < (Point p){return (p.x!=x)?p.x<x:p.y<y;}
  Real norm(){return sqr(x*x+y*y);}
  Real dist(Point a){return (*this-a).norm();}
  Real dot(Point a){return x*a.x+y*a.y;}
  Real cross(Point a){return x*a.y-y*a.x;}
  //点pを中心に点tを角度r(radius)だけ半時計回りに回転する
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

struct Line{
  Point a,b;

  Line(){}
  Line(Point a,Point b):a(a),b(b){}

  Real dist(Point c){return abs((b-a).cross(c-a))/(b-a).norm();}
  bool isOrthogonal(Line l){return (a-b).dot(l.a-l.b)==0.0;}
  bool isParallel(Line l){return (a-b).cross(l.a-l.b)==0.0;}
  bool isIntersection(Line l){return !((a-b).cross(l.a-l.b)==0.0);}
  //平行でない前提
  Point intersectionPoint(Line l){
    return a+(b-a)*((l.b-l.a).cross(l.a-a)/(l.b-l.a).cross(b-a));
  }

  //射影
  Point project(Point p){
    Point base=b-a;
    Real t=(p-a).dot(base)/base.dot(base);
    return a+base*t;
  }

  //p1,p2を通る直線を対称軸として点Qと線対称の座標R
  Point symmetry(Point Q){
    return Q+(project(Q)-Q)*2;
  }
};

struct Circle{
  Point p;
  Real r;
  Circle(){}
  Circle(Point p, Real r) : p(p) , r(r){}

  Line tangent(Real theta){
    Point a(r*cos(theta),r*sin(theta));
    Point b(a.y,-a.x);
    return Line(p+a,p+a+b);
  }
  
  vector<Line> commonTangent(Circle x){
    vector<Line>res;
    x.p=x.p-p;
    Real a=x.p.arg();
    Real b[2]={(r-x.r),(r+x.r)};
    for(int i=0;i<2;i++){
      b[i]/=x.p.norm();
      if(sgn(b[i],-1.0)<0 || sgn(b[i],1.0)>0)return res;
      Real c=asin(b[i])-asin(1.0);
      res.push_back(tangent(a-c));
      res.push_back(tangent(a+c));
    }
    return res;
  }
  
};

int n;
vector<Circle>c;
vector<Real>m;

vector<Line> enumerate(){
  vector<Line>res;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j)continue;
      vector<Line>tmp=c[i].commonTangent(c[j]);
      for(int k=0;k<tmp.size();k++){
	res.push_back(tmp[k]);
      }
      c[i].r+=m[i];
      tmp=c[i].commonTangent(c[j]);
      for(int k=0;k<tmp.size();k++){
	res.push_back(tmp[k]);
      }
      c[i].r-=m[i];
    }
  }
  return res;
}

int count(Line l){
  int cnt=0;
  for(int i=0;i<n;i++){
    Real d=l.dist(c[i].p)-c[i].r;
    cnt+=(sgn(d)>=0 && sgn(d,m[i])<=0);
  }
  return cnt;
}

int main(void){

  while(cin >> n,n){
    c.resize(n);
    m.resize(n);

    for(int i=0;i<n;i++)
      cin >> c[i].p.x >> c[i].p.y >> c[i].r >> m[i];
    
    vector<Line>res=enumerate();
    
    int cnt=0;
    for(int i=0;i<res.size();i++){
      cnt=max(cnt,count(res[i]));
    }
    cout << max(1,cnt) << endl;
  }
  return 0;
}
