#include<stdio.h>
#define INF 1000000000
void MST(int);

int edge[101][101],v[101],d[101],sum=0,n;

int main(void){

  int m,a,b,i,j, cost;

  while(1){
      scanf("%d",&n);
      if(n==0)break;

      scanf("%d",&m);

      for(i=0;i<101;i++){
	  for(j=0;j<101;j++){
	      edge[i][j]=INF;
	    }
	}

      for(i=0;i<m;i++){
	scanf("%d,%d,%d",&a,&b,&cost);
	edge[a][b]=cost;
	edge[b][a]=cost;
	 }

      for(i=0;i<101;i++){
	d[i]=INF;
	v[i]=0;
      }

      d[0]=0;
      sum = 0;
      MST(0);

      printf("%d\n",sum);
    }

  return 0;
}

void MST(int u){
  int x=0,i;

  while(1){
    int minv=INF;

    for(i=0;i<n;i++){
      if(v[i]==0 &&  d[i]<minv){
	x=i;
	minv=d[i];
      }
    }
    if(minv==INF)break;  

    v[x]=1;
    if ( x != u ) sum+=(d[x]/100-1);
    
    for(i=0;i<n;i++){
      if ( v[i] ) continue;
      d[i]=min(d[i],edge[x][i]);
    }
  }
}

int min(int x,int y){
  return x < y ? x : y;
 }
