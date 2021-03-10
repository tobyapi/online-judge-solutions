#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include<cfloat>
#include<cstdio>
 
#define curr(P, i) P[(i) % P.size()]
#define next(P, i) P[(i+1) % P.size()]
  
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
  point operator + (point p){return point(add(x,p.x), add(y,p.y));}
  point operator - (point p){return point(add(x,-p.x), add(y,-p.y));}
  point operator * (double d){return point(x*d,y*d);}
};
  
#define Line pair<point,point>
 
double dot(point a, point b){return (a.x * b.x + a.y * b.y);}
double cross(point a, point b){return (a.x * b.y - a.y * b.x);}
double norm(point a){return sqrt(a.x*a.x+a.y*a.y);}
  
int ccw(point a, point b, point c) {
  b = b-a; c = c-a;
  if (cross(b, c) > 0)   return +1;
  if (cross(b, c) < 0)   return -1;
  if (dot(b, c) < 0)     return +2;
  if (norm(b) < norm(c)) return -2; 
  return 0;
}
 
point intersection_l(point a1, point a2, point b1, point b2) {
  return a1 + (a2 - a1) * (cross(b2 - b1,b1 - a1) / cross(b2 - b1,a2 - a1));
}
 
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
 
 Line parallel_line(point a,point b,double h){
    double t = atan((a.y-b.y)/(a.x-b.x));
  
    point a_(a.x + h*cos(t+PI/2), a.y + h*sin(t+PI/2));
    point b_(b.x + h*cos(t+PI/2), b.y + h*sin(t+PI/2));
  
    if(ccw(a,b,a_)==-1)a_=symmetry(a,b,a_),b_=symmetry(a,b,b_);
    return make_pair(a_,b_);
}
 
vector<point> convex_cut(vector<point>pol,point a,point b){
  vector<point>q;
  for (int i=0; i<pol.size();i++) {
    point A=curr(pol,i),B=next(pol, i);
    if (ccw(a,b,A)!=-1)q.push_back(A);
    if (ccw(a,b,A)*ccw(a,b,B)<0)
      q.push_back(intersection_l(A,B,a,b));
  }
  return q;
}
 
bool C(vector<point>pol,double d){
  vector<Line>L;
  for(int i=0;i<pol.size();i++){
    L.push_back(Line(curr(pol,i),next(pol,i)));
  }
   
  for(int i=0;i<L.size();i++){
    Line tmp=parallel_line(L[i].first,L[i].second,d);
    pol=convex_cut(pol,tmp.first,tmp.second);
  }
  return pol.size()>0;
}
 
double Binary_search(vector<point>pol){
  double l=0,r=10000,tc=50;
  while(tc--){
    double d=(l+r)/2;
    if(C(pol,d))l=d;
    else r=d;
  }
  return l;
}
 
int main(void){
 
  int n;
  while(cin >> n,n){
    vector<point>pol(n);
    for(int i=0;i<n;i++)cin >> pol[i].x >> pol[i].y;
    printf("%.6f",Binary_search(pol));
    cout << endl;
  }
  return 0;
}
