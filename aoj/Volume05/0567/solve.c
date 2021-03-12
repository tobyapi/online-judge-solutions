#include<stdio.h>

int main(void){
  int n,a,b,c,d[101],i,j,t;

  scanf("%d %d %d %d",&n,&a,&b,&c);

  for(i=0;i<n;i++)scanf("%d",&d[i]);

  for(i=n-1;i>0;i--)
    for(j=0;j<i;j++)
      if(d[j]<d[j+1])
	t=d[j],d[j]=d[j+1],d[j+1]=t;
      
  for(i=0;i<n;i++)
    if((c+d[i])/(a+b)>=c/a)c+=d[i],a+=b;
    else break;
  
  printf("%d\n",c/a);

  return 0;
}
