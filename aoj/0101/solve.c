#include<stdio.h>
#include<string.h>

int main(void){
  int n,i,j,flag,k;
  char str[1001],ch[8]="Hoshino";

  scanf("%d",&n);
  scanf("%c",&str[0]);

  for(k=0;k<n;k++){
  scanf("%[^\n]%*c",str);
  
  for(i=0;i<strlen(str);i++){
    flag=0;
    for(j=0;j<7;j++){
      if(str[i+j]==ch[j])flag++;
    }
    if(flag==7)str[i+6]='a';
  }
  printf("%s\n",str);
  }
  return 0;
}
