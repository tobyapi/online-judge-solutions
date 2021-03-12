#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int main(void){


  int n;
  while(cin >> n,n){

    int mx=0,mn=INT_MAX;

    for(int i=0;i<n;i++){
      int sum=0;
      for(int j=0;j<5;j++){
        int a;
        cin >> a;
        sum+=a;
      }
      mx=max(mx,sum);
      mn=min(mn,sum);
    }
    cout << mx << " " << mn << endl;
  }

  return 0;
}
