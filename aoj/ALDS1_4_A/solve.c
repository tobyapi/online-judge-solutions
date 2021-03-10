#include<stdio.h>

int main(void){

  int n,q,cnt=0,a[10001],b[501],i,j;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&a[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&b[i]);

  for(i=0;i<q;i++)
    for(j=0;j<n;j++)
      if(a[j]==b[i]){cnt++;break;}
    
  printf("%d\n",cnt);

  return 0;
}
