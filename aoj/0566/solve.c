#include<stdio.h>

int x[101],ans[101][101];

int main(void){

  int n,i,j,a,b,c,d,res=0;

  scanf("%d",&n);

  while(~scanf("%d %d %d %d",&a,&b,&c,&d)){
    if(c>d)x[a]+=3;
    else if(c==d){x[a]+=1;x[b]+=1;}
    else x[b]+=3;
  }

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      if(res<=x[j]){a=j;res=x[j];}
    }

    for(j=1;j<=n;j++){
      if(res==x[j])ans[i][j]=1;
    }
    x[a]=-1;
    res=0;
  }

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      if(ans[j][i]==1){
	printf("%d\n",j);
	break;
      }
    }
  }
  return 0;
}
