#include<stdio.h>
#include<stdlib.h>
int sum(int);
void add(int,int);
int comp( const void *c1, const void *c2 );
int a[101],b[101],bit[101],n;

int main(void){
  int j,ans;

  while(scanf("%d",&n),n){
    for(j=0;j<101;j++)
      bit[j]=0;
    for(j=0;j<n;j++){
      scanf("%d",&a[j]);
      b[j]=a[j];
    }
    qsort(b,n,sizeof(int),comp);
    for(j=0;j<n;j++)
      a[j]=(int *)bsearch(&a[j],b,n,sizeof(int),comp)-b;
    
    ans=0;
    for(j=0;j<n;j++){
      ans += j - sum(a[j]);
      add(a[j],1);
}
    printf("%d\n",ans);
    }
  return 0;
}

int sum(int i){
  int s=0;i+=1;
  while(i>0){
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

void add(int i,int x){
  i+=1;
  while(i <= n){
    bit[i]+=x;
    i += i & -i;
  }
}

int comp( const void *c1, const void *c2 ){
  int tmp1 = *(int *)c1;
  int tmp2 = *(int *)c2;

  if( tmp1 < tmp2 )  return -1;
  if( tmp1 == tmp2 ) return  0;
  if( tmp1 > tmp2 )  return  1;
}
