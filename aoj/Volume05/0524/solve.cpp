#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<cfloat>
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
 
point solve(vector<point> M){
 
  for(int i=0; i< N.size(); i++){
    int j=1;
    for(; j< M.size(); j++){
      point t=N[i]+M[j]-M[0];
      if(!Binary_search(t))break;  
    }
    if(j==M.size())return N[i]-M[0];
  }
  return M[0];
}
 
int main(void){
  int n,m;
  point in;
  vector<point>M;
 
  while(cin >> m,m){
    M.clear();
    N.clear();   
 
    for(int i=0; i< m; i++){
      cin >> in.x >> in.y;
      M.push_back(in);
    }
     
    cin >> n;
 
    for(int i=0; i< n; i++){
      cin >> in.x >> in.y;
      N.push_back(in);
    }
 
    sort(N.begin(),N.end(),cmp_x);
 
    point res=solve(M);
 
    cout << res.x <<" "<< res.y << endl;
 
  }
 
  return 0;
}
