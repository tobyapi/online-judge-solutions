#include<stdio.h>
#define cls(x,n,i) else if((i)>=(double)(x) && (double)(x)>(n))

int main(void){
  double w;

  while(scanf("%lf",&w)!=EOF){
    if(w>91)printf("heavy\n");
    cls(w,81,91)printf("light heavy\n");
    cls(w,75,81)printf("middle\n");
    cls(w,69,75)printf("light middle\n");
    cls(w,64,69)printf("welter\n");
    cls(w,60,64)printf("light welter\n");
    cls(w,57,60)printf("light\n");
    cls(w,54,57)printf("feather\n");
    cls(w,51,54)printf("bantam\n");
    cls(w,48,51)printf("fly\n");
    else printf("light fly\n");
  } 
  return 0;
}
