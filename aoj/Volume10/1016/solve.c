#include<stdio.h>
#include<string.h>
#include<math.h>
#define MOD 1001
#define MAX 10001
int fibo[MAX];
int p[MAX];
int getfibo(int n)
{
  if(n<1)return 1;
  if(fibo[n])return fibo[n];
  return fibo[n]=(getfibo(n-1)+getfibo(n-2))%MOD;
}
int root(int a){
  return p[a]<0?a:(p[a]=root(p[a]));
}
int find(int a,int b)
{
  return root(a)==root(b);
}
void merge(int a,int b)
{
  p[root(a)]=root(b);
}
int main(void)
{
  fibo[0]=1;fibo[1]=2;
  int a,d,i,j;
  while(scanf("%d%d",&a,&d)==2){
    memset(p,-1,sizeof(p));
    for(i=1;i<=a;i++){
      for(j=1;j<=a;j++){
        if(abs(getfibo(i)-getfibo(j))<d){
          if(!find(i,j))merge(i,j);
        }
      }
    }
    int b[MAX]={0},res,c=0;
    for(i=1;i<=a;i++){
      res=root(i);
      if(!b[res]){
        b[res]=1;c++;
      }
    }
    printf("%d\n",c);
  }
  return 0;
}
