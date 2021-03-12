#include<stdio.h>

int main(void){
  int n,i,j,a[32],b,ohajiki;

  while(scanf("%d",&n),n){
      ohajiki=32;

      for(i=0;i<n;i++){
	scanf("%d",&a[i]);
      }
      i=0;
      j=0;
      while(ohajiki>1){
	  if(i%2==0){
	      b=(ohajiki-1)%5;
	      printf("%d\n",ohajiki-b);
	      ohajiki=ohajiki-b;
	    }
	  else{
	      printf("%d\n",ohajiki-a[j]);
	      ohajiki=ohajiki-a[j];
	      j++;
	    }
	  if(j==n)j=0;
	  i++;
	}
      printf("0\n");
    }
  return 0;
}
