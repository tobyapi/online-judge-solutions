#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include<cfloat>

using namespace std;

typedef pair<double, double>P;

int N;
const double INF=1000000000;
P A[1000000];

bool comp_y(P a,P b){
  return a.second<b.second;
}

double closest_pair(P *a, int n){
  if(n<=1)return INF;
  int m=n/2;
  double x=a[m].first;
  double d=min(closest_pair(a,m),closest_pair(a+m,n-m));
  inplace_merge(a,a+m,a+n,comp_y);

  vector<P>b;
  for(int i=0;i<n;i++){
    if(abs(a[i].first-x)>=d)continue;
    for(int j=0;j<b.size();j++){
      double dx = a[i].first-b[b.size()-j-1].first;
      double dy = a[i].second-b[b.size()-j-1].second;
      if(dy>=d)break;
      d=min(d,dx*dx+dy*dy);
    }
    b.push_back(a[i]);
  }
  return d;
}

int main(void){

  P in;

  cin >> N;
    for(int i=0;i<N;i++){
      cin >> in.first >> in.second;
      A[i]=in;
    }
    sort(A,A+N);
    double ans=closest_pair(A,N);
    cout << ans << endl;
  
  return 0;
}
