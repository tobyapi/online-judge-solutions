#include<stdio.h>

void dfs(int,int);

int h,w,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
char grid[101][101];

int main(void){
  int i,j,count;

  while(scanf("%d %d",&h,&w),h,w){

    for(i=0;i<h;i++)
      for(j=0;j<w;j++)
	scanf(" %c",&grid[i][j]);

    count=0;
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
	if(grid[i][j]!='$'){
	  count++;
	  dfs(i,j);
	}
      }
    }

    printf("%d\n",count);
  }

  return 0;
}

void dfs(int y,int x){
  char ch=grid[y][x];
  int i;
  
  grid[y][x]='$';
  for(i=0;i<4;i++){
    if(grid[y+dy[i]][x+dx[i]]==ch && 
       y+dy[i]>=0 && y+dy[i]<h && x+dx[i]>=0 && x+dx[i]<w)
      dfs(y+dy[i],x+dx[i]);
  }

}
