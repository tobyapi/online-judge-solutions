#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

struct point{double x, y;};

double areaPol(vector<point> t){
  t.push_back(t[0]);
  int tsz=t.size();
  double area=0;
  for(int i=0;i<tsz-1;i++){
    area+=(t[i].x-t[i+1].x)*(t[i].y+t[i+1].y);
  }
  return abs(area)/2.0;
}

int main(void){
  point p;
  vector<point>t;
  char k;

  while(cin>> p.x >> k >> p.y)t.push_back(p);

  printf("%.6f\n",areaPol(t));

  return 0;
}
