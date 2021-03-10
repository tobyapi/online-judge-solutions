#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct point{
  double x, y;
};

bool cmp_x(const point& p, const point& q){
  if(p.x != q.x)return p.x>q.x;
  return p.y < q.y;
}

int main(void){
  int n;
  point a;
  vector<point>v;

  cin >> n;
  while(n--){
    cin >> a.y >> a.x;
    v.push_back(a);
  }

  sort(v.begin(),v.end(),cmp_x);

  cout << v[0].y << " "<< v[0].x <<endl;

  return 0;
}
