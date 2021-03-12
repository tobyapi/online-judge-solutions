#include<stdio.h>
#include<string.h>

int main(void){
  int n,m,i,j,k,fg;
  char ch,str[2][100];


  while(scanf("%d\n",&n),n){
    for(i=0,j=0;i<n;i++,j++){
      scanf("%c %c\n",&str[0][i],&str[1][i]);
    }
    scanf("%d\n",&m);
    for(k=0;k<m;k++){
      scanf("%c\n",&ch);
      fg=0;
      for(i=0;i<j+1;i++){
	if(ch==str[0][i]){
	  printf("%c",str[1][i]);
	  fg=1;
	  break;
	}
      }
      if(!fg)printf("%c",ch);
    }
    printf("\n");
  }
  
  return 0;
}
