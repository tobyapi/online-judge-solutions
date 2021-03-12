#include<cstdio>
#include<algorithm>
#include<climits>

#define max_n (1<<18)

using namespace std;

int dat[max_n],n;

void update(int k,int a){
  for(k+=n,dat[k]=a;k>1;k>>=1)
    dat[k>>1]=min(dat[k],dat[k^1]);
}

int rmq(int a,int b){
  int res=INT_MAX;
  for(a+=n,b+=n;a<=b;a=(a+1)>>1,b=(b-1)>>1){
    if(a&1)res=min(res,dat[a]);
    if(!(b&1))res=min(res,dat[b]);
  }
    return res;
}

int main(void){
 
  fill(dat,dat+max_n,INT_MAX);
  int q;
  scanf("%d %d",&n,&q);
 
  while(q--){
    int com,x,y;
    scanf("%d %d %d",&com,&x,&y);
    if(com)printf("%d\n",rmq(x,y));
    else update(x,y);
  }
  return 0;
}
