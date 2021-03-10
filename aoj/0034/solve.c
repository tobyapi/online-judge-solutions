#include<stdio.h>

int main(void){
  int d[10],v[3],sum,ans,i,a,b;

  while(1){
    for(i=sum=0;i<10;i++){
      if(scanf("%d,",&d[i])==EOF)return 0;
      sum+=d[i];
    }      
      scanf("%d,%d",&v[1],&v[2]);

      ans=sum*v[2]/(v[2]+v[1]);
      for(i=9;i>=0;i--){
	ans-=d[i];
	if(ans<0){
	  printf("%d\n",i+1);
	  break;
	}
      }
  }
  return 0;
}
