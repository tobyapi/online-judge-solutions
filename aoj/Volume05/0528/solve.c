#include<stdio.h>
#include<string.h>

int main(void){
char str1[4001],str2[4001];
 int i,j,count,len1,len2;
static short dp[4002][4002];

  while(~scanf("%[^\n]%*c",str1)){
    scanf("%[^\n]%*c",str2);

    memset(dp,0,sizeof(dp));

    count=0;
    len1=strlen(str1);
    len2=strlen(str2);
    for(i=0;i<len1;i++){
      for(j=0;j<len2;j++){
	if(str1[i]==str2[j]){
	  dp[i+1][j+1]=dp[i][j]+1;
	  count=count>dp[i+1][j+1]?count:dp[i+1][j+1];
	}
	else dp[i+1][j+1]=0;
	
      }
    }
    printf("%d\n",count);
  }

  return 0;
}
