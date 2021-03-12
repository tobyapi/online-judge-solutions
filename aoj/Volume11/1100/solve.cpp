#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#define curr(P, i) P[(i) % P.size()]
#define next(P, i) P[(i+1) % P.size()]

using namespace std;

struct point{ double x, y; };

double areaPol(vector<point> t){
  double area=0;
  for(int i=0;i<t.size();i++)
    area+=(curr(t,i).x-next(t,i).x)*(curr(t,i).y+next(t,i).y);
  
  return abs(area)/2.0;
}

int main(void){
  int n,turn=1;
  point p;
  vector<point>t;

  while(cin >> n,n){
    t.clear();
    for(int i=0;i<n;i++){
      cin >> p.x >> p.y;
      t.push_back(p);
    }
    printf("%d %.1f\n",turn++,areaPol(t));
  }

  return 0;
}
