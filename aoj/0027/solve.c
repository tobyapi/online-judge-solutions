#include<stdio.h>

int main(void){
  int i,j,sum,a,b;
  
  while(1){
    sum=0;
    scanf("%d %d",&a,&b);
    if(a==0 && b==0)break;
    for(i=1;i<=a;i++){
      for(j=1;j<=31;j++){
	sum++;
	if(i==a && j==b)break;
	if(i==2 && j==29)break;
	if(i<=7 && i%2==0 && j==30)break;
	if(i>=8 && i%2==1 && j==30)break;

      }
    }
    switch(sum%7){
    case 1:
      printf("Thursday\n");
      break;
    case 2:
      printf("Friday\n");
      break;
    case 3:
      printf("Saturday\n");
      break;
    case 4:
      printf("Sunday\n");
      break;
    case 5:
      printf("Monday\n");
      break;
    case 6:
      printf("Tuesday\n");
      break;
    case 0:
      printf("Wednesday\n");
      break;
    }
    //printf("%d\n",sum);
  }
  return 0;
}
