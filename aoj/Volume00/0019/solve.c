#include<stdio.h>
typedef long long ll;
ll func(ll);
ll memo[21];

int main(void){
  ll x;
  scanf("%lld",&x);
  printf("%lld\n",func(x));
  return 0;
}

ll func(ll n){

  if(n==0)return 1;
  if(memo[n]!=0)return memo[n];
  return n * func(n-1);
}
