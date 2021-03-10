#include<iostream>
#include<cstdio>

using namespace std;

int main(void){
  double xa[3],ya[3],xb[3],yb[3];

  while(true){
    for(int i=1;i<3;i++)
      if(scanf("%lf %lf",&xa[i],&ya[i])==EOF)return 0;
    
    for(int i=1;i<3;i++)
      scanf("%lf %lf",&xb[i],&yb[i]);

    if(xa[2]>=xb[1] && xb[2]>=xa[1] && ya[2]>=yb[1] && yb[2]>=ya[1])cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
