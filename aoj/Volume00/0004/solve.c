#include<stdio.h>
int main(void){
  
  double x=0,y=0;
  int a,b,c,d,e,f,p=0,q=0,r=0,s=0;
  
  while(scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f)!=EOF)
    {
      p=a*e-b*d;
      q=c*e-b*f;
      x=(double)q/p;
      
      r=b*d-a*e;
      s=c*d-a*f;
      y=(double)s/r;
      
      if(x==-0)x=0;
      if(y==-0)y=0;

      printf("%.3f %.3f\n",x,y);
    }
  return 0;
}
