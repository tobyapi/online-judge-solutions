#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>

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

  point operator / (double d){
    return point(x/d,y/d);
  }
  
  bool operator == ( const point &p ) const {
    return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
  }
};

struct segment{
  point a,b;
};

double cross(point a, point b) {
  return (a.x * b.y - a.y * b.x);
}

double dist(point a,point b){
  return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

int is_intersected_ls(point a1, point a2, point b1, point b2) {
  return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
         ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}

point intersection_ls(point a1, point a2, point b1, point b2) {
  point b = b2-b1;
  double d1 = abs(cross(b, a1-b1));
  double d2 = abs(cross(b, a2-b1));
  double t = d1 / (d1 + d2);

  return a1 + (a2-a1) * t;
}

int main(void){
  segment s[3];

  while(true){
    for(int i=0;i<3;i++){
      cin >> s[i].a.x >> s[i].a.y >> s[i].b.x >> s[i].b.y;
      if( s[i].a.x==0 && s[i].a.y==0 && s[i].b.x==0 && s[i].b.y==0)return 0;
      }
    
    int fg[3]={0};
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	if(i!=j)
	  fg[i]+=is_intersected_ls(s[i].a,s[i].b,s[j].a,s[j].b);
      }
    }

    if(fg[0]==2 && fg[1]==2 && fg[2]==2){
      point p[3];
      for(int i=0;i<2;i++)
	    p[i]=intersection_ls(s[i].a,s[i].b,s[i+1].a,s[i+1].b);
      p[2]=intersection_ls(s[2].a,s[2].b,s[0].a,s[0].b);

      double z=(dist(p[0],p[1])+dist(p[1],p[2])+dist(p[2],p[0]))/2;
      double res=sqrt(z*(z-dist(p[0],p[1]))*(z-dist(p[1],p[2]))*(z-dist(p[2],p[0])));

      if(res>1900000-EPS)cout <<"dai-kichi"<<endl;
      else if(res>1000000-EPS)cout <<"chu-kichi"<<endl;
      else if(res>100000-EPS)cout <<"kichi"<<endl;
      else if(res>0+EPS)cout << "syo-kichi"<<endl;
      else cout <<"kyo"<<endl;
    }
    else cout <<"kyo"<<endl;
  }
  return 0;
}
