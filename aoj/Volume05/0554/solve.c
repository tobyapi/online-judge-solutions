#include <stdio.h>
int main(void) {
  
  int a[4],i,sum;
  a[3]=0;
  sum=0;
  
  for(i=0;i<4;i++){
    scanf("%d",&a[i]);
  }
  sum=a[0]+a[1]+a[2]+a[3];
  
  printf("%d\n%d\n",sum/60,sum%60);
  
  return 0;
}
