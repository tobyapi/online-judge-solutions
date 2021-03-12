#include<stdio.h>

int main(void){
  int n,ans;
  while(ans=0,scanf("%d",&n),n){
    while(n/=5)ans+=n;
    printf("%d\n",ans);
  }
  return 0;
}
