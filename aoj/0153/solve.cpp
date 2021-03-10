#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
 
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
};
 
struct segment{
  point a,b;
};
 
struct circle{
  point p;
  double r;
};
 
double dot(point a, point b) {
  return (a.x * b.x + a.y * b.y);
}
 
double cross(point a, point b) {
  return (a.x * b.y - a.y * b.x);
}
 
int ccw(point p0, point p1, point p2){
  point a = p1 - p0;
  point b = p2 - p0;
  if(cross(a,b)>EPS)return +1;
  if(cross(a,b)<EPS)return -1;
  if(dot(a,b)<-EPS)return +2;
  if(a.x*a.x+a.y*a.y<b.x*b.x+b.y*b.y)return -2;
  return 0;
}
 
double vec_abs(point a){
  return sqrt(a.x*a.x+a.y*a.y);
}
 
double distance_ls_p(point a, point b, point c) {
  if ( dot(b-a, c-a) < EPS ) return vec_abs(c-a);
  if ( dot(a-b, c-b) < EPS ) return vec_abs(c-b);
  return abs(cross(b-a, c-a)) / vec_abs(b-a);
}
 
double dist(point a,point b){
  return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
 
int crossCS(point a, point b, circle c){
  double res=distance_ls_p(a,b,c.p);
  double ac=dist(a,c.p);
  double bc=dist(b,c.p);
 
  if(res>c.r || (ac<c.r && bc<c.r))return 0;
  else if(c.r-res<EPS ||(ac<c.r && bc>=c.r)||(ac>=c.r && bc<c.r))return 1;
  else return 2;
}
 
vector<segment> construct_edge(point* p, int n){
  vector<segment>seg,seg2;
  segment temp;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i!=j){
    temp.a=p[i];
    temp.b=p[j];
    seg.push_back(temp);
      }
    }
  }
 
  int t=seg.size();
  for(int i=0;i<t;i++){
    int fg=0;
    for(int j=0;j<t;j++){
      if(i!=j && vec_abs(seg[i].b-seg[j].a)<=EPS){
    if(ccw(seg[i].a,seg[i].b,seg[j].b)==1){
      fg=1;
      break;
    }
      }
    }
    if(!fg)seg2.push_back(seg[i]);
  }
  return seg2;
}
 
int point_contain(vector<segment> ps, point p, int n){
  int cnt=ccw(ps[0].a,ps[0].b,p);
 
  for(int i=0;i<n;i++)
    if(cnt!=ccw(ps[i].a,ps[i].b,p))return 0;
   
  return 1;
}
 
int main(void){
  point p[3];
  vector<segment> t;
  circle C;
 
  while(true){
    for(int i=0;i<3;i++){
      cin >> p[i].x >> p[i].y;
      if(p[i].x==0 && p[i].y==0)return 0;
    }
    cin >> C.p.x >> C.p.y >> C.r;
 
    double ans=0;
    for(int i=0;i<3;i++){
    int tmp=dist(p[i],C.p);
    if(tmp>ans)ans=tmp;
    }
    if(C.r>=ans){
      cout <<'b'<<endl;
      continue;
    }
     
    t=construct_edge(p,3);
    int res1=point_contain(t,C.p,3);
    double res2=100000000;
    for(int i=0;i<3;i++)
      res2=min(res2,distance_ls_p(t[i].a,t[i].b,C.p));
 
    if(res1 && C.r<=res2)cout <<'a'<< endl;
    else if(!res1 && C.r<res2)cout <<'d'<< endl;
    else cout <<'c'<< endl;
     
  }
  return 0;
}
