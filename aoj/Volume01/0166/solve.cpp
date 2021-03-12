#include<iostream>
#include<cmath>

using namespace std;

double EPS=1e-10;
double pi=3.1415926535;

double calc(int x) {
  return sin((double)x*pi/180.0);
}
 

int main(void){
  int n,m;
  
  while(true){
    cin >> n;
    if(n==0)break;
    double sum1=0,sum2=0,s1=0,s2=0,v,s=360;
   
    for(int i=0;i<n-1;i++){
      cin >> v;
      s-=v;
      s1+=calc(v);
    }
    s1+=calc(s);
    cin >> m;
    s=360;
    for(int j=0;j<m-1;j++){
      cin >> v;
      s-=v;
      s2+=calc(v);
    }
    s2+=calc(s);
    if(s1>s2+EPS) cout << 1 << endl;
    else if(s1+EPS<s2) cout << 2 << endl;
    else cout << 0 << endl;
  }

  return 0;
}
