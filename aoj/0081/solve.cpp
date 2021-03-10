#include<stdio.h>

int main(void){

  double x1,y1,x2,y2,xq,yq;
  double xa,ya,xb,yb,x,y,t1,t2;
  while(~scanf("%lf,%lf,%lf,%lf,%lf,%lf",&x1,&y1,&x2,&y2,&xq,&yq)){
    
    xa=xq-x1,ya=yq-y1;
    xb=x2-x1,yb=y2-y1;

    t1=xa*xb+ya*yb,t2=xb*xb+yb*yb;

    x=2*(x1+xb*t1/t2)-xq;
    y=2*(y1+yb*t1/t2)-yq;
    
    printf("%lf %lf\n",x,y);
  }
  return 0;
}
