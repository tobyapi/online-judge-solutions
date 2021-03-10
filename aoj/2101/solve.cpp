#include<stdio.h>

int main(void){

  int S,N,i;

  while(scanf("%d",&N),N){
    for(i=1,S=-N;i*i<N;i++)if(!(N%i))S+=i+N/i;

    if(S==N)printf("perfect number\n");
    else if(S<N)printf("deficient number\n");
    else if(S>N)printf("abundant number\n");
  }
  return 0;
}
