#include<stdio.h>

int main(void){
  int n;
  double y,v;

  while(1){
    int c=scanf("%lf",&v);
    if(c==EOF)return 0;
    y=4.9*(v/9.8)*(v/9.8);
    n=0;
    while(1){
      if(5*n-5>=y)break;
	n++;
    }
    printf("%d\n",n);
  }
  return 0;
}
