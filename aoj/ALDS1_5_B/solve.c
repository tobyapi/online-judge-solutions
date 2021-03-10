#include<stdio.h>

#define MAX_N 500001
#define INF (1<<30)

int cnt=0;
int L[MAX_N],R[MAX_N];

void merge(int *A,int left,int mid,int right){
  int i,j,k;
  
  int n1=mid-left;
  int n2=right-mid;
  
  for(i=0;i<n1;i++)L[i]=A[left+i];
  for(i=0;i<n2;i++)R[i]=A[mid+i];

  L[n1]=INF;
  R[n2]=INF;

  i=0;
  j=0;

  for(k=left;k<right;k++,cnt++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
    }
    else {
      A[k]=R[j];
      j=j+1;
    }
  }
}

void mergeSort(int *A,int left,int right){
  if(left+1<right){
    int mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int main(void){

  int n,A[MAX_N],i;
 
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);

  mergeSort(A,0,n);

  for(i=0;i<n;i++){
    printf("%d%c",A[i],(i<n-1?' ':'\n'));
  }  
  printf("%d\n",cnt);
  
  return 0;
}
