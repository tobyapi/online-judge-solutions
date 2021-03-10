#include<stdio.h>

int main(void){
  int num;
  double w,h;

  while(scanf("%d,%lf,%lf",&num,&w,&h)!=EOF){
    if(w/(h*h)>=25)printf("%d\n",num);
  }
  return 0;
}
