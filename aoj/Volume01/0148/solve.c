#include<stdio.h>

int main(void){
  int n,i;
  
  while(scanf("%d",&n)!=EOF){
      if(n>39)n=n%39;
      if(n==0){
	  printf("3C39\n");
	}
      for(i=1;i<40;i++){
	  if(i==n){
	      if(i>9)printf("3C%d\n",i);
	      else printf("3C0%d\n",i);
	      break;
	    }
	}
    }
  return 0;
}
