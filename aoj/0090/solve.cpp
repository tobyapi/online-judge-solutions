#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
 
using namespace std;
 
typedef pair<double,double> P;
double EPS=1e-10;
 
int main(void){
  int n;
  double x[100],y[100];
 
  while(cin >> n,n){
    vector<P>d;
 
    for(int i=0;i<n;i++)
      scanf("%lf,%lf",&x[i],&y[i]);
     
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
    double L=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
    if(L>2.0000)continue;
    double theta=atan2(y[j]-y[i],x[j]-x[i]);
    double a=acos(L/2);
    d.push_back(make_pair(x[i]+cos(theta+a),y[i]+sin(theta+a)));
    d.push_back(make_pair(x[i]+cos(theta-a),y[i]+sin(theta-a)));
      }
    }
 
    int count,ans=1;
    for(int i=0;i<d.size();i++){
      count=0;
       
      for(int j=0;j<n;j++){
    if(pow(d[i].first-x[j],2)+pow(d[i].second-y[j],2)<=1.0+EPS){
      count++;
    }
      }
    ans=max(ans,count);
    }
    cout << ans << endl;
  }
  return 0;
}
