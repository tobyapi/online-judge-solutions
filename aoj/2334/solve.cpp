#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>

#define f first
#define s second
#define INF (1<<29)

using namespace std;

typedef pair<double,double>pii;

double dist(pii a,pii b){
  return sqrt(pow(a.f-b.f,2)+pow(a.s-b.s,2));
}

const double EPS=1e-10;

double dot(pii a,pii b){
  return a.f*b.f+a.s*b.s;
}

double cross(pii a,pii b){
  return a.f*b.s-a.s*b.f;
}

double norm(pii a){
  return sqrt(a.f*a.f+a.s*a.s);
}

int ccw(pii a, pii b, pii c) {
  b.f -= a.f; 
  b.s -= a.s; 
  c.f -= a.f;
  c.s -= a.s;
  if (cross(b, c) > 0)   return +1;
  if (cross(b, c) < 0)   return -1;
  if (dot(b, c) < 0)     return +2;
  if (norm(b) < norm(c)) return -2;
  return 0;
}

bool isCross(pii a1,pii a2,pii b1,pii b2){
  return ccw(a1,a2,b1)*ccw(a1,a2,b2)<=0 &&
    ccw(b1,b2,a1)*ccw(b1,b2,a2)<=0;
}

int main(void){
  
  int na,nb;
  cin >> na >> nb;
  
  vector<pii>a(na),b(nb);
  
  for(int i=0;i<na;i++)cin >> a[i].f >> a[i].s;
  for(int i=0;i<nb;i++)cin >> b[i].f >> b[i].s;
  
  double ans=isCross(a[0],a[1],b[0],b[1])?INF:dist(a[0],a[1])+dist(b[0],b[1]);
  for(int i=2;i<na;i++){
    double d=dist(a[0],a[i])+dist(a[i],a[1]);
    if(!isCross(a[0],a[i],b[0],b[1]) && 
       !isCross(a[i],a[1],b[0],b[1]))ans=min(ans,d+dist(b[0],b[1]));
    
    for(int j=2;j<na;j++){
      if(!isCross(a[0],a[i],b[0],b[1]) &&
	 !isCross(a[i],a[j],b[0],b[1]) &&
	 !isCross(a[j],a[1],b[0],b[1]))
	ans=min(ans,dist(a[0],a[i])+dist(a[i],a[j])+dist(a[j],a[1])+dist(b[0],b[1]));
    }
  }
  
  for(int i=2;i<nb;i++){
    double d=dist(b[0],b[i])+dist(b[i],b[1]);
    if(!isCross(b[0],b[i],a[0],a[1]) &&
       !isCross(b[i],b[1],a[0],a[1]))ans=min(ans,d+dist(a[0],a[1]));
    
    for(int j=2;j<nb;j++){
      if(!isCross(b[0],b[i],a[0],a[1]) &&
	 !isCross(b[i],b[j],a[0],a[1]) &&
	 !isCross(b[j],b[1],a[0],a[1]))
	ans=min(ans,dist(b[0],b[i])+dist(b[i],b[j])+dist(b[j],b[1])+dist(a[0],a[1]));
    }    
  }
  
  if(ans==INF)cout << -1 << endl;
  else {
    printf("%.9f",ans);
    cout << endl;
  }

  return 0;
}
