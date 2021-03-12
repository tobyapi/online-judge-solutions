#include<stdio.h>

int n,A[2000000],B[2000000],C[10001],i;

int main(void){
  for(i=0;i<10001;i++)C[i]=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]),C[A[i]]++;
  for(i=1;i<10001;i++)C[i]+=C[i-1];
  for(i=n-1;i>=0;i--)B[C[A[i]]-1]=A[i],C[A[i]]--;
  for(i=0;i<n;i++)printf("%d%c",B[i],(i<n-1?' ':'\n'));

  return 0;
}
