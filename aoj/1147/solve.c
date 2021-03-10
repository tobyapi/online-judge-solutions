#include<stdio.h>

int min(int,int);
int max(int,int);

int main(void){
  int n,s,i,mini,maxi,sum;

  while(scanf("%d",&n),n){

    mini=100000;
    maxi=sum=0;

    for(i=0;i<n;i++){
    scanf("%d",&s);
    mini = min(mini,s);
    maxi = max(maxi,s);
    sum+=s;
    }
    printf("%d\n",(sum-mini-maxi)/(n-2));
}
  return 0;
}

int min(int x,int y){
  return x<y?x:y;
}

int max(int x,int y){
  return x>y?x:y;
}
