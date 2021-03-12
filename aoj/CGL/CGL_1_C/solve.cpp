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

double EPS = 1e-10;
const double PI = acos(-1);

double add(double a, double b){
  if(abs(a+b) < EPS * (abs(a)+abs(b)))return 0;
  return a+b;
}

struct point{
  double x, y;
  point(){}
  point(double x,double y) : x(x) , y(y){}

  point operator + (point p){
    return point(add(x,p.x), add(y,p.y));
  }

  point operator - (point p){
    return point(add(x,-p.x), add(y,-p.y));
  }

  point operator * (double d){
    return point(x*d,y*d);
  }

  point operator / (double d){
    return point(x/d,y/d);
  }
};

typedef point Vector;

double dot(point a, point b) {
  return (a.x * b.x + a.y * b.y);
}

double cross(point a, point b) {
  return (a.x * b.y - a.y * b.x);
}

double norm(point a){
  return sqrt(a.x*a.x+a.y*a.y);
}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw( point p0, point p1, point p2 ){
  Vector a=p1-p0;
  Vector b=p2-p0;
  if (cross(a,b)>EPS) return COUNTER_CLOCKWISE;
  if (cross(a,b)<-EPS) return CLOCKWISE;
  if (dot(a, b)<-EPS) return ONLINE_BACK;
  if (norm(a)<norm(b)) return ONLINE_FRONT;
  return ON_SEGMENT;
}

int main(void){
  point a,b,c;
  int q;
  cin >> a.x >> a.y >> b.x >> b.y;
  cin >> q;
  while(q--){
    cin >> c.x >> c.y;
    int res=ccw(a,b,c);
    if(res==COUNTER_CLOCKWISE)cout << "COUNTER_CLOCKWISE" << endl;
    else if(res==CLOCKWISE)cout << "CLOCKWISE" << endl;
    else if(res==ONLINE_BACK)cout << "ONLINE_BACK" << endl;
    else if(res==ONLINE_FRONT)cout << "ONLINE_FRONT" << endl;
    else if(res==ON_SEGMENT)cout << "ON_SEGMENT" << endl;
  }

  return 0;
}
