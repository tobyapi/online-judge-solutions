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

int contain(point p,vector<point>pol){
  bool in=false;
  for(int i=0;i<pol.size();i++){
    point a=curr(pol,i)-p,b=next(pol,i)-p;
    if(a.y>b.y)swap(a,b);
    if(a.y<=0 && 0<b.y && cross(a,b)<0)in=!in;
    if(cross(a,b)==0 && dot(a,b)<=0)return 1;
  }
  return in?2:0;
}

int main(void){

  int n;
  cin >> n;
  vector<point>pol(n);
  for(int i=0;i<n;i++)cin >> pol[i].x >> pol[i].y;

  int q;
  cin >> q;
  point a;
  while(q--){
    cin >> a.x >> a.y;
    cout << contain(a,pol) << endl;
  }

  return 0;
}
