#include<stdio.h>

int main(void){
  int w[10]={1,2,4,8,16,32,64,128,256,512};
  int i,n,ans[10],end;

  while(scanf("%d",&n)!=EOF){
    end=-1;
    for(i=0;i<10;i++)ans[i]=0;
    for(i=9;i>=0;i--){
      if(w[i]<=n){
	n-=w[i];
	ans[i]=1;
	if(end<0)end=i;
      }
    }
    for(i=0;i<10;i++){
      if(ans[i]==1 && i==end)printf("%d\n",w[i]);
     else if(ans[i]==1 && i!=end)printf("%d ",w[i]);
    }
}
  return 0;
}
