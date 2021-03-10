#include<stdio.h>
#include<stdio.h>
int main(void){
  int x,count[4]={0,0,0,0};
  char str[3];
  while(scanf("%d,%s",&x,str)!=EOF){
    if(str[0]=='B')count[1]++;
    else if(str[0]=='O')count[3]++;
    else {
      if(str[1]=='B')count[2]++;
      else count[0]++;
    }
  }
  for(x=0;x<4;x++)
    printf("%d\n",count[x]);
  return 0;
}
