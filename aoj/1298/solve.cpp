#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include<cfloat>
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

  point operator - (point p){
    return point(add(x,-p.x), add(y,-p.y));
  }
};

bool cmp_x(const point& p, const point& q){
  if(p.x != q.x)return p.x<q.x;
  return p.y < q.y;
}

double dot(point a, point b) {
  return (a.x * b.x + a.y * b.y);
}

double cross(point a, point b) {
  return (a.x * b.y - a.y * b.x);
}

int is_point_on_line(point a, point b, point c) {
  return cross(b-a, c-a)==0.0 &&
         (dot(b-a, c-a) > -EPS) &&
         (dot(a-b, c-b) > -EPS);
}

int is_intersected_ls(point a1, point a2, point b1, point b2) {

  if(cross(a1-a2,b1-b2)==0){
    return is_point_on_line(a1,a2,b1) || is_point_on_line(a1,a2,b2) 
        || is_point_on_line(b1,b2,a1) || is_point_on_line(b1,b2,a2);
  }
  else {
    return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
           ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
  }
}

int contain(point p, vector<point> ps){
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

int crossPol(vector<point> pol1, vector<point> pol2){

  for(int i=0;i<pol1.size();i++)
    if(contain(pol1[i],pol2))return 1;
  
  for(int i=0;i<pol2.size();i++)
    if(contain(pol2[i],pol1))return 1;

  for(int i=0;i<pol1.size();i++)
    for(int j=0;j<pol2.size();j++)
      if(is_intersected_ls(pol1[i],next(pol1,i),pol2[j],next(pol2,j)))return 1;
  
  return 0;
}

vector<point>convex_hull(point* ps, int n){
  sort(ps,ps+n,cmp_x);
  int k=0;
  vector<point>qs(n*2);
 
  for(int i=0;i<n;i++){
    while(k>1&&cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<=0)k--;
    qs[k++]=ps[i];
  }
 
  for(int i=n-2,t=k;i>=0;i--){
    while(k>t&&cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<=0)k--;
    qs[k++]=ps[i];
  }
  qs.resize(k-1);
  return qs;
}

int main(void){
  int n,m;
  point black[100],white[100];

  while(cin >> n >> m,n|m){

    for(int i=0;i<n;i++)
      cin >> black[i].x >> black[i].y;
    
    for(int i=0;i<m;i++)
      cin >> white[i].x >> white[i].y;

    if(n<2||m<2){
      if(n<2 && m<2)cout << "YES" << endl;
      else {
	bool fg=false;
	for(int i=0;i<n;i++){
	  for(int j=0;j<m;j++){
	    if(is_intersected_ls(black[i],black[(i+1)%n],white[j],white[(j+1)%n]))fg=true;
	  }
	}
	if(fg)cout <<"NO"<<endl;
	else cout << "YES" << endl;
      }
      continue;
    }

    vector<point>Black,White;

    Black=convex_hull(black,n);
    White=convex_hull(white,m);
    
    if(crossPol(Black,White))cout << "NO" << endl;
    else cout << "YES" << endl;
  }

  return 0;
}
