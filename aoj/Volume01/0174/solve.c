#include<stdio.h>
#include<string.h>

int max(int,int);

int main(void){
  char str[200];
  int a,b,i;
  
  while(1){
    for(i=0;i<200;i++){
      str[i]='\0';
    }
    scanf("%[^\n]%*c",str);
    a=0;
    b=0;
    if(str[0]=='0')break;
    
    for(i=1;str[i]!='\0';i++){  
      if(str[i]=='A')a++;
      else if(str[i]=='B')b++;
    }
    
    if(a==max(a,b))a++;
    else if(b==max(a,b))b++;
    printf("%d %d\n",a,b);
  }
  
  return 0;
}

int max(int x,int y){
  return (x<y)?y:x;
}
