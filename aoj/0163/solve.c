#include<stdio.h>
#define begin 17*60+30
#define end 19*60+30
int main(void){
  int x[8][8];

  x[1][2]=300;
  x[1][3]=500;
  x[1][4]=600;
  x[1][5]=700;
  x[1][6]=1350;
  x[1][7]=1650;
  x[2][1]=6;
  x[2][3]=350;
  x[2][4]=450;
  x[2][5]=600;
  x[2][6]=1150;  
  x[2][7]=1500;
  x[3][1]=13;
  x[3][2]=7;
  x[3][4]=250;
  x[3][5]=400;
  x[3][6]=1000;
  x[3][7]=1350;
  x[4][1]=18;
  x[4][2]=12;
  x[4][3]=5;
  x[4][5]=250;
  x[4][6]=850;
  x[4][7]=1300;
  x[5][1]=23;
  x[5][2]=17;
  x[5][3]=10;
  x[5][4]=5;
  x[5][6]=600;
  x[5][7]=1150;
  x[6][1]=43;
  x[6][2]=37;
  x[6][3]=30;
  x[6][4]=25;
  x[6][5]=20;
  x[6][7]=500;
  x[7][1]=58;
  x[7][2]=52;
  x[7][3]=45;
  x[7][4]=40;
  x[7][5]=35;
  x[7][6]=15;
  
  int v,y,a,b,h,m,val;

  while(1){
    scanf("%d",&v);
    if(v==0)break;
    scanf("%d %d %d %d %d",&a,&b,&y,&h,&m);

    if(((begin<=a*60+b && a*60+b<=end )||(begin<=h*60+m && h*60+m<=end))&&x[y][v]<=40){
      val=x[v][y]/2;
      if(val%100!=0){
	if(val%100<50){
	val=val/100;
	val=val*100+50;
	}
	else if(val%100>50){
	  val=val/100;
	  val=val*100+100;
	}
      }
      printf("%d\n",val);
	}
      else printf("%d\n",x[v][y]);
}

  return 0;
}
