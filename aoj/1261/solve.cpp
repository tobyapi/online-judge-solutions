#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define INF (1<<29)
using namespace std;
 
const double EPS=1e-10;
 
struct rod{
  double l,r,w;
  rod(double l=0,double r=0,double w=INF):l(l),r(r),w(w){}
};
 
rod Merge(rod a,rod b){
  rod res;
  res.w=a.w+b.w;
  double mid=b.w/(a.w+b.w);
  res.l=min(-b.w/(a.w+b.w)+a.l,b.l+(1-mid));
  res.r=max(a.w/(a.w+b.w)+b.r,a.r-mid);
  return res;
}

double r,ans;
 
void rec(vector<rod>v){
  int vl=v.size();
  if(vl<=1){
    double res=v[0].r-v[0].l;
    if(res<r-EPS)ans=max(ans,res);
    return;
  }
  for(int i=0;i<vl;i++){
    for(int j=0;j<vl;j++){
      if(i==j)continue;
      vector<rod>nx;
      for(int k=0;k<vl;k++){
        if(k==i || k==j)continue;
        nx.push_back(v[k]);
      }
      nx.push_back(Merge(v[i],v[j]));
      rec(nx);
    }
  }
 
}
 
int main(void){
 
  int T;
  cin >> T;
  while(T--){
    int s;
    cin >> r >> s;
    vector<rod>v(s);
    for(int i=0;i<s;i++)cin >> v[i].w;
    ans=-INF;
    rec(v);
    if(ans<0)cout << -1 << endl;
    else printf("%.16f\n",ans);
  }
  return 0;
}
