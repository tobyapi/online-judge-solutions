#include<stdio.h>
#include<string.h>
#include<ctype.h>
char stack[1000000];
int top;

void push(char);
void pop(void);
int empty(void);

int main(void){
char str[101];
 int i,flag;
  while(1){
    scanf("%[^\n]%*c",str);
    if(str[0]=='.'&&strlen(str)==1)break;

    top=0;
    flag=1;
    for(i=0;i<strlen(str);i++){
      if(str[i]=='('||str[i]=='[')push(str[i]);
      else if((str[i]==')'&&stack[top-1]=='(')||(str[i]==']'&&stack[top-1]=='['))pop();
      else if((str[i]==')'||str[i]==']')&&empty()){flag=0;break;}
      else if((str[i]==']'&&stack[top-1]=='(')||(str[i]==')'&&stack[top-1]=='[')){flag=0;break;}
    }
    printf((flag && empty())?"yes\n":"no\n");
  }
  return 0;
}

void push(char x){
  stack[top]=x;
  top++;
}

void pop(void){
  top--;
}

int empty(void){
  return (top==0)?1:0;
}
