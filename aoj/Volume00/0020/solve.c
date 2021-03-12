#include<stdio.h>
#include<ctype.h>

#define Num 1000

int main(void)
{
  char str[Num];
  int i=0;
  
  while(scanf("%c",&str[i])!=EOF)
    {
      if(islower(str[i])!=0)str[i]=toupper(str[i]);
   
      printf("%c",str[i]);
      i++;
    }
  //printf("\n");


  return 0;
}
