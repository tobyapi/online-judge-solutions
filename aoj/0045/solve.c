#include<stdio.h>

int main(void){
  int x,y,sum=0,i=0;
  double ave=0;

  while(scanf(" %d,%d",&x,&y)!=EOF){
    sum+=x*y;
    ave+=(double)y;
    i++;
}
  ave=ave/i+0.5;
  printf("%d\n%.0f\n",sum,ave);
  return 0;
}
