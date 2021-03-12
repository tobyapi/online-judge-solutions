#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
  int n;
  vector<int>num;

  while(cin >> n,~n){
    if(n==0){
      cout << 0 << endl;
      continue;
    }
    for(int i=0;n>0;i++){
      num.push_back(n%4);
      n/=4;
    }
    for(int i=num.size()-1;i>=0;i--)
      cout << num[i];
    cout << endl;
    num.clear();
  }

  return 0;
}
