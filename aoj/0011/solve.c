#include<stdio.h>
#define rep(i,n) for((i)=0;(i)<(int)(n);(i)++)
int main(void){
  int x,y,a,b,i,num[30],t;

  scanf("%d %d",&y,&x);
  rep(i,y)num[i]=i+1;

  rep(i,x){
      scanf("%d,%d",&a,&b);
      t=num[a-1];
      num[a-1]=num[b-1];
      num[b-1]=t;
    }  
  rep(i,y)printf("%d\n",num[i]);
  
  return 0;
}
