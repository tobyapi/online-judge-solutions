#include<stdio.h>

int main(void){
  int i,L,n[13],m[13],sum;

  while(scanf("%d",&L),L){
    
    sum=0;
    for(i=1;i<=12;i++){
      scanf("%d %d",&m[i],&n[i]);
    }
    for(i=1;i<=12;i++){
      sum+=m[i]-n[i];
      if(sum>=L)break;
    }
    
    if(sum<L)printf("NA\n");
    else printf("%d\n",i);

  }
  return 0;
}
