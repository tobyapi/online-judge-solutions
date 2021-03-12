#include<stdio.h>

int main(void){
  long long x,emp[4001],val[4001];
  long long emp1,val1,con,flag;
  int i,j;

  while(scanf("%lld",&x),x){

    for(i=0;i<4001;i++){
      emp[i]=0;
      val[i]=0;
    }
    for(i=0;i<x;i++){

      scanf("%lld %lld %lld",&emp1,&val1,&con);

      flag=0;
      for(j=0;j<x;j++){
	if(emp[j]==emp1){
	  flag=1;
	  val[j]+=val1*con;
	  break;
	}
      }

      if(flag==0){
	for(j=0;j<4001;j++){
	  if(emp[j]==0){
	    emp[j]=emp1;
	    val[j]=val1*con;
	    break;
	  }  
	}
      }
    }
      flag=0;
    for(j=0;j<4001;j++){
      if(val[j]>=1000000){
	printf("%lld\n",emp[j]);
	flag=1;
      }
    }
    if(flag==0)printf("NA\n");
  }
  return 0;
}
