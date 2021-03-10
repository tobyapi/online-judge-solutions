#include<stdio.h>
int main(void){

  int n,a,i=0,sum=0;

  while(1){
    scanf("%d",&n);
    if(n==0)break;
    
    for(i=n/4;i>0;i--)
      { 
	scanf("%d",&a);
	//	printf("%d\n",a);
	sum += a;
      }
    // printf("a:%d\n",a);
    
    printf("%d\n",sum); 
    sum=0; 
  }
  
  return 0;
}
