#include<stdio.h>

int aux(int,int,int,int,int);

int main(void){
    int p,q,a,n;

    while(scanf("%d %d %d %d",&p,&q,&a,&n),p,q,a,n)
      printf("%d\n",aux(1,p,q,a,n));

  return 0;
}

int aux(int last,int P,int Q,int A,int N){
  int count=0,y;
  if(P==0)return 1;
  if(N<=0)return 0;

  for(y=last;y<=A;y++)
    if(Q<=y*P)count+=aux(y,P*y-Q,Q*y,A/y,N-1);

  return count;
}
