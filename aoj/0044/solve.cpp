#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>

using namespace std;

int main(void){
  int prime[60000],i,j,x;

  for(i=0;i<60000;i++)
    prime[i]=0;
  prime[0]=1;
  prime[1]=1;

  
  for(i=2;i*i<60000;i++){
    if(prime[i]==0){
      for(j=i*2;j<60000;j+=i){
	prime[j]=1;
      }
    }
  }

  while(scanf("%d",&x)!=EOF){
    for(i=x-1;i>=2;i--){
      if(prime[i]==0){
	cout << i <<" ";
	break;
      }
    }
    
    for(i=x+1;i<60000;i++){
      if(prime[i]==0){
	cout << i << endl;
	break;
      } 
    }
  }
  return 0;
}
