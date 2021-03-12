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

double areaPol(vector<point> t){
  double area=0;
  for(int i=0;i<t.size();i++)
    area+=(curr(t,i).x-next(t,i).x)*(curr(t,i).y+next(t,i).y);

  return abs(area)/2.0;
}

int main(void){
  int n;
  cin >> n;
  vector<point>pol(n);

  for(int i=0;i<n;i++)cin >> pol[i].x >> pol[i].y;

  printf("%.1f\n",areaPol(pol));

  return 0;
}
