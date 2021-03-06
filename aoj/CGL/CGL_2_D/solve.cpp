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

double norm(point a){
  return sqrt(dot(a,a));
}

int isOnSegment(point a, point b, point c) {
  return cross(b-a, c-a)==0.0 &&
    (dot(b-a, c-a) > -EPS) &&
    (dot(a-b, c-b) > -EPS);
}

int is_intersected_ls(point a1, point a2, point b1, point b2) {

  if(cross(a1-a2,b1-b2)==0){
    return isOnSegment(a1,a2,b1) || isOnSegment(a1,a2,b2)
      || isOnSegment(b1,b2,a1) || isOnSegment(b1,b2,a2);
  }
  else {
    return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
      ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
  }
}
double distance_ls_p(point a, point b, point c) {
  if ( dot(b-a, c-a) < EPS ) return norm(c-a);
  if ( dot(a-b, c-b) < EPS ) return norm(c-b);
  return abs(cross(b-a, c-a)) / norm(b-a);
}

double dist(point a,point b,point c,point d){
  if(is_intersected_ls(a,b,c,d))return 0.0;
  double A=distance_ls_p(a,b,c);
  double B=distance_ls_p(a,b,d);
  double C=distance_ls_p(c,d,a);
  double D=distance_ls_p(c,d,b);
  return min(min(A,B),min(C,D));
}

int main(void){

  int q;
  cin >> q;
  while(q--){
    point a,b,c,d;
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;

    printf("%.10f\n",dist(a,b,c,d));
  }
  return 0;
}
