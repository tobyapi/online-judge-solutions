#include<stdio.h>

int a[100001],b[50001];

int main(void){

  int n,q,cnt=0,i,j;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&a[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&b[i]);

  for(i=0;i<q;i++){
    int l=0,r=n;
    while(r-l>1){
      int m=(l+r)/2;
      if(a[m] > b[i])r=m;
      else l=m;
    }
    cnt+=(a[l]==b[i] || a[r]==b[i]);
  }

  printf("%d\n",cnt);

  return 0;
}
