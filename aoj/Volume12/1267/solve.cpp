#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include<cfloat>
#define pb push_back
#define curr(P, i) P[(i) % P.size()]
#define next(P, i) P[(i+1) % P.size()]

using namespace std;

double EPS = 1e-10;

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
  return sqrt(a.x*a.x+a.y*a.y);
}

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

vector<point> covex_cut(vector<point>pol,point a,point b){
  vector<point>q;
  for (int i=0; i<pol.size();i++) {
    point A=curr(pol,i),B=next(pol, i);
    if (ccw(a,b,A)!=-1)q.push_back(A);
    if (ccw(a,b,A)*ccw(a,b,B)<0)
      q.push_back(intersection_l(A,B,a,b));
  }
  return q;
}

int main(void){
  int n;
  point in;
  vector<point>pol,ans;

  while(cin >> n,n){
    pol.clear();
    ans.clear();
    for(int i=0;i<n;i++){
      cin >> in.x >> in.y;
      pol.pb(in);
    }

    ans.pb(point(0,0));
    ans.pb(point(10001,0));
    ans.pb(point(10001,10001));
    ans.pb(point(0,10001));

    for(int i=0;i<n;i++)
      ans=covex_cut(ans,curr(pol,i),next(pol,i));
    
    if(ans.size())cout << 1 << endl;
    else cout << 0 << endl;

  }
  return 0;
}
