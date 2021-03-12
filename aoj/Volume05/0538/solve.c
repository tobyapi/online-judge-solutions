#include <stdio.h>

int main(void){
  int i,n,m,count[1000001],res;
  char s[1000001];
  
  while(scanf("%d",&n),n){
    scanf("%d %s",&m,s);
    
    for(i=0;i<1000001;count[i]=0,i++);
    
    for(i=0,res=0;i<=m;i++)
      if(s[i]=='I' && s[i-1]=='O' && s[i-2]=='I')
        count[i]=count[i-2]+1;
    
    for(i=0,res=0;i<m;i++)if(count[i]>=n)res++;
    
    printf("%d\n",res);
  }
  return 0;
}
