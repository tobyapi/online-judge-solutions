#include<stdio.h>

int main(void){
  int n,r,p,c,i,j,card[52],temp[52];
  
  while(scanf("%d %d",&n,&r),n,r){
    for(i=0;i<51;i++)card[i]=i;

    for(i=0;i<r;i++){
      scanf("%d %d",&p,&c);
      
      for(j=0;j<c;j++){
	temp[n-j]=card[n-p+1-j];
      }

      for(j=1;j<=p-1;j++){
	card[n-(p-1)-c+j]=card[n-(p-1)+j];
      }

       for(j=0;j<c;j++){
	 card[n-j]=temp[n-j];
      }
    }
    printf("%d\n",card[n]);
  }


  return 0;
}
