#include<stdio.h>
#include<stdlib.h>

int MIN( const void *c1, const void *c2 );

int main(void){
  int N,n,d,i,x[402],y[402];
  
  while(1){
    scanf("%d",&N);
    if(N==0)break;
    
    x[0]=0;
    y[0]=0;
    
    if(N==1)printf("1 1\n");
    else {
      for(i=1;i<N;i++){
	
	scanf("%d %d",&n,&d);
	
	if(d==0){x[i]=x[n]-1; y[i]=y[n];}
	else if(d==2){x[i]=x[n]+1; y[i]=y[n];}
	else if(d==1){y[i]=y[n]-1; x[i]=x[n];}
	else if(d==3){y[i]=y[n]+1; x[i]=x[n];}
      }
      
      qsort(x,N,sizeof(int),MIN);
      qsort(y,N,sizeof(int),MIN);
      
      printf("%d %d\n",x[N-1]-x[0]+1,y[N-1]-y[0]+1);
    }
  }
  return 0;
}

int MIN( const void *c1, const void *c2 )
{
  int tmp1 = *(int *)c1;
  int tmp2 = *(int *)c2;
  
  if( tmp1 < tmp2 )  return -1;
  if( tmp1 == tmp2 ) return  0;
  if( tmp1 > tmp2 )  return  1;
}
