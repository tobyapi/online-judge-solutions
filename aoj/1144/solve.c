#include<stdio.h>
#include<string.h>

void search(int,int,int);

int g[100][100],start[2],h,w,ans;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int main(void){
  
  int i,j;

  while(scanf("%d %d",&w,&h),w,h){
    
    memset(g,-1,sizeof(g));

    for(i=1;i<=h;i++){
      for(j=1;j<=w;j++){
	scanf("%d",&g[i][j]);
	if(g[i][j]==2){
	  g[i][j]=0;
	  start[0]=i,start[1]=j;
	}
      }
    }
    
    ans=100000000;
    search(start[0],start[1],0);
    if(ans==100000000)ans=-1;
    printf("%d\n",ans);
  }
  return 0;
}

void search(int x,int y,int turn){

  int i,nx,ny;

  if(g[x][y]==3){
    ans=ans<turn?ans:turn;
    return;
  }
 if(turn>=10||turn>=ans)return;
  for(i=0;i<4;i++){
    if(g[x+dx[i]][y+dy[i]]!=1){
    nx=x,ny=y;
    while(1){
      nx+=dx[i],ny+=dy[i];
      if(g[nx][ny]!=0)break;
    }
    if(g[nx][ny]==-1)continue;
    if(g[nx][ny]==1){
      g[nx][ny]=0;
      search(nx-dx[i],ny-dy[i],turn+1);
      g[nx][ny]=1;
    }
    else if(g[nx][ny]==3)search(nx,ny,turn+1);
    }
  }

}
