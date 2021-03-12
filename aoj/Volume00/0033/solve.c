#include<stdio.h>
int main(void){

  int N,x,i,j,B=0,C=1,flag=0;

  scanf("%d",&N);

  for(i=0;i<N;i++){
      flag=0;
      B=0;
      C=1;
      for(j=0;j<10;j++){
	  scanf("%d",&x);
	  if(B>C && x>B)B=x;
	  else if(B>C && x<B && x>C)C=x;
	  else if(B<C && x>C)C=x;
	  else if(B<C && x<C && x>B)B=x;
	  else {flag=1; break;}
	}
      if(flag)printf("NO\n");
      else printf("YES\n");
}

  return 0;
}
