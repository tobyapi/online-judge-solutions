#include<stdio.h>
#include<string.h>
int main(void){
  char str[10001];
  int i,j,a,b;

  while(scanf("%[^\n]%*c",str)!=EOF){
    a=b=0;
    for(i=0;i<strlen(str);i++){
      if(str[i+1]=='O' && str[i+2]=='I'){
	if(str[i]=='J')a++;
	else if(str[i]=='I')b++;
      }
    }
    printf("%d\n%d\n",a,b);
  }
  return 0;
}
