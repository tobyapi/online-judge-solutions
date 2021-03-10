#include<iostream>

using namespace std;

int main(void){
  int x,prime[1000000];
long long int i,j;

  for(i=0;i<1000000;i++)
    prime[i]=0;
  
  prime[0]=1;
  prime[1]=1;
  for(i=2;i*i<100000;i++){
    if(prime[i]==0){
      for(j=i*2;j<100000;j+=i){
	prime[j]=1;
      }
    }
  }

  while(scanf("%d",&x)!=EOF){
    int count=0;

      for(i=1;i<=x;i++){
      if(prime[i]==0 && prime[x+1-i]==0){
	count++;
      }
    }
      cout << count << endl;
  }
  
  return 0;
}
