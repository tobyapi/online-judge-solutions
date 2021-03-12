#include<stdio.h>

int main(void){
  int a,b,c,count1=0,count2=0;
  
  while(scanf("%d,%d,%d",&a,&b,&c)!=EOF){
    if(c*c==a*a+b*b && (a!=b && b!=c))count1++;
    else if((a==b&&b!=c)||(a==b && b==c))count2++;
  }
  printf("%d\n%d\n",count1,count2);
  
  return 0;
}
