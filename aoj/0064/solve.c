#include<stdio.h>
#include<string.h>
 
int main(void){
  
  int ans,i,x;
  char str[100];
 
  memset(str,'a',sizeof(str));
  ans=0;
  while(~scanf("%s",str)){
    for(i=0;i<strlen(str);i++)
      if(str[i]<='9' && str[i]>='0'){
	for(x=0;str[i]<='9'&&str[i]>='0'&&i<strlen(str);i++){
	  x*=10;
	  x+=str[i]-'0';
	}
	i--;
	ans+=x;
      }
    
  }
  printf("%d\n",ans);
  return 0;
}
