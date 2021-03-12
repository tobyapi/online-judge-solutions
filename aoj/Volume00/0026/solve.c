#include<stdio.h>
#include<stdlib.h>

int max(int,int);
void ink1(int,int);
void ink2(int,int);
void ink3(int,int);

int grid[14][14];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int main(void){

  int x,y,size,i,j,count=0,ans=0;

  memset(grid,0,sizeof(grid));

  while(~scanf("%d,%d,%d",&x,&y,&size)){
    if(size==1)ink1(y+2,x+2);
    else if(size==2)ink2(y+2,x+2);
    else if(size==3)ink3(y+2,x+2);

  }

  for(i=2;i<12;i++){
    for(j=2;j<12;j++){
      ans=max(ans,grid[i][j]);
      if(grid[i][j]==0)count++;
    }
  }

  printf("%d\n%d\n",count,ans);

  return 0;
}

int max(int a,int b){
  return a>b?a:b;
}

void ink1(int y,int x){
  int i;
  for(i=0;i<4;i++)
    grid[y+dy[i]][x+dx[i]]++;
  grid[y][x]++;
}

void ink2(int y,int x){
  int i,j;
  for(i=-1;i<2;i++)
    for(j=-1;j<2;j++)
      grid[y+i][x+j]++;

}

void ink3(int y,int x){
  int i,j;
  for(i=0;i<4;i++)
    grid[y+2*dy[i]][x+2*dx[i]]++;

  for(i=-1;i<2;i++)
    for(j=-1;j<2;j++)
      grid[y+i][x+j]++;
}
