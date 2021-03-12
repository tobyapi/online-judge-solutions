#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include<cfloat>
 
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
 
struct segment{
  point a,b;
};
 
double dot(point a, point b) {
  return (a.x * b.x + a.y * b.y);
}
 
double cross(point a, point b) {
  return (a.x * b.y - a.y * b.x);
}
 
int is_intersected_ls(point a1, point a2, point b1, point b2) {
  return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
         ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}

int is_point_on_line(point a, point b, point c) {
  return cross(b-a, c-a)==0.0 &&
         (dot(b-a, c-a) > -EPS) &&
         (dot(a-b, c-b) > -EPS);
}

int inside(point p, vector<point> ps){
  point a(p.x,p.y),b(1000000,p.y);

  double ymx=-DBL_MAX,ymn=DBL_MAX;
  for(int i=0;i<ps.size();i++){
    ymx=max(ymx,ps[i].y);
    ymn=min(ymn,ps[i].y);
  }
  if(a.y<=ymn||a.y>=ymx)return 0;

  int cnt1=0;
  for(int i=0;i<ps.size();i++)
    if(is_point_on_line(a,b,ps[i]))cnt1++;
  
  int cnt=0;
  for(int i=0;i<ps.size();i++)
    if(is_intersected_ls(ps[i],ps[(i+1)%ps.size()],a,b))cnt++;

  return (cnt-cnt1)%2;
}

int main(void){
  int n;
  point k,s,in;
  vector<point>p; 

  cin >> n;
  while(n--){
    p.clear();
    for(int i=0;i<3;i++){
      cin >> in.x >> in.y;
      p.push_back(in);
    }     

    cin >> k.x >> k.y >> s.x >> s.y;

    if(inside(k,p)!=inside(s,p))cout << "OK" << endl;
    else cout << "NG" << endl;
     
  }
 
  return 0;
}
