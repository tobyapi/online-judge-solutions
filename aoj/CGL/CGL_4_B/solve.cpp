#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include<cfloat>
#include<cstdio>

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

  bool operator < (const point &p) const {
    if(p.x != x)return x<p.x;
    return y < p.y;
  }
};

typedef vector<point> Polygon;

double cross(point a, point b) {
  return (a.x * b.y - a.y * b.x);
}

double dist(point a,point b){
  return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

Polygon convex_hull(Polygon ps, int n){
  sort(ps.begin(),ps.end());
  int k=0;
  Polygon qs(n*2);

  for(int i=0;i<n;i++){
    while(k>1&&cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<0)k--;
    qs[k++]=ps[i];
  }

  for(int i=n-2,t=k;i>=0;i--){
    while(k>t&&cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<0)k--;
    qs[k++]=ps[i];
  }
  qs.resize(k-1);
  return qs;
}


double convex_diameter(Polygon ps){
  Polygon qs=convex_hull(ps,ps.size());
  int n=qs.size();
  if(n==2)return 0.0;

  int i=0,j=0;
  for(int k=0;k<n;k++){
    if(qs[k]<qs[i])i=k;
    if(qs[j]<qs[k])j=k;
  }
  double res=0;
  int si=i,sj=j;
  while(i!=sj || j!=si){
    res=max(res,dist(qs[i],qs[j]));
    if(cross(qs[(i+1)%n]-qs[i],qs[(j+1)%n]-qs[j])<0)i=(i+1)%n;
    else j=(j+1)%n;
  }
  return res;
}

int main(void){

  int n;
  cin >> n;
  Polygon pol(n);

  for(int i=0;i<n;i++)cin >> pol[i].x >> pol[i].y;

  printf("%.10f\n",convex_diameter(pol));

  return 0;
}
