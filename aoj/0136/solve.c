#include <stdio.h>

int main(void){  
  int n,i,j,res[7];
  double a;
  char b='*';
     
  res[1]=0;  
  res[2]=0;
  res[3]=0;
  res[4]=0;
  res[5]=0;
  res[6]=0;
  
  scanf("%d",&n);
  
  for(i=1;i<n+1;i++){
    
    scanf("%lf",&a);
    
    if( a < 165.0 ){
      res[1]=res[1]+1;
    }
    else if( a >= 165.0 && a < 170.0 ){
      res[2]=res[2]+1;
    }
    else if( a >= 170.0 && a < 175.0 ){
      res[3]=res[3]+1;
    }
    else if( a >= 175.0 && a < 180.0 ){
      res[4]=res[4]+1;
    }
    else if( a >= 180.0 && a < 185.0 ){
      res[5]=res[5]+1;
    }
    else{
      res[6]=res[6]+1;
    }
  }
  
  for( n=1 ; n<7 ; n++ ){
    printf("%d:",n);

    j=1;    
    while( j < res[n]+1 ){
      printf("%c",b);
      j = j + 1;
    }
    printf("\n");
  }
  return 0;
}
