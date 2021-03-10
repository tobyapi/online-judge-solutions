#include<stdio.h>
#include<string.h>

void dfs(int,int);
char grid[102][102];

int main(void){

  int i,j,h,w;

  while(scanf("%d %d",&h,&w),h,w){
    
    for(i=0;i<h;i++)
      for(j=0;j<w;j++)
	scanf(" %c",&grid[i][j]);

    dfs(0,0);
  }
  return 0;
}

void dfs(int y,int x){

  char temp=grid[y][x];

  if(temp=='1'){
    printf("LOOP\n");
    return ;
  }

  if(temp=='.'){
    printf("%d %d\n",x,y);
  }

  grid[y][x]='1';
  if(temp=='>')dfs(y,x+1);
  else if(temp=='<')dfs(y,x-1);
  else if(temp=='^')dfs(y-1,x);
  else if(temp=='v')dfs(y+1,x);

}
