#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include<cfloat>
#include<cstdio>
#include<cstdio>
#include<valarray>
#include<list>

using namespace std;

typedef valarray<double> point;
const int dim = 3;
double EPS = 1e-10;

/*
double add(double a, double b){
  if(abs(a+b) < EPS * (abs(a)+abs(b)))return 0;
  return a+b;
}

struct point{
  double x,y,z;
	
  point(){}
  point(double x,double y,double z) : x(x),y(y),z(z){}
     
  point operator + (point p){
    return point(add(x,p.x), add(y,p.y),add(z,p.z));
  }
     
  point operator - (point p){
    return point(add(x,-p.x), add(y,-p.y),add(z,-p.z));
  }
     
  point operator * (double d){
    return point(x*d,y*d,z*d);
  }
};


double dist(point a,point b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2));
}
*/

double dot(const point& a, const point& b) {
  return (a * b).sum();
}

point cross(const point& a, const point& b) {
  return a.cshift(+1)*b.cshift(-1)
       - a.cshift(-1)*b.cshift(+1);
}
double dist2(const point& a, const point& b) {
  return dot(a-b, a-b);
}

struct min_sphere {
  point center;
  double radius2;
	
  void add_point(const point& p) {
    ps.push_back(p);
  }
	
  void compile(void) {
    m = 0;
    center.resize(dim, 0);
    radius2 = -1;
    make_ball(ps.end());
  }
	
  template <class OUT>
  void support(OUT out) {
    copy(ps.begin(), supp_end, out);
  }
	
  min_sphere(void) {
    for (int i = 0; i <= dim; i++) {
      c[i].resize(dim, 0);
      v[i].resize(dim, 0);
    }
  }
private:
  list<point> ps;
  list<point>::iterator supp_end;
  int m;
  point v[dim+1], c[dim+1];
  double z[dim+1], r[dim+1];
	
  void pop(void){ m--; }
	
  void push(const point& p) {
    if (m == 0)c[0]=p,r[0]=0;
    else {
      double e=dist2(p,c[m-1])-r[m-1];
      point delta=p-c[0];
      v[m]=p-c[0];
    	
      for (int i=1;i<m;i++)
        v[m]-=v[i]*dot(v[i],delta)/z[i];
    	
      z[m]=dot(v[m],v[m]);
      c[m]=c[m-1]+e*v[m]/z[m]/2;
      r[m]=r[m-1]+e*e/z[m]/4;
    }
    center  = c[m];
    radius2 = r[m]; 
  	m++;
  }
	
  void make_ball(list<point>::iterator i) {
    supp_end = ps.begin();
    if (m == dim + 1) return;
    for (list<point>::iterator k = ps.begin(); k != i; ) {
      list<point>::iterator j = k++;
      if (dist2(*j, center) > radius2) {
        push(*j); make_ball(j); pop();
        move_to_front(j);
      }
    }
  }
	
  void move_to_front(list<point>::iterator j) {
    if (supp_end == j)supp_end++;
    ps.splice (ps.begin(), ps, j);
  }
};
/*
4面体の体積 V
4面体の外接球の半径 R

4点が同一平面上にあれば-1を返す
*/
/*
double circumscribed_sphere(point A,point B,point C,point D){
	double a=dist(B,C),b=dist(C,A),c=dist(A,B);
	double d=dist(D,A),e=dist(D,B),f=dist(D,C);
	
	double a2=a*a,b2=b*b,c2=c*c,d2=d*d,e2=e*e,f2=f*f;
	
	double V=sqrt(a2*d2*(b2+e2+c2+f2-a2-d2)
			+b2*e2*(c2+f2+a2+d2-b2-e2)
			+c2*f2*(a2+d2+b2+e2-c2-f2)
			-(a2*e2*f2+d2*e2*f2+c2*d2*e2+a2*b2*c2))/12;

	if(V!=V)return -1;
	
	double R=sqrt((a*d+b*e+c*f)*(a*d+b*e-c*f)
			*(b*e+c*f-a*d)*(c*f+a*d-b*e))/(24*V);
	
	return R;
}
*/
int main(void){
	
	int n;
	
	while(cin >> n,n){
		point p(3);
		min_sphere S;
		
		for(int i=0;i<n;i++){
			cin >> p[0] >> p[1] >> p[2];
			S.add_point(p);
		}
		
		S.compile();
		printf("%.5f\n",sqrt(S.radius2));;
	}
	
return 0;
}
