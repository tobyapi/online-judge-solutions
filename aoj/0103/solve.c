#include<stdio.h>
#include<string.h>

int main(void){
  int i,a,out,base,point;
  char event[8];

  scanf("%d",&a);

  for(i=0;i<a;i++){
    point=0;
    base=0;
    out=0;
    while(1){

      scanf("%s",event);
      
      if(!strcmp(event,"OUT")){
	out++;
	if(out==3)break;
      }

      if(!strcmp(event,"HIT")){
	if(base<3)base++;
	else {
	  point++;
	}
      }
      
      if(!strcmp(event,"HOMERUN")){
	point+=base+1;
	base=0;
      }

    }
    printf("%d\n",point);
  }
  return 0;
}
