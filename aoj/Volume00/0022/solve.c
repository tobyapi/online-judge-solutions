#include<stdio.h>

int max(int,int);

int main(void){
  int n,a,sum,m,v,i;
  
  while(1){
    m=0;
    v=-100000;
    sum=0;
    scanf("%d",&n);
    if(n==0)break;
    
    for(i=0;i<n;i++){
      scanf("%d",&a);
      m=max(0,m+a);
      sum=max(sum,m);
      v=max(v,a);
    }
    printf("%d\n",(v<0)?v:sum);
  }
  
  return 0;
}

int max(int x,int y){
  return (x>y)?x:y;
}
