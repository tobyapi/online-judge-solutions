#include<stdio.h>

int main(void){
  int x,count[101],i,max=0;
  
  for(i=0;i<101;i++)
    count[i]=0;
  
  while(scanf("%d",&x)!=EOF){
    count[x]++;
  }

  for(i=0;i<101;i++)
    if(max<count[i])max=count[i];

  for(i=0;i<101;i++)
    if(count[i]==max)printf("%d\n",i);
  return 0;
}
