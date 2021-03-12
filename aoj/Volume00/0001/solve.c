#include<stdio.h>
int main(void){
  int f,j,a[10],i;
  f=0;
  j=0;
  a[9]=0;
  i=0;

  for(f=0;f<10;f++){
    scanf("%d",&a[f]);
}

  for(f=0;f<9;f++)
    {
      for(j=f+1;j<10;j++)
	{
	  if(a[f]<a[j])
	    {
	      i=a[f];
	      a[f]=a[j];
	      a[j]=i;
	    }
	}
    }
  printf("%d\n%d\n%d\n",a[0],a[1],a[2]);

  return 0;
}
