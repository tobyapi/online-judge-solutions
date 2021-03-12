#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){

  int prime[300000],a[300000];

  fill(prime,prime+300000,1);
  fill(a,a+300000,0);

  for(int i=0;i<300000;i++)if(i%7==1||i%7==6)a[i]=1;

  prime[0]=prime[1]=0;

  for(int i=2;i*i<300000;i++)
    if(a[i]==1)
      for(int j=i*2;j<300000;j+=i)
	prime[j]=0;

  int x;
  vector<int>ans;
  while(cin >> x,x!=1){
    ans.clear();
    for(int i=0;i<=x;i++)
      if(prime[i] && a[i] && x%i==0)ans.push_back(i);
    
    cout << x <<": ";

    for(int i=0;i<ans.size();i++){
      cout << ans[i];
      if(i==ans.size()-1)cout << endl;
      else cout << " ";
    }
  }

  return 0;
}
