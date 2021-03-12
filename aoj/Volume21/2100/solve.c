#include<stdio.h>

int main(void){
  int n,m,h[100],i,j,maxup,maxdown;

  scanf("%d",&n);

  while(n--){
    scanf("%d",&m);

    for(i=0;i<m;i++){
      scanf("%d",&h[i]);
    }

    maxup=maxdown=0;

    for(i=0;i<m-1;i++){
      j=h[i]-h[i+1];
      if(j>0)maxdown=maxdown<j?j:maxdown;
      else maxup=maxup>j?j:maxup;
    }
    printf("%d %d\n",-1*maxup,maxdown);
  }

  return 0;
}
