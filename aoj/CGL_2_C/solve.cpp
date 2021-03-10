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

};

double dot(point a, point b) {
  return (a.x * b.x + a.y * b.y);
}

double cross(point a, point b) {
  return (a.x * b.y - a.y * b.x);
}

point intersection_ls(point a1, point a2, point b1, point b2) {
  point b = b2-b1;
  double d1 = abs(cross(b, a1-b1));
  double d2 = abs(cross(b, a2-b1));
  double t = d1 / (d1 + d2);

  return a1 + (a2-a1) * t;
}

int main(void){

  int q;
  cin >> q;
  while(q--){
    point a,b,c,d;
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;
    point res=intersection_ls(a,b,c,d);
    printf("%.10f %.10f\n",res.x,res.y);
  }
  return 0;
}
