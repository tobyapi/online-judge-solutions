#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){

  bool prim[10001];
  fill(prim,prim+10001,true);

  for(int i=2;i*i<10001;i++){
    if(prim[i]){
      for(int j=i*2;j<10001;j+=i){
        prim[j]=false;
      }
    }
  }

  vector<int>p;
  for(int i=2;i<10001;i++)
    if(prim[i])p.push_back(i);

  int n;
  while(cin >> n,n){
    int ans=0,sum=0;

    for(int i=0,j=0;j<p.size();){
      while(sum>n)sum-=p[i++];
      while(sum<n)sum+=p[j++];
      if(sum==n)ans++,sum+=p[j++];
    }
    cout << ans << endl;
  }

  return 0;
}
