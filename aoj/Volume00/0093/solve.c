#include<stdio.h>

int main(void){
  int a,b,i,j=1,flag;
  
  while(scanf("%d %d",&a,&b),a,b)
    {
      flag=0;

      if(j!=1)printf("\n");
      
      for(i=a;i<=b;i++){
	  if(i%100==0 && i%400==0){
	      printf("%d\n",i);
	      flag=1;
	    }
	  else if(i%4==0 && i%100!=0){
	      printf("%d\n",i);
	      flag=1;	    
	    }
	}
      
      if(flag==0)printf("NA\n");
      
      j++;
    }
  return 0;
}
