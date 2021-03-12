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

double dot(point a, point b) {
  return (a.x * b.x + a.y * b.y);
}

double norm(point a){
  return sqrt(dot(a,a));
}

typedef point Vector;
typedef pair<point,point> Line;

point projection(Vector p,Vector b){
  return b*dot(p,b)/dot(b,b);
}

point projection(Line l,Vector p){
  point a=l.second-l.first;
  point b=p-l.first;
  return l.first+projection(b,a);
}

int main(void){

  Line l;
  point c;
  int q;
  cin >> l.first.x >> l.first.y >> l.second.x >> l.second.y;
  cin >> q;
  while(q--){
    cin >> c.x >> c.y;
    point res=projection(l,c);
    printf("%.10f %.10f\n",res.x,res.y);
  }

  return 0;
}
