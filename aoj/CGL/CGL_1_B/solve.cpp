#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
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

point symmetry(point p1, point p2, point Q){
  double xa,ya,xb,yb,t1,t2;
  point R;

  xa=Q.x-p1.x,ya=Q.y-p1.y;
  xb=p2.x-p1.x,yb=p2.y-p1.y;

  t1=xa*xb+ya*yb,t2=xb*xb+yb*yb;

  R.x=2*(p1.x+xb*t1/t2)-Q.x;
  R.y=2*(p1.y+yb*t1/t2)-Q.y;
  return R;
}

int main(void){

  point a,b;
  cin >> a.x >> a.y >> b.x >> b.y;

  int q;
  cin >> q;

  while(q--){
    point in;
    cin >> in.x >> in.y;
    point res=symmetry(a,b,in);
    printf("%.10f %.10f\n",res.x,res.y);
  }

  return 0;
}
