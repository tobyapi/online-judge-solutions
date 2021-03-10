#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<cstdio>

#define all(c) (c).begin(),(c).end()

using namespace std;

const double EPS=1e-10;

double add(double a, double b){
  if(abs(a+b) < EPS * (abs(a)+abs(b)))return 0;
  return a+b;
}

struct point{
  double x,y,z;
  point(){}
  point(double x,double y,double z) : x(x),y(y),z(z){}
  point operator + (point p){return point(add(x,p.x),add(y,p.y),add(z,p.z));}
  point operator - (point p){return point(add(x,-p.x),add(y,-p.y),add(z,-p.z));}
  point operator * (double d){return point(x*d,y*d,z*d);}
};
double dot(point a,point b){return a.x*b.x+a.y*b.y+a.z*b.z;}
double norm(point a){return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);}
double theta(point a,point b){return acos(dot(a,b)/norm(a)/norm(b));}

int main(void){

  int n,m;
  while(cin >> n,n){
    vector<point>star(n);
    for(int i=0;i<n;i++)cin >> star[i].x >> star[i].y >> star[i].z;
    cin >> m;
    vector<double>p(m);
    vector<point>scope(m);
    for(int i=0;i<m;i++)
      cin >> scope[i].x >> scope[i].y >> scope[i].z >> p[i];
 
    int ans=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	if(theta(star[i],scope[j])-EPS<p[j]){ans++;break;}
      }
    }
    cout << ans << endl;
  }

  return 0;
}
