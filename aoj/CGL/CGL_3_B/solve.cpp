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

long double EPS = 1e-8;
const double PI = acos(-1);

long double add(long double a,long double b){
  if(abs(a+b) < EPS * (abs(a)+abs(b)))return 0;
  return a+b;
}

struct point{
  long double x, y;
  point(){}
  point(long double x,long double y) : x(x) , y(y){}

  point operator + (point p){
    return point(add(x,p.x), add(y,p.y));
  }

  point operator - (point p){
    return point(add(x,-p.x), add(y,-p.y));
  }

  point operator * (double d){
    return point(x*d,y*d);
  }
};

typedef point Vector;

long double dot(point a, point b) {
  return (a.x * b.x + a.y * b.y);
}

long double cross(point a, point b) {
  return (a.x * b.y - a.y * b.x);
}

long double norm(point a){
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

bool is_convex(vector<point> pol){
  for(int i=0;i<pol.size();i++){
    if(ccw(prev(pol,i),curr(pol,i),next(pol,i))==-1)return false;
  }
  return true;
}
int main(void){
  int n;
  cin >> n;
  vector<point>pol(n);

  for(int i=0;i<n;i++)cin >> pol[i].x >> pol[i].y;

  cout << is_convex(pol) << endl;

  return 0;
}
