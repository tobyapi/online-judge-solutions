#include<stdio.h>
int main(void){
  double left,right;
  int lA=0,lB=0,lC=0,lD=0;
  int rA=0,rB=0,rC=0,rD=0;
  
  while(scanf("%lf %lf",&left,&right)!=EOF){

      if(left>=1.1)lA++;
      else if(left>=0.6 && left<1.1)lB++;
      else if(left>=0.2 && left<0.6)lC++;
      else if(left<0.2)lD++;

      if(right>=1.1)rA++;
      else if(right>=0.6 && right<1.1)rB++;
      else if(right>=0.2 && right<0.6)rC++;
      else if(right<0.2)rD++;
    }
  printf("%d %d\n",lA,rA);
  printf("%d %d\n",lB,rB);
  printf("%d %d\n",lC,rC);
  printf("%d %d\n",lD,rD);
  
  return 0;
}
