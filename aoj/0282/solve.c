#include<stdio.h>
#include<limits.h>

#define MAX_N 100001

struct pair{int first,second;};

int n;
struct pair dat[2*MAX_N-1];

int add(int k,int a){
  k+=n-1;
  dat[k].first+=a;
  while(k>0){
    k=(k-1)/2;
    if(dat[k*2+1].first>dat[k*2+2].first)dat[k]=dat[k*2+1];
    else if(dat[k*2+1].first==dat[k*2+2].first){
      if(dat[k*2+1].second<dat[k*2+2].second)dat[k]=dat[k*2+1];
      else dat[k]=dat[k*2+2];
    }
    else dat[k]=dat[k*2+2];
  }
}

void init(){
  int i;
  for(i=0;i<n;i++){
    struct pair p;
    p.first=0;
    p.second=i;
    dat[i+n-1]=p;
  }
  for(i=0;i<n;i++)add(i,0);
}

int cnt[100001];

int main(void){

  int r,l,now=0,pre=0,i;

  scanf("%d %d %d",&n,&r,&l);
  init();

  while(r--){

    int d,t,x;
    scanf("%d %d %d",&d,&t,&x);
    cnt[now]+=t-pre;
    pre=t;
    add(d-1,x);
    now=dat[0].second;
  }
  cnt[now]+=l-pre;

  int ans=0,p=0;
  for(i=0;i<n;i++)if(p<cnt[i])p=cnt[i],ans=i;
  printf("%d\n",ans+1);

  return 0;
}
