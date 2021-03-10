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

};

double dot(point a, point b) {
  return (a.x * b.x + a.y * b.y);
}

double cross(point a, point b) {
  return (a.x * b.y - a.y * b.x);
}

int is_orthogonal(point a1, point a2, point b1, point b2) {
  return dot(a1-a2, b1-b2)==0.0;
}

int is_parallel(point a1, point a2, point b1, point b2) {
  return cross(a1-a2, b1-b2)==0.0 ;
}

int main(void){

  int q;
  cin >> q;
  while(q--){
    point a,b,c,d;
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;
    if(is_orthogonal(a,b,c,d))cout << 1 << endl;
    else if(is_parallel(a,b,c,d))cout << 2 << endl;
    else cout << 0 << endl;
  }
  return 0;
}
