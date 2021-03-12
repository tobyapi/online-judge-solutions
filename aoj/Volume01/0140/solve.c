#include<stdio.h>

int main(void){
  int st[25]={0,1,2,3,4,5,6,7,8,9,5,4,3,2,1,0,1,2,3,4,5,6,7,8,9};
  int n,s,g,i;
  scanf("%d",&n);
  
  while(n--){
    scanf("%d %d",&s,&g);

      for(i=(s>g&&s<6)?15-s:s;st[i]!=g;i++)
	printf("%d ",st[i]);
      printf("%d\n",st[i]);

  }
  return 0;
}
