#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

double EPS = 1e-10;
double PI = 3.141592653589793238462643383279;

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

struct circle{
  point p;
  double r;
};

double dot(point a, point b){return (a.x * b.x + a.y * b.y);}
double cross(point a, point b){return (a.x * b.y - a.y * b.x);}
double norm(point a){return sqrt(a.x*a.x+a.y*a.y);}

double dist(point a,point b){
  return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

double distance_ls_p(point a, point b, point c) {
    if ( dot(b-a, c-a) < EPS ) return norm(c-a);
    if ( dot(a-b, c-b) < EPS ) return norm(c-b);
  return abs(cross(b-a, c-a)) / norm(b-a);
}

int crossCS(point a, point b, circle c){
  double res=distance_ls_p(a,b,c.p);
  double ac=dist(a,c.p);
  double bc=dist(b,c.p);

  if(res>c.r || (ac<c.r && bc<c.r))return 0;
  else if(c.r-res<EPS ||(ac<c.r && bc>=c.r)||(ac>=c.r && bc<c.r))return 1;
  else return 2;
}

int main(void){
  int n,m;
  circle c[100];
  point t,s;

  while(cin >> n,n){
    for(int i=0;i<n;i++)
      cin >> c[i].p.x >> c[i].p.y >> c[i].r;
    
    cin >> m;
    for(int i=0;i<m;i++){
      cin >> t.x >> t.y >> s.x >> s.y;

      int fg=0;
      for(int j=0;j<n;j++)fg+=crossCS(t,s,c[j]);
      
      if(fg==0)cout << "Danger" << endl;
      else cout << "Safe" << endl;
    }
  }
  return 0;
}
