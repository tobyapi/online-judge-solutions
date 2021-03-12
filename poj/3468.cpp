#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

typedef long long ll;

class SegmentTree {
  static const int MAX_N = (1<<18);

  ll n,value[MAX_N],delta[MAX_N],size;

  void push(int k,int l,int r){
    value[k] += delta[k]*(r-l);
    if(k+1 < size){
      delta[k*2+1] += delta[k];
      delta[k*2+2] += delta[k];
    }
    delta[k]=0;
  }

  void add(int a,int b,int v,int k, int l, int r){
    push(k,l,r);
    if(r <= a || b <= l)return;
    if(a <= l && r <= b)delta[k]+=v,push(k,l,r);
    else {
      add(a, b, v, k*2+1, l, (l+r)/2);
      add(a, b, v, k*2+2, (l+r)/2, r);
      value[k] = value[k*2+1]+value[k*2+2];
    }
  }
  
  ll sum(int a,int b,int k,int l, int r){
    push(k,l,r);
    if(r <= a || b <= l)return 0;
    if(a <= l && r <= b)return value[k];
    return sum(a,b,k*2+1,l,(l+r)/2) + sum(a,b,k*2+2,(l+r)/2,r);
  }
  
public :

  SegmentTree(int n):n(n){
    fill(value,value+MAX_N,0);
    fill(delta,delta+MAX_N,0);
    int n_=1;
    while(n_<n)n_*=2;
    size = n_;
  }

  //add v to [a,b)
  void add(int a,int b,int v){ add(a,b,v,0,0,n); }

  //sum [a,b)
  ll sum(int a,int b){ return sum(a,b,0,0,n); }
};

int main(void){
  ll n,q,a,b,c;
  cin >> n >> q;

  SegmentTree range = SegmentTree(n);

  for(int i=0;i<n;i++){
    scanf("%lld",&a);
    range.add(i,i+1,a);
  }
  
  while(q--){
    char com;
    scanf(" %c",&com);
    if(com=='Q'){
      scanf("%lld %lld",&a, &b);
      printf("%lld\n",range.sum(a-1,b));
    } else {
      scanf("%lld %lld %lld",&a,&b,&c);
      range.add(a-1,b,c);
    }
  }
  
  return 0;
}