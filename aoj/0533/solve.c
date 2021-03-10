#include <stdio.h>
int main(void) {

  int w[10],k[10],wsum,ksum,i,j,n,m;
  n=0;
  m=0;

  for(i=0;i<10;i++){
    scanf("%d",&w[i]);
}
  for(i=0;i<10;i++){
    scanf("%d",&k[i]);
  }
  for(i=0;i<10;i++){
    for(j=i+1;j<10;j++){
      if(w[i]<w[j]){
	n=w[i];
	w[i]=w[j];
	w[j]=n;
      }
    }
  }
  wsum=w[0]+w[1]+w[2];

  for(i=0;i<10;i++){
    for(j=i+1;j<10;j++){
      if(k[i]<k[j]){
	m=k[i];
	k[i]=k[j];
	k[j]=m;
      }
    }
  }
  ksum=k[0]+k[1]+k[2];

  printf("%d %d\n",wsum,ksum);

  return 0;
}
