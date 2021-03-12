#include<stdio.h>
#include<math.h>

int main(void){
  double xa,ya,ra,xb,yb,rb,N,m;

  scanf("%lf",&N);

  while(N--){
    scanf("%lf %lf %lf %lf %lf %lf",&xa,&ya,&ra,&xb,&yb,&rb);
    m=sqrt(pow(xa-xb,2)+pow(ya-yb,2));
    if(m<=ra+rb && m<ra-rb)printf("2\n");
    else if(m<=ra+rb && m<rb-ra)printf("-2\n");
    else if(m>ra+rb)printf("0\n");
    else printf("1\n");

  }

  return 0;
}
