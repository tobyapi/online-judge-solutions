#include<iostream>

using namespace std;

int main(void){
  int n,prime[1000000],ans[1000000];


  for(int i=0;i<1000000;i++)prime[i]=ans[i]=0;
  prime[0]=prime[1]=1;

  for(int i=2;i*i<1000000;i++)
    if(prime[i]==0)
      for(int j=2*i;j<1000000;j+=i)
	prime[j]=1;
  
  int cnt=0;
  for(int i=0;i<1000000;i++){
    if(prime[i]==0)cnt++;
    ans[i]=cnt;
  }

  while(cin >> n)
    cout << ans[n] << endl;
  
  return 0;
}
