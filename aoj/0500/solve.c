#include<stdio.h>

int main(void){
  int n,a,b,i;

  while(scanf("%d",&n),n){
    int Pa=0,Pb=0;
    for(i=0;i<n;i++){
      scanf("%d %d",&a,&b);
      if(a>b)Pa+=a+b;
      else if(a<b)Pb+=a+b;
      else {Pa+=a; Pb+=b;}
    }
    printf("%d %d\n",Pa,Pb);
  }
  return 0;
}
