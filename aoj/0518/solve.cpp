#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
 
 
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

  bool operator == ( const point &p ) const {
    return abs(x-p.x) < EPS && abs(y-p.y) < EPS;
  }
};
 
bool cmp_x(const point& p, const point& q){
  if(p.x != q.x)return p.x<q.x;
  return p.y < q.y;
}

vector<point> normal_vector(point a){
  vector<point>res; 
  point b;
  b.x=-a.y, b.y=a.x;
  res.push_back(b);
  b.x=a.y, b.y=-a.x;
  res.push_back(b);

  return res;
}

double areaPol(vector<point> t){
  t.push_back(t[0]);
  int tsz=t.size();
  double area=0;
  for(int i=0;i<tsz-1;i++){
    area+=(t[i].x-t[i+1].x)*(t[i].y+t[i+1].y);
  }
  return abs(area)/2.0;
}

vector<point>N;

bool Binary_search(point x){
  int l=0,r=N.size(),mid=(l+r)/2;
 
  while(r-l>1){
    if(N[mid]==x)return true;
 
    if(x.x < N[mid].x ||(N[mid].x==x.x && x.y < N[mid].y))r=mid;
    else l=mid;
 
    mid=(l+r)/2;
  }
 
  if(N[mid]==x)return true;
  return false;
}

double solve(void){

  double res=0;

  for(int i=0;i<N.size();i++){
    for(int j=i+1;j<N.size();j++){

      vector<point> nv=normal_vector(N[j]-N[i]);
      point a=N[i]+nv[0],b=N[j]+nv[0];

      if(Binary_search(a) && Binary_search(b)){
	vector<point>c;
	c.push_back(N[i]);
	c.push_back(N[j]);
	c.push_back(b);
	c.push_back(a);
	res=max(res,areaPol(c));
      
      }
    }
  }
 return res;
}
 
int main(void){
  int n;
  point in;
 
  while(cin >> n){
    if(n==0)break;

    N.clear();   

    for(int i=0; i<n; i++){
      cin >> in.x >> in.y;
      N.push_back(in);
    }

    sort(N.begin(),N.end(),cmp_x);
    cout << (int)solve() << endl;
  }
 
  return 0;
}
