#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<climits>
#include<cfloat>

using namespace std;

double EPS=1e-10;

double add(double a,double b){
  if(abs(a+b)<EPS * (abs(a)+abs(b)))return 0;
  return a+b;
}

struct point{
  double x,y;
  point(){}
  point(double x,double y) : x(x) , y(y) {}

  point operator + (point p) {
    return point(add(x,p.x),add(y,p.y));
  }

  point operator - (point p) {
    return point(add(x,-p.x),add(y,-p.y));
  }

  point operator * (double d) {
    return point(x*d,y*d);
  }

  point operator / (double d) {
    return point(x/d,y/d);
  }

  bool operator == (const point &p)const{
    return abs(x-p.x)<EPS && abs(y-p.y)<EPS;
  }
};

struct circle{
  point p;
  double r;
  circle(){}
  circle(point p,double r):p(p),r(r){}
};

double dist(point a, point b){
  return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

vector<point> circle_cross(circle a, circle b){
  vector<point>ret;

  double x=a.p.x-b.p.x,y=a.p.y-b.p.y;
  double L=x*x+y*y;

  if(L>pow(a.r+b.r,2))return ret;

  L=sqrt(L);
  double C=atan2(b.p.y-a.p.y,b.p.x-a.p.x);
  double alpha=acos((L*L+a.r*a.r-b.r*b.r)/(2*L*a.r));

  point r1,r2;
  r1.x=a.p.x+cos(C+alpha),r1.y=a.p.y+sin(C+alpha);
  r2.x=a.p.x+cos(C-alpha),r2.y=a.p.y+sin(C-alpha);

  ret.push_back(r1),ret.push_back(r2);
  return ret;
}

int main(void){

  int n;
  point a;
  vector<point>P;
  vector<circle>C;

  while(cin >> n,n){
    P.clear();
    C.clear();
    for(int i=0;i<n;i++){
      cin >> a.x >> a.y;
      P.push_back(a);
    }

    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
	if(dist(P[i],P[j])>2.0+EPS)continue;
	vector<point>res=circle_cross(circle(P[i],1.0),circle(P[j],1.0));
	for(int k=0;k<res.size();k++)
	  C.push_back(circle(res[k],1));
      }
    }

    int ans=1;
    for(int i=0;i<C.size();i++){
      int cnt=0;
      for(int j=0;j<P.size();j++)
	if(dist(C[i].p,P[j])<1.0+EPS)cnt++;
	
      ans=max(ans,cnt);
    }

    cout << ans << endl;
  }

  return 0;
}
