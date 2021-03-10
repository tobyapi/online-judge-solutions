#include<stdio.h>

int main(void){
  int i,j,n,table[11][11],w;

  while(1){
    scanf("%d",&n);
    if(n==0)break;
    w=0;
    for(i=0;i<11;i++)
      table[n][i]=0;
    
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	scanf("%d",&table[i][j]);
	w+=table[i][j];
	if(j==n-1){
	  table[i][j+1]=w;
	  w=0;
	}
	table[n][j]+=table[i][j];
      }
    }

    for(i=0;i<n;i++){
      table[n][n]+=table[n][i];
}

    for(i=0;i<=n;i++){
      for(j=0;j<=n;j++){
	printf("%5d",table[i][j]);
	if(j==n)printf("\n");
      }
    }
  }

  return 0;
}
