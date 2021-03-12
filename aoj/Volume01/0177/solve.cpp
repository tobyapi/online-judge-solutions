#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<cstdio>

#define all(c) (c).begin(),(c).end()

using namespace std;

const double R=6378.10;
const double PI=3.1415926535;
const double EPS=1e-10;
const double toRad=360.0/2.0/PI;

int main(void){
  double a,b,c,d;
  while(cin >> a >> b >> c >> d){
    if(a<0 && b<0 && c<0 && d<0)break;
    a/=toRad,b/=toRad,c/=toRad,d/=toRad;
    double ax=cos(b)*cos(a),ay=sin(b)*cos(a),az=sin(a);
    double bx=cos(d)*cos(c),by=sin(d)*cos(c),bz=sin(c);
    double D=sqrt(pow(ax-bx,2)+pow(ay-by,2)+pow(az-bz,2));
    double rad=acos(1-D*D/2);
    printf("%.0f",round(R*rad));
    cout << endl;
  }
  return 0;
}
