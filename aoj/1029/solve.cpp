#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){
  int n,m;
  
  while(cin >> n >> m,n|m){
    vector<int>v(n+m);
    for(int i=0;i<n+m;i++)cin >> v[i];
    sort(v.begin(),v.end());
    int ans=v[0];
    for(int i=0;i<v.size()-1;i++)ans=max(ans,v[i+1]-v[i]);
    cout << ans << endl;
  }
  return 0;
}
