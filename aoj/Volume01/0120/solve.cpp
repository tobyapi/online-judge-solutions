#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<climits>
#include<cfloat>
#include<sstream>
#define all(c) (c).begin(),(c).end()
#define INF (1<<29)

using namespace std;


double dist(double p,double q){
  double a=p+q,b=abs(p-q);
  return sqrt(a*a-b*b);
}

int count(int bits){
  bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
  bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
  bits =(((bits >> 4) + bits) & 0x0f0f0f0f);
  bits += bits >> 8;
  return (bits + (bits >> 16)) & 0xff;
}

double dp[(1<<12)][12];

int main(void){

  string str;
  while(getline(cin,str)){
    int value;
    stringstream ss(str);
    vector<double>in;
    while(ss >> value)in.push_back(value);
    if(in.size()<1)break;
    double L=in[0];

    int m=in.size()-1;
    vector<double>p(m);
    for(int i=1;i<in.size();i++)p[i-1]=in[i];

    fill(dp[0],dp[1<<12],INF);
    for(int i=0;i<m;i++)dp[1<<i][i]=p[i];

    for(int S=0;S<(1<<m);S++){
      for(int v=0;v<m;v++){
	for(int u=0;u<m;u++){
	  if(S>>u&1 || !(S>>v&1))continue;
	  int nx=S;
	  nx|=(1<<u);
	  if(count(S)==m-1)dp[nx][u]=min(dp[nx][u],dp[S][v]+dist(p[v],p[u])+p[u]);
	  else dp[nx][u]=min(dp[nx][u],dp[S][v]+dist(p[v],p[u]));
	}
      }
    }
    double ans=INF;
    for(int i=0;i<m;i++)ans=min(ans,dp[(1<<m)-1][i]);
    if(ans<=L)cout << "OK" << endl;
    else cout << "NA" << endl;
  }
  return 0;
}
