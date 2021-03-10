#include<stdio.h>
int main(void){

  double h,Max=0,Min=1000000000;

  while(scanf("%lf",&h)!=EOF)
    {
      if(Max<h)Max=h;
      if(Min>h)Min=h;
}
  printf("%.1f\n",Max-Min);

  return 0;
}
