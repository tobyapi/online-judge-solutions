#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

struct point{
  double x, y;
};

struct circle{
  point p;
  double r;
};

circle circumscribed_circle(point p, point q, point r){
  double a[2],b[2],c[2];
  circle res;
    
    a[0]=2*(q.x-p.x);
    b[0]=2*(q.y-p.y);
    c[0]=p.x*p.x-q.x*q.x+p.y*p.y-q.y*q.y;
    
    a[1]=2*(r.x-p.x);
    b[1]=2*(r.y-p.y);
    c[1]=p.x*p.x-r.x*r.x+p.y*p.y-r.y*r.y;
    
    res.p.x=(b[0]*c[1]-b[1]*c[0])/(a[0]*b[1]-a[1]*b[0]);
    res.p.y=(c[0]*a[1]-c[1]*a[0])/(a[0]*b[1]-a[1]*b[0]);
 
    res.r=sqrt(pow(fabs(p.x-res.p.x),2)+pow(fabs(p.y-res.p.y),2));
    
    return res;
}

int main(void) {
  
  int n;
  point in[3];
  circle ans;
 
  cin >> n;
  
  while(n--){
    for(int i=0;i<3;i++)
      cin >> in[i].x >> in[i].y;

    ans=circumscribed_circle(in[0], in[1], in[2]);

    printf("%.3f %.3f %.3f\n",ans.p.x,ans.p.y,ans.r);
  }
  
  return 0;
}
