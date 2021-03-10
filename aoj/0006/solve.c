#include<stdio.h>
int main(void)
{
  int i=0,j;
  char str,ch[20];

  while(scanf("%c",&str)!=EOF)
    {
      ch[i]=str;
      i++;
    }

  for(j=i-2;j>=0;j--)
    {
      printf("%c",ch[j]);
    }
  printf("\n");
  return 0;
}
