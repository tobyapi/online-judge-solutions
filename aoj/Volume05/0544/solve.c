#include<stdio.h>

int main(void){
  int n,m,i,s[1002],d[1002],now;
  
  while(scanf("%d %d",&n,&m),n|m){
    for(i=1;i<=n;i++)scanf("%d",&s[i]);
    for(i=1;i<=m;i++)scanf("%d",&d[i]);

    now=1;
    for(i=1;i<=m+1;i++){
      if(now>=n){
	printf("%d\n",i-1);
	break;
      }
      now+=d[i];
      now+=s[now];
    }
  }


  return 0;
}
