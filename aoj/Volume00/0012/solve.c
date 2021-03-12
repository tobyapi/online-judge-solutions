#include<stdio.h>
#include<math.h>

#define SQ(x) (x)*(x)
#define EPS (1e-10)
#define EQ(a,b) (fabs((a)-(b)) < EPS)

int main(void){

  double x[4],y[4],S,s,a,b,c,sum;

  while(~scanf("%lf %lf %lf %lf %lf %lf %lf %lf"
	      ,&x[1],&y[1],&x[2],&y[2],&x[3],&y[3],&x[0],&y[0])){
    
    sum=0;

    a=sqrt(SQ(x[1]-x[2])+SQ(y[1]-y[2]));
    b=sqrt(SQ(x[3]-x[2])+SQ(y[3]-y[2]));
    c=sqrt(SQ(x[1]-x[3])+SQ(y[1]-y[3]));

    s=(a+b+c)/2;
    S=sqrt(s*(s-a)*(s-b)*(s-c));

    a=sqrt(SQ(x[0]-x[2])+SQ(y[0]-y[2]));
    b=sqrt(SQ(x[3]-x[2])+SQ(y[3]-y[2]));
    c=sqrt(SQ(x[0]-x[3])+SQ(y[0]-y[3]));

    s=(a+b+c)/2;
    sum+=sqrt(s*(s-a)*(s-b)*(s-c));

    a=sqrt(SQ(x[1]-x[0])+SQ(y[1]-y[0]));
    b=sqrt(SQ(x[3]-x[0])+SQ(y[3]-y[0]));
    c=sqrt(SQ(x[1]-x[3])+SQ(y[1]-y[3]));

    s=(a+b+c)/2;
    sum+=sqrt(s*(s-a)*(s-b)*(s-c));

    a=sqrt(SQ(x[1]-x[2])+SQ(y[1]-y[2]));
    b=sqrt(SQ(x[0]-x[2])+SQ(y[0]-y[2]));
    c=sqrt(SQ(x[1]-x[0])+SQ(y[1]-y[0]));

    s=(a+b+c)/2;
    sum+=sqrt(s*(s-a)*(s-b)*(s-c));

    if(EQ(S,sum))printf("YES\n");
    else printf("NO\n");
  }

  return 0;
}
