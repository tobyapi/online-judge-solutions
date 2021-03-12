#include<iostream>
#include<algorithm>

using namespace std;

int p,q,a,n;

int func(int turn,int last,int product,int c,int d){
  if(p*d==c*q)return 1;
  if(!turn)return 0;
  
  int count=0;
  for(int i=last;product*i<=a;i++){
    if(c/d+1/i<=p/q)
      count+=func(turn-1,i,product*i,i*c+d,i*d);
  }  
  return count;
}

int main(void){
  
  while(cin >> p >> q >> a >> n,p|q|a|n){
    cout << func(n,1,1,0,1) << endl;
  }
  
  return 0;
}
