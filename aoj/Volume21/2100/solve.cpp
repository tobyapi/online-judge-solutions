#include<stdio.h>

int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}

int main(void){

  int t,n,h[101],i,up=0,down=0;

  scanf("%d",&t);

  while(t--){
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&h[i]);
    for(i=up=down=0;i<n-1;i++){
      up=max(up,h[i+1]-h[i]);
      down=min(down,h[i+1]-h[i]);
    }
    printf("%d %d\n",up,-down);
  }
  return 0;
}
