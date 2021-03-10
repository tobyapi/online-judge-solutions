#include<stdio.h>

int main(void){
  int n,i,j;
  double x[4],y[4],t;

  scanf("%d",&n);

  for(i=0;i<n;i++){

    for(j=0;j<4;j++)
      scanf("%lf%lf",&x[j],&y[j]);

    for(j=0;j<4;j+=2){
      if(x[j]<x[j+1]){
	t=x[j];
	x[j]=x[j+1];
	x[j+1]=t;
	t=y[j];
	y[j]=y[j+1];
	y[j+1]=t;
      }
    }

    if((x[0]-x[1])/(y[0]-y[1])==(x[2]-x[3])/(y[2]-y[3]))printf("YES\n");
    else printf("NO\n");
  }

  return 0;
}
