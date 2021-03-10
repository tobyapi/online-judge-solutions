#include<stdio.h>

int main(void){
  int x[7],n,a,i;

  while(scanf("%d",&n),n){

    for(i=0;i<7;i++)
      x[i]=0;

    for(i=0;i<n;i++){
      scanf("%d",&a);
      if(a<10)x[0]++;
      else if(10<=a && a<20)x[1]++;
       else if(20<=a && a<30)x[2]++;
       else if(30<=a && a<40)x[3]++;
       else if(40<=a && a<50)x[4]++;
       else if(50<=a && a<60)x[5]++;
       else if(60<=a)x[6]++;
    }

    for(i=0;i<7;i++)
      printf("%d\n",x[i]);
  }
  return 0;
}
