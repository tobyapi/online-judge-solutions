#include<stdio.h>
#define swap(a,b) a^=b^=a^=b

int partition(int *A,int p,int r){
  int x=A[r],i=p-1,j;
  for(j=p;j<r;j++){
    if(A[j]<=x){
      i=i+1;
      swap(A[i],A[j]);
    }
  }
  swap(A[i+1],A[r]);
  return i+1;
}

int main(void){

  int n,A[100000],i;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  int res = partition(A,0,n-1);
  for(i=0;i<n;i++){
    if(i==res)printf("[%d]",A[i]);
    else printf("%d",A[i]);    
    if(i<n-1)printf(" ");
  }
  printf("\n");
  return 0;
}
