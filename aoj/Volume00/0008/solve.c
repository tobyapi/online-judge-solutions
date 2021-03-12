#include<stdio.h>
#define REP(i) for((i)=0;(i)<10;(i)++)

int main(void)

{

int i ,j ,k ,l ,m=0 ,n ;



while(scanf("%d",&n) != EOF)

{

m=0 ;


REP(i){REP(j){REP(k){REP(l){if(i+j+k+l==n)m++;}}}}


printf("%d\n",m) ;

}

return 0 ;

}
