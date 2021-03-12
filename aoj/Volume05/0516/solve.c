#include<stdio.h>

int main(void){
  int i,n,k,a[100001],sum,ans;
  
  while(scanf("%d %d",&n,&k),n,k){
    ans=sum=0;
    for(i=0;i<n;i++)scanf("%d",&a[i]);

    for(i=0;i<k;i++)sum+=a[i];

    for(i=0;k<n;i++,k++){
      sum+=a[k]-a[i];
      ans=(ans>sum)?ans:sum;
    }
    printf("%d\n",ans);
  }
  return 0;
}
