#include<stdio.h>
int main(void){
  
  int a[3]= {1,0,0},t=0;
  char x,y,z,e;
  
  while(scanf("%c%c%c%c",&x,&y,&z,&e)!=EOF)
    {
      //printf("%c%c%c\n",x,y,z);
      // printf("aaaaaaaaaa\n");

      if(x=='A' && z=='B' || x=='B' && z=='A')
	{
	  t=a[0];
	  a[0]=a[1];
	  a[1]=t;
	}
      else if(x=='A' && z=='C' || x=='C' && z=='A')
	{
	  t=a[0];
	  a[0]=a[2];
	  a[2]=t;
	}
      else if(x=='B' && z=='C' || x=='C' && z=='B')
	{
	  t=a[1];
	  a[1]=a[2];
	  a[2]=t;
	}
      // if(a[0]==1)printf("A\n");
      // else if(a[1]==1)printf("B\n");
      //else if(a[2]==1)printf("C\n");
    }
  if(a[0]==1)printf("A\n");
  else if(a[1]==1)printf("B\n");
  else if(a[2]==1)printf("C\n");
  
  return 0;
}
