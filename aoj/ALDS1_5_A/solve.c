#include<stdio.h>

int n,q,a[2001],m;

int rec(int i,int sum){
  if(sum==m)return 1;
  if(i>=n)return 0;
  return rec(i+1,sum) || rec(i+1,sum+a[i]);
}

int main(void){

  int i,j;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&a[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&m);
    if(rec(0,0))printf("yes\n");
    else printf("no\n");
  }
  return 0;
}
