#include<stdio.h>

int main(void){
  int n,i,j,ans;
  char s[10000001];

  s[0]='1';
  s[1]='1';
  for(i=2;i<=10000001;i++)
    s[i]='0';

  for(i=2;i*i<=10000001;i++){
    if(s[i]=='0'){
      for(j=2*i;j<=10000001;j+=i)
	s[j]='1';
      }
}

  while(scanf("%d",&n),n){
    for(i=n;;i--){
      if(s[i]=='0' && s[i-2]=='0' && s[i-6]=='0' && s[i-8]=='0'){
	printf("%d\n",i);
	break;
      }
    }
  }
  return 0;
}
