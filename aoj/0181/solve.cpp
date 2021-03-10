#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int m,n;
vector<int>v;

bool C(int x){

  int cnt=0,sum=0,i=0;
  while(i<n && cnt<m){
    if(sum+v[i]<=x)sum+=v[i],i++;
    else sum=0,cnt++;
  }
  return m>cnt;
}

int main(void){

  while(cin >> m >> n,m|n){
    v.clear();

    int l=0,r=100000000,a;
    for(int i=0;i<n;i++){
      cin >> a;
      v.push_back(a);
    }
    
    while(r-l>1){
      int mid=(l+r)/2;
      if(C(mid))r=mid;
      else l=mid;
    }
    cout << r << endl;
  }

  return 0;
}
