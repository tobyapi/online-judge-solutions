#include<stdio.h>

int min(int,int);

int main(void){
  int a,b,c,d,e;

  scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);

  printf("%d\n",min(a,min(b,c))+min(d,e)-50);

  return 0;
}

int min(int x,int y){
  return x<y?x:y;
}
