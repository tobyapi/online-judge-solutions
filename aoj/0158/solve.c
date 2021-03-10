#include<stdio.h>
int main(void){
  
  int n,i;
  
  while(scanf("%d",&n),n){
      i=0;
      while(n!=1){
	  i++;
	  if(n%2==0)n=n/2;
	  else n=3*n+1;
	}
      printf("%d\n",i);
    }
  return 0;
}
