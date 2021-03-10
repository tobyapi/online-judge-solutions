#include<stdio.h>

void dfs(int,int);
int a,b,dp[20][20];

int main(void){
  int i,j,n,c,d,flag1,flag2,max;

  while(scanf("%d %d",&a,&b),a,b){
    scanf("%d",&n);

    max = a>b?a:b;

    for(i=0;i<a;i++)
      for(j=0;j<b;j++)
	dp[i][j]=-1;

    for(i=0;i<max;i++){
      dp[i][0]=1;
      dp[0][i]=1;
}
    for(i=0;i<n;i++){
      scanf("%d %d",&c,&d);
      dp[c-1][d-1]=0;
    }

    flag1=flag2=0;
    for(i=0;i<max;i++){
      if(dp[0][i]==0)flag1=1;
      if(dp[i][0]==0)flag2=2;
      if(flag1==1)dp[0][i]=0;
      if(flag2==2)dp[i][0]=0;
}

    dfs(1,1);

    if(dp[a-1][b-1]<0)dp[a-1][b-1]=0;
    printf("%d\n",dp[a-1][b-1]);
}

  return 0;
}

void dfs(int x,int y){
  if(x==a || y==b)return ;

 if(dp[x][y]>0 || dp[x][y]<-1)return ;
  if(dp[x-1][y]>=0 && dp[x][y-1]>=0 && dp[x][y]==-1)dp[x][y]=dp[x-1][y]+dp[x][y-1];
  //if(x==a-1 && y==b-1)return ;
  dfs(x+1,y);
  dfs(x,y+1);
}
