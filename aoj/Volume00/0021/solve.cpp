#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include<cfloat>

using namespace std;

double EPS = 1e-10;
const double PI = acos(-1);

double add(double a, double b){
  if(abs(a+b) < EPS * (abs(a)+abs(b)))return 0;
  return a+b;
}

struct point{
  double x, y;
  point(){x=y=0;}
  point(double x,double y) : x(x) , y(y){}

  point operator - (point p){
    return point(add(x,-p.x), add(y,-p.y));
  }
};

double cross(point a, point b) {return (a.x * b.y - a.y * b.x);}

int is_parallel(point a1, point a2, point b1, point b2) {
  return cross(a1-a2, b1-b2)==0.0 ;
}

int main(void){

  point a,b,c,d;
  int n;
  cin >> n;

  while(n--){
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;
    if(is_parallel(a,b,c,d))cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}
